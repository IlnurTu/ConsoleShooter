#include "../headers/Graphic Logic Forager.h"

GraphicForagerLogic::GraphicForagerLogic(Level &lvl, std::shared_ptr<Forager> &forager) : ForagerControlSystem(lvl,
                                                                                                               forager),
                                                                                          DrawSystem(lvl) {};

void GraphicForagerLogic::takeStep() {
    direction drct = static_cast<direction>(rand() % 8);
    ForagerControlSystem::take_step(drct);
    DrawSystem::drawMap();
}

void GraphicForagerLogic::takeItems() {
    ForagerControlSystem::take_items();
    DrawSystem::drawMap();
}

void GraphicForagerLogic::throwItems() {
    ForagerControlSystem::throw_items();
    DrawSystem::drawMap();
}

void GraphicForagerLogic::setForager(std::shared_ptr<Forager> &forager) {
    current_forager = forager;
}

void GraphicForagerLogic::makeMove() {
    while (current_forager->get_general_parameters().current_points_time != 0) {
        takeItems();
        throwItems();
        takeStep();
    }
    current_forager->reload_current_time();
}


};