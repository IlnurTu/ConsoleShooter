#ifndef LAB4_UNIT_H
#define LAB4_UNIT_H

#include <string>
#include "Point.h"
#include "Base parameters.h"
#include "Direction enum.h"

class Unit {
protected:
    base_parameters general_parameters;
    Point position;
public:
    Unit(const std::string &);

    Unit(const std::string &name, unsigned short max_health, unsigned short time_step,
         unsigned short viewing_radius, unsigned short max_points_time);

    virtual ~Unit();

    base_parameters get_general_parametres() const;

    Point get_position() const;

    void set_position(const Point&);

    void set_general_parametres(const base_parameters &);

    void take_step(direction);

    void get_damage(unsigned short);

    void reload_current_time();
};

#endif //LAB4_UNIT_H
