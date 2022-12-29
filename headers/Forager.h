#ifndef LAB4_FORAGER_H
#define LAB4_FORAGER_H

#include "Unit.h"
#include "Inventory.h"
#include "Kit.h"

class Forager : virtual public Unit {
protected:
    unsigned short max_weight;
    unsigned short current_weight;
    Inventory inventory;
public:
    Forager(std::string name, unsigned short max_health, unsigned short current_health, unsigned short points_time_for_step,
            unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
            size_t coordinate_x,size_t coordinate_y, unsigned short max_weight,unsigned short current_weight, Inventory inventory);

    unsigned short get_max_weight() const;

    unsigned short get_current_weight() const;

    Forager& push_inventory(std::unique_ptr<Item>);

    std::unique_ptr<Item> pop_inventory(size_t id);

    const std::unique_ptr<Item>& get_item(size_t id) const;

    size_t get_count_items() const;

    std::string get_info() const;

    virtual char get_character() const override;
};

#endif //LAB4_FORAGER_H
