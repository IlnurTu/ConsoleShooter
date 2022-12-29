#ifndef LAB4_GRAPHIC_INTELLIGENT_SYSTEM_H
#define LAB4_GRAPHIC_INTELLIGENT_SYSTEM_H

#include "Intelligent Control System.h"
#include "DrawSystem.h"

class GraphicIntelligentLogic : public IntelligentControlSystem, public DrawSystem {
public:
    GraphicIntelligentLogic(Level &lvl, std::shared_ptr<Intelligent> &current_intelligent) : IntelligentControlSystem(
            lvl, current_intelligent), DrawSystem(lvl) {};

    void takeStep() {
        direction drct = static_cast<direction>(rand() % 8);
        IntelligentControlSystem::take_step(drct);
    }

    void shoot() {
        IntelligentControlSystem::shoot();
        DrawSystem::drawMap();
    }

    void changeWeapon() {
        IntelligentControlSystem::changeWeapon();
        DrawSystem::drawMap();
    }

    void makeMove() {
        while (current_intelligent->get_general_parameters().current_points_time != 0){
            changeWeapon();
            shoot();
            takeStep();
        }
        current_intelligent->reload_current_time();
    }
};

#endif
