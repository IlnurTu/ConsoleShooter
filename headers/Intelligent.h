#ifndef LAB4_INTELLIGENT_H
#define LAB4_INTELLIGENT_H
#include "Wild.h"
#include "Weapon.h"

class Intelligent:public Wild{
protected:
    std::unique_ptr<Weapon> current_weapon;
public:
    Intelligent(std::string name, unsigned short max_health, unsigned short current_health, unsigned short points_time_for_step,
                unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
                size_t coordinate_x,size_t coordinate_y, unsigned short damage,
                unsigned short points_time_for_shoot, std::unique_ptr<Weapon> current_weapon);

    const std::unique_ptr<Weapon>& get_current_weapon() const;

    std::unique_ptr<Weapon> set_current_weapon(std::unique_ptr<Weapon>);

    virtual unsigned short shoot() override;

    std::string get_info() const;

    virtual char get_character() const override;
};

#endif
