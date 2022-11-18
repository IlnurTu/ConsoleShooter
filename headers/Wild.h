#ifndef LAB4_WILD_H
#define LAB4_WILD_H
#include "Unit.h"

class Wild: virtual public Unit{
protected:
    unsigned short damage;
    unsigned int points_time_for_shoot;
    unsigned short accuracy;
public:

    Wild(std::string name, unsigned short max_health, unsigned short points_time_for_step,
         unsigned short viewing_radius, unsigned short max_points_time, size_t coordinate_x, size_t coordinate_y,
         unsigned short accuracy, unsigned short damage, unsigned short points_time_for_shoot);

    unsigned short get_accuracy() const;

    unsigned short get_points_time_for_shoot() const;

    virtual size_t shoot();

};

#endif //LAB4_WILD_H
