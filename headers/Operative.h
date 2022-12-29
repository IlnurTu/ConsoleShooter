#ifndef LAB4_OPERATIVE_H
#define LAB4_OPERATIVE_H
#include "Intelligent.h"
#include "Forager.h"

class Operative: public Forager,public Intelligent{
public:
    Operative(std::string name, unsigned short max_health, unsigned short current_health, unsigned short points_time_for_step,
              unsigned short viewing_radius, unsigned short max_points_time, unsigned short current_points_time,
              size_t coordinate_x,size_t coordinate_y, unsigned short damage,
              unsigned short points_time_for_shoot, std::unique_ptr<Weapon> current_weapon,
              unsigned short max_weight,unsigned short current_weight, Inventory inventory);

    Operative& set_current_weapon(size_t id);

    Operative& use_kit(size_t id);

    Operative& reload_weapon();

    std::string get_info() const;

    virtual char get_character() const override;
};

#endif //LAB4_OPERATIVE_H
