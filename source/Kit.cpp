#include "../headers/Kit.h"

Kit::Kit(std::string name, unsigned short weight, unsigned short points_time_for_use, unsigned short restored_health) :
        Item(std::move(name), weight) {
    if (points_time_for_use <= 0 || restored_health <= 0) {
        std::runtime_error("Parameters must be greater than 0");
    }
    parameters.points_time_for_use = points_time_for_use;
    parameters.restored_health = restored_health;
}

kit_parameters Kit::get_parameters() const {
    return parameters;
}

std::string Kit::get_info() const {
    std::string result;
    result = get_name() + " "
             + std::to_string(get_weight()) + " "
             + std::to_string(get_parameters().points_time_for_use) + " "
             + std::to_string(get_parameters().restored_health) + "\n";
    return result;
}
