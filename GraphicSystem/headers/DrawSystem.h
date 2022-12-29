#ifndef LAB4_DRAWSYSTEM_H
#define LAB4_DRAWSYSTEM_H

#include "../../Application/headers/Level.h"
#include <iostream>

class DrawSystem {
private:
    Level &lvl;
public:
    DrawSystem(Level &lvl);

    void drawMap();

    void drawInventoryOperative(const std::shared_ptr<Operative> &operative);

    void drawInfoCurrentOperative(const std::shared_ptr<Operative> &operative);

    void drawInfoEnemy();

    void drawListOperatives();

    void drawListEnemy();

    void drawInventoryCell(const std::shared_ptr<Operative> &operative);
};

#endif //LAB4_DRAWSYSTEM_H
