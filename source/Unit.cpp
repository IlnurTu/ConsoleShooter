#include "../headers/Unit.h"

Unit::Unit(std::string name, unsigned short max_health, unsigned short current_health,
           unsigned short points_time_for_step,
           unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
           size_t coordinate_x, size_t coordinate_y) {

    if (max_health <= 0 || points_time_for_step <= 0 || viewing_radius <= 0 || max_points_time <= 0 ||
        coordinate_x < 0 || coordinate_y < 0) {
        throw std::runtime_error("Parameters must be greater than 0");
    }

    if (current_points_time > max_points_time || current_health > max_health) {
        throw std::runtime_error("Current parameters can`t be greater than max parameters");
    }

    main_parameters = {std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
                       current_points_time, max_points_time,};

    position = {coordinate_x, coordinate_y};
}

base_parameters Unit::get_general_parameters() const {
    return main_parameters;
}

Point Unit::get_position() const {
    return position;
}

Unit &Unit::take_step(direction direction) {
    if (main_parameters.current_points_time < main_parameters.points_time_for_step) {
        return *this;
    }
    switch (direction) {
        case left:
            position.x -= 1;
            break;
        case right:
            position.x += 1;
            break;
        case straight:
            position.y += 1;
            break;
        case back:
            position.y -= 1;
            break;
        case left_back:
            position.x -= 1;
            position.y -= 1;
            break;
        case right_back:
            position.x += 1;
            position.y -= 1;
            break;
        case left_straight:
            position.x -= 1;
            position.y += 1;
            break;
        case right_straight:
            position.x += 1;
            position.y += 1;
            break;
    }
    main_parameters.current_points_time -= main_parameters.points_time_for_step;
    return *this;
}

Unit &Unit::get_damage(unsigned short damage) {
    if (damage > main_parameters.current_health) {
        main_parameters.current_health = 0;
    } else {
        main_parameters.current_health -= damage;
    }
    return *this;
}

void Unit::reload_current_time() {
    main_parameters.current_points_time = main_parameters.max_points_time;
}

