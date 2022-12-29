#include "../headers/Intelligent Control System.h"

IntelligentControlSystem::IntelligentControlSystem(Level &lvl, std::shared_ptr<Intelligent> &current_intelligent) :
        lvl(lvl), current_intelligent(current_intelligent) {};

void IntelligentControlSystem::take_step(direction drctn) {
    if (current_intelligent->get_general_parameters().current_points_time <
        current_intelligent->get_general_parameters().points_time_for_step)
        return;
    Point current_point = current_intelligent->get_position();


    current_point.setPos(drctn);
    if (!(current_point.x < lvl.map->getSizeX() && current_point.x >= 0 && current_point.y < lvl.map->getSizeY() &&
          current_point.y >= 0))
        return;
    auto cell = lvl.map->get_cell(current_point.x, current_point.y);
    if (cell->get_shoot_state() == false && cell->get_unit() == nullptr) {
        lvl.map->get_cell(current_intelligent->get_position().x, current_intelligent->get_position().y)->set_unit(
                nullptr);
        current_intelligent->take_step(drctn);
        cell->set_unit(current_intelligent);
    }
}

void IntelligentControlSystem::take_weapon(size_t id) {
    auto cell = lvl.map->get_cell(current_intelligent->get_position().x,
                                  current_intelligent->get_position().y);
    auto &item = cell->get_item(id);
    if (!item || dynamic_cast<Weapon *>(item.get()))
        return;
    //cell->pushItem(std::move(current_intelligent->set_current_weapon(std::move(cell->extractItem(id)))));
    auto weapon = cell->extractItem(id);
    Weapon *el = dynamic_cast<Weapon *>(weapon.release());
    std::unique_ptr<Weapon> e(el);
    cell->pushItem(std::move(current_intelligent->set_current_weapon(std::move(e))));
}

void IntelligentControlSystem::shoot(direction drctn) {
    auto damage = current_intelligent->shoot();
    if (damage == 0)
        return;
    Point current_point = current_intelligent->get_position();
    auto firing_range = current_intelligent->get_current_weapon()->get_parameters().firing_range;

    while (firing_range) {
        current_point.setPos(drctn);
        --firing_range;
        if (!(current_point.x < lvl.map->getSizeX() && current_point.x >= 0 && current_point.y < lvl.map->getSizeY() &&
              current_point.y >= 0))
            return;
        auto cell = lvl.map->get_cell(current_point.x, current_point.y);
        bool resultOfShootCell = cell->get_shoot_state();
        cell->shoot();
        if (resultOfShootCell) {
            return;
        }
        auto unit = std::dynamic_pointer_cast<Operative>(cell->get_unit());
        if (unit) {
            unit->Forager::get_damage(damage);
            if (unit->get_general_parameters().current_health == 0) {
                auto CountItems = unit->get_count_items();
                for (int i = 0; i < CountItems; ++i) {
                    cell->pushItem(unit->pop_inventory(i + 1));
                }
                cell->set_unit(nullptr);
                --lvl.countOperative;
            }
        }
    }
}

void IntelligentControlSystem::set_intelligent(std::shared_ptr<Intelligent> &intelligent) {
    current_intelligent = intelligent;
}

void IntelligentControlSystem::shoot() {

    size_t radius = current_intelligent->get_general_parameters().viewing_radius;
    Point pos = current_intelligent->get_position();
    bool isFindedOperative = false;
    direction drct;
    for (int j = 0; j < 8; ++j) {
        drct = static_cast<direction>(j);
        for (int i = 0; i < radius; ++i) {
            pos.setPos(drct);
            if (pos.x < 0 || pos.y < 0)
                break;
            auto unit = lvl.map->get_cell(pos.x, pos.y)->get_unit();
            if (std::dynamic_pointer_cast<Operative>(unit)) {
                isFindedOperative = true;
                break;
            }
        }
        if (isFindedOperative)
            break;
        pos = current_intelligent->get_position();
    }
    if (!isFindedOperative)
        return;
    while (current_intelligent->get_points_time_for_shoot() <=
           current_intelligent->get_general_parameters().current_points_time)
        shoot(drct);
}

void IntelligentControlSystem::changeWeapon() {
    if (current_intelligent->get_current_weapon()->get_parameters().current_number_bullets != 0)
        return;
    auto cell = lvl.map->get_cell(current_intelligent->get_position().x, current_intelligent->get_position().y);
    if (*std::find(lvl.StoragePoints.begin(), lvl.StoragePoints.end(), cell->get_coordinate()) !=
        cell->get_coordinate())
        return;
    for (int i = 0; i < cell->get_count_items(); ++i) {
        auto &item = cell->get_item(i + 1);
        if (auto weapon = dynamic_cast<Weapon *>(item.get())) {
            if (weapon->get_parameters().current_number_bullets != 0) {
                IntelligentControlSystem::take_weapon(i + 1);
                return;
            }
        }
    }
}