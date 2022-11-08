#ifndef LAB4_OPERATIVE_H
#define LAB4_OPERATIVE_H
#include "Intelligent.h"
#include "Forager.h"

class Operative: public Forager,public Intelligent{
public:
    Operative(std::string name);

    Operative(std::string name, unsigned short max_health, unsigned short time_step,
              unsigned short viewing_radius, unsigned short max_points_time, unsigned short accuracy,
              unsigned short max_weight,unsigned short time_shoot);

    void set_current_weapon(size_t id);

    void use_kit(size_t id);

    void reload_weapon();
};

#endif //LAB4_OPERATIVE_H
