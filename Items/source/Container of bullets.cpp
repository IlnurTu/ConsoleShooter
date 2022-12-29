#include "../headers/Container of bullets.h"

ContainerBullets::ContainerBullets(std::string name, unsigned short weight, size_t max_bullets, size_t current_bullets,
                                   unsigned short type) :
        Item(std::move(name), weight), type(type) {

    if (max_bullets <= 0 || current_bullets <= 0)
        throw std::runtime_error("Parameters must be greater than 0");

    if (current_bullets > max_bullets)
        throw std::runtime_error("Current parameters can`t be greater than max parameters");

    parameters.current_number_bullets = current_bullets;

    parameters.max_number_bullets = max_bullets;
}

ContainerBullets_parameters ContainerBullets::get_parameters() const {
    return parameters;
}

unsigned short ContainerBullets::get_type() const {
    return type;
}

bool ContainerBullets::reload(size_t bullets) {
    if(parameters.current_number_bullets < bullets)
        return false;
    parameters.current_number_bullets -= bullets;
    if(parameters.current_number_bullets == 0)
        weight = 0;
    return true;
}

std::string ContainerBullets::get_info() const {
    std::string result;
    result = get_name() + " "
            + std::to_string(get_weight()) + " "
            + std::to_string(get_parameters().max_number_bullets) + " "
            + std::to_string(get_parameters().current_number_bullets) + " "
            + std::to_string(get_type()) + "\n";
    return result;
}