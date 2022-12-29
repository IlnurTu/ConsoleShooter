#include "../headers/Intelligent.h"

Intelligent::Intelligent(std::string name, unsigned short max_health, unsigned short current_health,
                         unsigned short points_time_for_step, unsigned short viewing_radius,
                         unsigned short max_points_time, unsigned short current_points_time, size_t coordinate_x,
                         size_t coordinate_y, unsigned short damage,
                         unsigned short points_time_for_shoot, std::unique_ptr<Weapon> current_weapon) :

        Wild(std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
             max_points_time, current_points_time, coordinate_x, coordinate_y, damage, points_time_for_shoot),

        Unit(std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
             max_points_time, current_points_time, coordinate_x, coordinate_y),

        current_weapon(std::move(current_weapon)) {};

const std::unique_ptr<Weapon>& Intelligent::get_current_weapon() const {
    return current_weapon;
}

std::unique_ptr<Weapon> Intelligent::set_current_weapon(std::unique_ptr<Weapon> newWeapon) {
    std::swap(newWeapon, current_weapon);
    return newWeapon;
}

unsigned short Intelligent::shoot() {

    if (current_weapon == nullptr) {
        return Wild::shoot();
    }

    if (main_parameters.current_points_time < current_weapon->get_parameters().points_time_for_shoot) {
        return 0;
    }
    unsigned int damage = current_weapon->shoot();
    if(damage != 0)
        main_parameters.current_points_time -= current_weapon->get_parameters().points_time_for_shoot;
    return damage;
}

std::string Intelligent::get_info() const {
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
             + std::to_string(get_damage()) + " "
             + std::to_string(get_points_time_for_shoot()) + "\n";
    if (!current_weapon)
        result += "nullptr\n";
    else
        result += current_weapon->get_info();
    return result;
}

char Intelligent::get_character() const {
    return 'I';
}