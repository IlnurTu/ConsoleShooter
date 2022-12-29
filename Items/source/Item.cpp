#include "../headers/Item.h"

Item::Item(std::string name, unsigned short weight) : name(std::move(name)){
    if(weight <= 0)
        throw std::runtime_error("The weight must be greater than 0");
    this->weight = weight;
}

std::string Item::get_name() const {
    return name;
}

unsigned short Item::get_weight() const {
    return weight;
}

