#ifndef LAB4_INTELLIGENT_H
#define LAB4_INTELLIGENT_H
#include "Wild.h"
#include "Weapon.h"

class Intelligent:public Wild{
protected:
    std::shared_ptr<Weapon> current_weapon;
public:
    Intelligent(std::string name, unsigned short max_health, unsigned short points_time_for_step,
                unsigned short viewing_radius, unsigned short max_points_time, size_t coordinate_x, size_t coordinate_y,
                unsigned short accuracy, unsigned short damage, unsigned short points_time_for_shoot,
                std::shared_ptr<Weapon> current_weapon = nullptr);

    std::shared_ptr<Weapon> get_current_weapon() const;

    std::shared_ptr<Weapon> set_current_weapon(std::shared_ptr<Weapon>);

    virtual size_t shoot() override;
};

#endif
