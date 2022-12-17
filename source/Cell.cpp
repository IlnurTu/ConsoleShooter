#include "../headers/Cell.h"


Cell::Cell(std::string name, unsigned short x, unsigned short y, bool is_transparent, bool is_bullet_stop,
           Inventory inventory,std::shared_ptr<Unit> unit) : name(std::move(name)), is_transparent(is_transparent), is_bullet_stop(is_bullet_stop),
                                  inventory(std::move(inventory)),unit(std::move(unit)) {
            if(x<0 || y<0){
                throw std::runtime_error("Coordinate must be greater than 0");
            }
            coordinate = {x,y};
}

Point Cell::get_coordinate() const {
    return coordinate;
}

bool Cell::get_shoot_state() const {
    return is_bullet_stop;
}

bool Cell::get_view_state() const {
    return is_transparent;
}

std::shared_ptr<Item> Cell::get_item(size_t id) const{
    return inventory.getItem(id);
}

std::shared_ptr<Item> Cell::extractItem(size_t id) {
    return inventory.eraseItem(id);
}

Cell& Cell::pushItem(std::shared_ptr<Item> newItem) {
    inventory.add(newItem);
    return *this;
}

size_t Cell::get_count_items() const {
    return inventory.getCount();
}

void Cell::set_unit(std::shared_ptr<Unit> unit) {
    this->unit = std::move(unit);
}

std::shared_ptr<Unit> Cell::get_unit() const {
    return unit;
}

std::string Cell::get_info() const {
    std::string result;
    result = name + " "
             + std::to_string(coordinate.x) + " "
             + std::to_string(coordinate.y) + " "
             + std::to_string(is_transparent) + " "
             + std::to_string(is_bullet_stop) + "\n";
    result += inventory.get_info();
    return result;
}