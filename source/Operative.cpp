#include "../headers/Operative.h"

Operative::Operative(std::string name, unsigned short max_health, unsigned short current_health,
                     unsigned short points_time_for_step,
                     unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
                     size_t coordinate_x, size_t coordinate_y, unsigned short damage,
                     unsigned short points_time_for_shoot, std::unique_ptr<Weapon> current_weapon,
                     unsigned short max_weight, unsigned short current_weight, Inventory inventory) :

        Unit(std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
             max_points_time, current_points_time, coordinate_x, coordinate_y),

        Intelligent(std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
                    max_points_time, current_points_time, coordinate_x, coordinate_y, damage,
                    points_time_for_shoot, std::move(current_weapon)),

        Forager(std::move(name), max_health, current_health, points_time_for_step, viewing_radius,
                max_points_time, current_points_time, coordinate_x, coordinate_y, max_weight, current_weight,
                std::move(inventory)) {};

Operative &Operative::set_current_weapon(size_t id) {

    if (dynamic_cast<Weapon*>(inventory.getItem(id).get()) == nullptr) {
        return *this;
    }

    inventory.add(std::move(current_weapon));
    current_weapon.reset(dynamic_cast<Weapon*>(inventory.eraseItem(id).release()));
    return *this;
}
///function which check that there is kit in inventory and use it
///@param size_t id in inventory
///@return Operative&
Operative &Operative::use_kit(size_t id) {

    auto tmp = dynamic_cast<Kit*>(inventory.getItem(id).get());

    if (tmp == nullptr) {
        return *this;
    }

    if (main_parameters.current_points_time < tmp->get_parameters().points_time_for_use) {
        return *this;
    }

    main_parameters.current_points_time -= tmp->get_parameters().points_time_for_use;

    current_weight -= tmp->get_weight();

    if (main_parameters.max_health - main_parameters.current_health < tmp->get_parameters().restored_health) {
        main_parameters.current_health = main_parameters.max_health;
    } else {
        main_parameters.current_health += tmp->get_parameters().restored_health;
    }

   inventory.eraseItem(id);

    return *this;
}
///function that check is there container of bullets with type equal type of current weapon and use it
///@param
///@return operative
Operative &Operative::reload_weapon() {

    if (current_weapon == nullptr) {
        return *this;
    }

    if (current_weapon->get_parameters().current_number_bullets ==
        current_weapon->get_parameters().max_number_bullets) {
        return *this;
    }

    if (main_parameters.current_points_time < current_weapon->get_parameters().points_time_for_reload) {
        return *this;
    }

    auto iter = inventory.cbegin();
    for (; iter < inventory.cend(); ++iter) {
        auto tmp = dynamic_cast<ContainerBullets*>(iter->get());
        if (tmp && tmp->get_type() == current_weapon->get_type_bullets()) {
            unsigned short needed_number_bullets = current_weapon->get_parameters().max_number_bullets -
                                                   current_weapon->get_parameters().current_number_bullets;

            if (needed_number_bullets < tmp->get_parameters().current_number_bullets) {
                current_weapon->reload(needed_number_bullets);
                tmp->reload(needed_number_bullets);
                if (tmp->get_weight() == 0) {
                    inventory.eraseItem(iter - inventory.cbegin());
                }

            } else {
                current_weapon->reload(tmp->get_parameters().current_number_bullets);
                current_weight -= tmp->get_weight();
                inventory.eraseItem(iter - inventory.cbegin());
            }
            main_parameters.current_points_time -= current_weapon->get_parameters().points_time_for_reload;
        }
    }
    return *this;
}

std::string Operative::get_info() const {
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
             + std::to_string(get_points_time_for_shoot()) + " "
             + std::to_string(get_max_weight()) + " "
             + std::to_string(get_current_weight()) + "\n";
    if (!current_weapon)
        result += "nullptr\n";
    else
        result += current_weapon->get_info();
    result += inventory.get_info();
    return result;
}

char Operative::get_character() const {
    return 'O';
}