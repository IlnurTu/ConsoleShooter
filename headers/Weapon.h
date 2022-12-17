
#ifndef LAB4_WEAPON_H
#define LAB4_WEAPON_H

#include "Item.h"

struct weapon_parameters {
    unsigned short damage;
    unsigned short current_number_bullets;
    unsigned short max_number_bullets;
    unsigned short points_time_for_shoot;
    unsigned short points_time_for_reload;
    unsigned short firing_range;
};

class Weapon : public Item {
protected:
    weapon_parameters parameters;
    unsigned short type_bullets;
public:
    Weapon(std::string name, unsigned short weight, unsigned short damage,
           unsigned short type_bullets, unsigned short current_number_bullets,
           unsigned short max_number_bullets, unsigned short points_time_for_shoot,
           unsigned short points_time_for_reload, unsigned short firing_range);

    weapon_parameters get_parameters() const;

    Weapon &reload(unsigned short);

    unsigned short get_type_bullets() const;

    virtual unsigned short shoot() = 0;

    std::string get_info() const override;

};


#endif //LAB4_WEAPON_H
