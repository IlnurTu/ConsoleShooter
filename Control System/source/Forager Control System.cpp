#include "../headers/Forager Control Sytem.h"

ForagerControlSystem::ForagerControlSystem(Level &lvl, std::shared_ptr<Forager> &current_forager) :
        lvl(lvl), current_forager(current_forager) {};

void ForagerControlSystem::take_step(direction drctn) {
    if (current_forager->get_general_parameters().current_points_time <
        current_forager->get_general_parameters().points_time_for_step)
        return;
    Point current_point = current_forager->get_position();

    current_point.setPos(drctn);
    if (!(current_point.x < lvl.map->getSizeX() && current_point.x >= 0 && current_point.y < lvl.map->getSizeY() &&
          current_point.y >= 0))
        return;
    auto cell = lvl.map->get_cell(current_point.x, current_point.y);
    if (cell->get_shoot_state() == false && cell->get_unit() == nullptr) {
        lvl.map->get_cell(current_forager->get_position().x, current_forager->get_position().y)->set_unit(
                nullptr);
        current_forager->take_step(drctn);
        cell->set_unit(current_forager);
    }
}

void ForagerControlSystem::set_forager(std::shared_ptr<Forager> &forager) {
    current_forager = forager;
}

void ForagerControlSystem::take_items() {
    auto cell = lvl.map->get_cell(current_forager->get_position().x,
                                  current_forager->get_position().y);
    if (lvl.StoragePoints.size() == 0 || *std::find(lvl.StoragePoints.begin(), lvl.StoragePoints.end(), current_forager->get_position()) ==
        cell->get_coordinate())
        return;
        for (int i = 0; i < cell->get_count_items(); ++i) {
            auto &item = cell->get_item(i + 1);
            if (dynamic_cast<Weapon *>(item.get())) {
                current_forager->push_inventory(std::move(cell->extractItem(i + 1)));
            }
        }
}

void ForagerControlSystem::throw_items() {
    auto cell = lvl.map->get_cell(current_forager->get_position().x,
                                  current_forager->get_position().y);
    if(lvl.StoragePoints.size() == 0)
        return;
    auto q = std::find(lvl.StoragePoints.begin(), lvl.StoragePoints.end(), current_forager->get_position());
    if (*q == cell->get_coordinate()) {
        for (int i = 0; i < current_forager->get_count_items(); ++i) {
            auto item = current_forager->pop_inventory(i + 1);
            cell->pushItem(std::move(item));
        }
    }
}