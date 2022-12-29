#include "../headers/Wild Graphic System.h"


GraphicWildLogic::GraphicWildLogic(Level &lvl, std::shared_ptr<Wild> &current_wild) : WildControlSystem(lvl,
                                                                                                        current_wild),
                                                                                      DrawSystem(lvl) {};

void GraphicWildLogic::takeStep() {
    direction drct = static_cast<direction>(rand() % 8);
    WildControlSystem::take_step(drct);
    DrawSystem::drawMap();
}

void GraphicWildLogic::shoot() {
    WildControlSystem::shoot();
    GraphicWildLogic::drawMap();
}

void GraphicWildLogic::setWild(std::shared_ptr<Wild> &wild) {
    current_wild = wild;
}

void GraphicWildLogic::makeMove() {
    while (current_wild->get_general_parameters().current_points_time != 0) {
        shoot();
        takeStep();
    }
    current_wild->reload_current_time();
}
