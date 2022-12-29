#ifndef LAB4_GRAPHIC_LOGIC_FORAGER_H
#define LAB4_GRAPHIC_LOGIC_FORAGER_H

#include "Forager Control Sytem.h"
#include "DrawSystem.h"

class GraphicForagerLogic : public ForagerControlSystem, public DrawSystem {
public:
    GraphicForagerLogic(Level &lvl, std::shared_ptr<Forager> &forager) : ForagerControlSystem(lvl, forager),
                                                                         DrawSystem(lvl) {};

    void takeStep() {
        direction drct = static_cast<direction>(rand() % 8);
        ForagerControlSystem::take_step(drct);
        DrawSystem::drawMap();
    }

    void takeItems() {
        ForagerControlSystem::take_items();
        DrawSystem::drawMap();
    }

    void throwItems() {
        ForagerControlSystem::throw_items();
        DrawSystem::drawMap();
    }

    void setForager(std::shared_ptr<Forager> &forager) {
        current_forager = forager;
    }

    void makeMove() {
        while (current_forager->get_general_parameters().current_points_time != 0) {
            takeItems();
            throwItems();
            takeStep();
        }
        current_forager->reload_current_time();
    }


};

#endif //LAB4_GRAPHIC_LOGIC_FORAGER_H
