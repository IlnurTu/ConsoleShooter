#ifndef LAB4_UNIT_H
#define LAB4_UNIT_H

#include <string>
#include "Direction enum.h"

struct base_parameters {
    std::string name;
    unsigned short max_health;
    unsigned short current_health;
    unsigned short points_time_for_step;
    unsigned short viewing_radius;
    unsigned short current_points_time;
    unsigned short max_points_time;
};

struct Point {
    size_t x, y;
};

class Unit {
protected:
    base_parameters main_parameters;
    Point position;
public:
    Unit(std::string name, unsigned short max_health, unsigned short points_time_for_step,
         unsigned short viewing_radius, unsigned short max_points_time,size_t coordinate_x,size_t coordinate_y);

    virtual ~Unit();

    base_parameters get_general_parametres() const;

    Point get_position() const;

    Unit& take_step(direction);

    Unit& get_damage(unsigned short);

    Unit& reload_current_time();
};

#endif //LAB4_UNIT_H
