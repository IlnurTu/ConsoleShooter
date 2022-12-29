#include "../headers/Gun.h"

Gun::Gun(std::string name, unsigned short weight, unsigned short damage, unsigned short type_bullets,
             unsigned short current_number_bullets, unsigned short max_number_bullets,
             unsigned short points_time_for_shoot, unsigned short points_time_for_reload,unsigned short firing_range) :
        Weapon(std::move(name), weight, damage, type_bullets, current_number_bullets, max_number_bullets,
               points_time_for_shoot, points_time_for_reload,firing_range){};

unsigned short Gun::shoot() {
   if(parameters.current_number_bullets == 0){
       return 0;
   }
   else{
       parameters.current_number_bullets -= 1;
       return parameters.damage;
   }
}