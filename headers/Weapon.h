
#ifndef LAB4_WEAPON_H
#define LAB4_WEAPON_H

#include "Item.h"

class Weapon : Item {
protected:
    unsigned short damage;
    unsigned short type_bullets;
    unsigned short current_number_bullets;
    unsigned short max_number_bullets;
    unsigned short time_shoot;
public:
    Weapon(std::string name, unsigned short weight, unsigned short damage,
           unsigned short type_bullets, unsigned short current_number_bullets,
           unsigned short max_number_bullets, unsigned short time_shoot);

    unsigned short get_damage() const;

    unsigned short get_type_bullets() const;

    unsigned short get_current_number_bullets() const;

    unsigned short get_max_number_bullets() const;

    unsigned short get_time_shoot() const;

    void set_damage(unsigned short);

    void set_type_bullets(unsigned short);

    void set_current_number_bullets(unsigned short);

    void set_max_number_bullets(unsigned short);

    void set_time_shoot(unsigned short);

    void reload();

    virtual unsigned short shoot() = 0;
};

#endif //LAB4_WEAPON_H
