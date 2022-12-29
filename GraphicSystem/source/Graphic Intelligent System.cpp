#include "../headers/Graphic Intelligent System.h"


GraphicIntelligentLogic::GraphicIntelligentLogic(Level &lvl, std::shared_ptr<Intelligent> &current_intelligent)
        : IntelligentControlSystem(
        lvl, current_intelligent), DrawSystem(lvl) {};

void GraphicIntelligentLogic::takeStep() {
    direction drct = static_cast<direction>(rand() % 8);
    IntelligentControlSystem::take_step(drct);
}

void GraphicIntelligentLogic::shoot() {
    IntelligentControlSystem::shoot();
    DrawSystem::drawMap();
}

void GraphicIntelligentLogic::changeWeapon() {
    IntelligentControlSystem::changeWeapon();
    DrawSystem::drawMap();
}

void GraphicIntelligentLogic::makeMove() {
    while (current_intelligent->get_general_parameters().current_points_time != 0) {
        changeWeapon();
        shoot();
        takeStep();
    }
    current_intelligent->reload_current_time();
}
