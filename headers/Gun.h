#ifndef LAB4_GUN_H
#define LAB4_GUN_H
#include "Weapon.h"
class Gun: public Weapon{
public:
    Gun(std::string name, unsigned short weight, unsigned short damage,
        unsigned short type_bullets, unsigned short current_number_bullets,
        unsigned short max_number_bullets, unsigned short points_time_for_shoot);

    unsigned short shoot() override;
};


#endif //LAB4_GUN_H
