#ifndef LAB4_OPERATIVE_H
#define LAB4_OPERATIVE_H
#include "Intelligent.h"
#include "Forager.h"

class Operative: public Forager,public Intelligent{
public:
    Operative(std::string name, unsigned short max_health, unsigned short points_time_for_step,
              unsigned short viewing_radius, unsigned short max_points_time, size_t coordinate_x, size_t coordinate_y,
              unsigned short accuracy, unsigned short damage, unsigned short points_time_for_shoot,
              std::shared_ptr<Weapon> current_weapon = nullptr,Inventory inventory = Inventory());

    Operative& set_current_weapon(size_t id);

    Operative& use_kit(size_t id);

    Operative& reload_weapon();
};

#endif //LAB4_OPERATIVE_H
