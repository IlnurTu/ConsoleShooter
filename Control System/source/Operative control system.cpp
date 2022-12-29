#include "../headers/Operative control system.h"

OperativeControlSystem::OperativeControlSystem(Level &lvl, std::shared_ptr<Operative> &current_operative) :
        lvl(lvl), current_operative(current_operative){};

///function, which associate map and units on it,
///check all cells in current direction, change state this cells and units
///@param direction direction
void OperativeControlSystem::shoot(direction drctn) {
    auto damage = current_operative->shoot();
    if (damage == 0)
        return;
    Point current_point = current_operative->get_position();
    auto firing_range = current_operative->get_current_weapon()->get_parameters().firing_range;

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
        auto unit = cell->get_unit();
        if (unit && !std::dynamic_pointer_cast<Operative>(unit)) {
            unit->get_damage(damage);
            if (unit->get_general_parameters().current_health == 0) {
                auto unitForager = std::dynamic_pointer_cast<Forager>(unit);
                if (unitForager) {
                    auto CountItems = unitForager->get_count_items();
                    for (int i = 0; i < CountItems; ++i) {
                        cell->pushItem(unitForager->pop_inventory(i + 1));
                    }
                }
                --lvl.countEnemy;
                cell->set_unit(nullptr);
            }
        }
    }
}

///function which associate map and state of units, change pointer on unit in cell and position in unit
///@param direction direction
void OperativeControlSystem::take_step(direction drctn) {
    if (current_operative->get_general_parameters().current_points_time <
        current_operative->get_general_parameters().points_time_for_step)
        return;
    Point current_point = current_operative->get_position();


    current_point.setPos(drctn);
    if (!(current_point.x < lvl.map->getSizeX() && current_point.x >= 0 && current_point.y < lvl.map->getSizeY() &&
          current_point.y >= 0))
        return;
    auto cell = lvl.map->get_cell(current_point.x, current_point.y);
    if (cell->get_shoot_state() == false && cell->get_unit() == nullptr) {
        lvl.map->get_cell(current_operative->get_position().x, current_operative->get_position().y)->set_unit(
                nullptr);
        current_operative->take_step(drctn);
        cell->set_unit(current_operative);
    }

}

void OperativeControlSystem::set_operative(std::shared_ptr<Operative>& operative) {
    current_operative = operative;
}

///function which associate unit with map, extract item from cell and push it into unit
///@param size_t id of item in cell
void OperativeControlSystem::take_item(size_t id) {
    auto cell = lvl.map->get_cell(current_operative->get_position().x,
                                  current_operative->get_position().y);
    auto &item = cell->get_item(id);
    if (!item)
        return;
    if (item->get_weight() <= (current_operative->get_max_weight() - current_operative->get_current_weight())) {
        current_operative->push_inventory(std::move(cell->extractItem(id)));
    }
}

///function which associate unit with map, extract item from unit and push it into cell
///@param size_t id of item in unit
void OperativeControlSystem::throw_item(size_t id) {
    auto cell = lvl.map->get_cell(current_operative->get_position().x,
                                  current_operative->get_position().y);
    auto item = current_operative->pop_inventory(id);
    if (!item)
        return;
    cell->pushItem(std::move(item));
}



