#include "../headers/Rifle.h"

Rifle::Rifle(std::string name, unsigned short weight, unsigned short damage, unsigned short type_bullets,
             unsigned short current_number_bullets, unsigned short max_number_bullets,
             unsigned short points_time_for_shoot, unsigned short points_time_for_reload,unsigned short firing_range) :
        Weapon(std::move(name), weight, damage, type_bullets, current_number_bullets, max_number_bullets,
               points_time_for_shoot, points_time_for_reload,firing_range){};

unsigned short Rifle::shoot() {
    unsigned short result_damage = 0;
    if(parameters.current_number_bullets<5){
        result_damage = parameters.current_number_bullets * parameters.damage;
        parameters.current_number_bullets = 0;
    }
    else{
        result_damage = parameters.damage * 5;
        parameters.current_number_bullets -=5;
    }
    return result_damage;
}
