#ifndef LAB4_FORAGER_H
#define LAB4_FORAGER_H

#include "Unit.h"
#include "Inventory.h"

class Forager : virtual public Unit {
protected:
    unsigned short max_weight;
    unsigned short current_weight;
    Inventory inventory;
public:
    Forager(std::string name, unsigned short max_health, unsigned short points_time_for_step,
            unsigned short viewing_radius, unsigned short max_points_time, size_t coordinate_x, size_t coordinate_y,
            unsigned short max_weight,Inventory inventory = Inventory());

    unsigned short get_max_weight() const;

    unsigned short get_current_weight() const;

    std::string show_invetory() const;

    Forager& push_inventory(std::shared_ptr<Item>);

    Forager& pop_inventory(size_t id);

};

#endif //LAB4_FORAGER_H
