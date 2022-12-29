//
// Created by Ильнур Тухватулин on 08.11.2022.
//

#ifndef LAB4_RIFLE_H
#define LAB4_RIFLE_H
#include "Weapon.h"
class Rifle: public Weapon{
public:
    Rifle(std::string name, unsigned short weight, unsigned short damage,
          unsigned short type_bullets, unsigned short current_number_bullets,
          unsigned short max_number_bullets, unsigned short points_time_for_shoot,
          unsigned short points_time_for_reload,unsigned short firing_range);

    unsigned short shoot() override;

};

#endif //LAB4_RIFLE_H
