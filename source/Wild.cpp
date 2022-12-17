#include "../headers/Wild.h"

Wild::Wild(std::string name, unsigned short max_health, unsigned short current_health,
           unsigned short points_time_for_step, unsigned short viewing_radius, unsigned short max_points_time,
           unsigned short current_points_time, size_t coordinate_x, size_t coordinate_y,
           unsigned short damage, unsigned short points_time_for_shoot):
           Unit(std::move(name),max_health,current_health,points_time_for_step,viewing_radius, max_points_time,
                current_points_time, coordinate_x, coordinate_y){


    if(damage<0 || points_time_for_step<0){
        throw std::runtime_error("Parameters must be greater than 0");
    }

    this->damage = damage;
    this->points_time_for_shoot = points_time_for_shoot;
}


unsigned short Wild::get_points_time_for_shoot() const {
    return points_time_for_shoot;
}

unsigned short Wild::get_damage() const {
    return damage;
}

unsigned short Wild::shoot() {
    if(main_parameters.current_points_time<points_time_for_shoot){
        return 0;
    }
    main_parameters.current_points_time -= points_time_for_shoot;
    return damage;
}

std::string Wild::get_info() const {
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
    return result;
}