#include "../headers/Weapon.h"

Weapon::Weapon(std::string name, unsigned short weight, unsigned short damage, unsigned short type_bullets,
               unsigned short current_number_bullets, unsigned short max_number_bullets,
               unsigned short points_time_for_shoot, unsigned short points_time_for_reload, unsigned short firing_range)
        :
        Item(std::move(name), weight), type_bullets(type_bullets) {
    if (damage <= 0 || current_number_bullets < 0 || max_number_bullets <= 0 || points_time_for_shoot <= 0 ||
        points_time_for_reload <= 0 || firing_range <= 0) {
        throw std::runtime_error("Parameters must be greater than 0");
    }
    if (current_number_bullets > max_number_bullets) {
        throw std::runtime_error("Current parameters can`t be greater than maximum");
    }
    parameters.max_number_bullets = max_number_bullets;
    parameters.current_number_bullets = current_number_bullets;
    parameters.points_time_for_shoot = points_time_for_shoot;
    parameters.damage = damage;
    parameters.points_time_for_reload = points_time_for_reload;
    parameters.firing_range = firing_range;
}

weapon_parameters Weapon::get_parameters() const {
    return parameters;
}

Weapon &Weapon::reload(unsigned short bullets) {
    if (parameters.max_number_bullets - parameters.current_number_bullets < bullets)
        parameters.current_number_bullets = parameters.max_number_bullets;
    else
        parameters.current_number_bullets += bullets;
    return *this;
}

unsigned short Weapon::get_type_bullets() const {
    return type_bullets;
}

std::string Weapon::get_info() const {
    std::string result;
    result = get_name() + " "
             + std::to_string(get_weight()) + " "
             + std::to_string(get_parameters().damage) + " "
             + std::to_string(get_type_bullets()) + " "
             + std::to_string(get_parameters().current_number_bullets) + " "
             + std::to_string(get_parameters().max_number_bullets) + " "
             + std::to_string(get_parameters().points_time_for_shoot) + " "
             + std::to_string(get_parameters().points_time_for_reload)+ " "
             + std::to_string(get_parameters().firing_range)
             + "\n";
    return result;
}
