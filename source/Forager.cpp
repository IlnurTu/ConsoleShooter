#include "../headers/Forager.h"

Forager::Forager(std::string name, unsigned short max_health, unsigned short current_health,
                 unsigned short points_time_for_step, unsigned short viewing_radius, unsigned short max_points_time,
                 unsigned short current_points_time, size_t coordinate_x, size_t coordinate_y,
                 unsigned short max_weight, unsigned short current_weight, Inventory inventory) :
        Unit(std::move(name), max_health, current_health, points_time_for_step, viewing_radius, max_points_time,
             current_points_time, coordinate_x, coordinate_y), inventory(std::move(inventory)) {
    if (max_weight < 0 || current_weight < 0) {
        throw std::runtime_error("Parameters must be greater than 0");
    }

    if (current_weight > max_weight) {
        throw std::runtime_error("Current parameters can`t be greater than max parameters");
    }

    this->current_weight = current_weight;
    this->max_weight = max_weight;
}

unsigned short Forager::get_current_weight() const {
    return current_weight;
}

unsigned short Forager::get_max_weight() const {
    return max_weight;
}


Forager &Forager::push_inventory(std::shared_ptr<Item> newItem) {
    if (max_weight - current_weight < newItem->get_weight()) {
        return *this;
    }
    unsigned short WeightOfItem = newItem->get_weight();
    inventory.add(std::move(newItem));
    current_weight += WeightOfItem;
    return *this;
}

std::shared_ptr<Item> Forager::pop_inventory(size_t id) {
    auto tmp = inventory.eraseItem(id);
    if (tmp != nullptr)
        current_weight -= tmp->get_weight();
    return tmp;
}

std::shared_ptr<Item> Forager::get_item(size_t id) const {
    return inventory.getItem(id);
}

size_t Forager::get_count_items() const {
    return inventory.getCount();
}

std::string Forager::get_info() const {
    std::string result;
    result = get_general_parameters().name + " "
             + std::to_string(get_general_parameters().max_health) + " "
             + std::to_string(get_general_parameters().current_health) + " "
             + std::to_string(get_general_parameters().points_time_for_step) + " "
             + std::to_string(get_general_parameters().viewing_radius) + " "
             + std::to_string(get_general_parameters().max_points_time) + " "
             + std::to_string(get_general_parameters().current_points_time) + " "
             + std::to_string(get_position().x) + " "
             + std::to_string(get_position().y) + " "
             + std::to_string(get_max_weight()) + " "
             + std::to_string(get_current_weight()) + "\n";
    result += inventory.get_info();
    return result;
}