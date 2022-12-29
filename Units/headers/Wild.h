#ifndef LAB4_WILD_H
#define LAB4_WILD_H

#include "Unit.h"

class Wild : virtual public Unit {
protected:
    unsigned short damage;
    unsigned int points_time_for_shoot;

public:

    Wild(std::string name, unsigned short max_health, unsigned short current_health,
         unsigned short points_time_for_step,
         unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
         size_t coordinate_x, size_t coordinate_y,
         unsigned short damage, unsigned short points_time_for_shoot);


    unsigned short get_points_time_for_shoot() const;

    unsigned short get_damage() const;

    virtual unsigned short shoot();

    std::string get_info() const;

    virtual char get_character() const override;

};

#endif //LAB4_WILD_H
