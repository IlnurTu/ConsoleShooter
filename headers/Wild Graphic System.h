#ifndef LAB4_WILD_GRAPHIC_SYSTEM_H
#define LAB4_WILD_GRAPHIC_SYSTEM_H
#include "Wild Control System.h"
#include "DrawSystem.h"

class GraphicWildLogic: public WildControlSystem,DrawSystem{
public:
    GraphicWildLogic(Level& lvl,std::shared_ptr<Wild>& current_wild): WildControlSystem(lvl,current_wild), DrawSystem(lvl){};

    void takeStep(){
        direction drct = static_cast<direction>(rand() % 8);
        WildControlSystem::take_step(drct);
        DrawSystem::drawMap();
    }

    void shoot(){
       WildControlSystem::shoot();
       GraphicWildLogic::drawMap();
    }

    void setWild(std::shared_ptr<Wild>& wild){
        current_wild = wild;
    }

    void makeMove(){
        while(current_wild->get_general_parameters().current_points_time != 0){
            shoot();
            takeStep();
        }
        current_wild->reload_current_time();
    }
};

#endif //LAB4_WILD_GRAPHIC_SYSTEM_H
