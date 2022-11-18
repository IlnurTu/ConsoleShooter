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
    Forager(std::string);

    Forager(std::string name, unsigned short max_health, unsigned short time_step,
            unsigned short viewing_radius, unsigned short max_points_time, unsigned short max_weight);

    unsigned short get_max_weight() const;

    unsigned short get_current_weight() const;

    void set_max_weight(unsigned short);

    void set_current_weight(unsigned short);

    std::string show_invetory() const;

    void push_inventory(std::shared_ptr<Item>);

    void pop_inventory(size_t id);

};

#endif //LAB4_FORAGER_H
