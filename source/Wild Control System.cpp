#include "../headers/Wild Control System.h"

WildControlSystem::WildControlSystem(Level &lvl, std::shared_ptr<Wild> &current_wild) :
        lvl(lvl), current_wild(current_wild) {};


void WildControlSystem::shoot(direction drctn) {
    auto damage = current_wild->shoot();
    if (damage == 0)
        return;
    Point current_point = current_wild->get_position();

    current_point.setPos(drctn);

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
            --lvl.countOperative;
            cell->set_unit(nullptr);
        }
    }
}

void WildControlSystem::take_step(direction drctn) {
    if (current_wild->get_general_parameters().current_points_time <
        current_wild->get_general_parameters().points_time_for_step)
        return;
    Point current_point = current_wild->get_position();

    current_point.setPos(drctn);
    if (!(current_point.x < lvl.map->getSizeX() && current_point.x >= 0 && current_point.y < lvl.map->getSizeY() &&
          current_point.y >= 0))
        return;
    auto cell = lvl.map->get_cell(current_point.x, current_point.y);
    if (cell->get_shoot_state() == false && cell->get_unit() == nullptr) {
        lvl.map->get_cell(current_wild->get_position().x, current_wild->get_position().y)->set_unit(
                nullptr);
        current_wild->take_step(drctn);
        cell->set_unit(current_wild);
    }

}

void WildControlSystem::set_wild(std::shared_ptr<Wild>& wild) {
    current_wild = wild;
}

void WildControlSystem::shoot() {
    size_t radius = 1;
    Point pos = current_wild->get_position();
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
        pos = current_wild->get_position();
    }
    if (!isFindedOperative)
        return;
    while (current_wild->get_points_time_for_shoot() <= current_wild->get_general_parameters().current_points_time)
        shoot(drct);
}