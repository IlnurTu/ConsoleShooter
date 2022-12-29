#ifndef LAB4_GRAPHIC_LOGIC_FORAGER_H
#define LAB4_GRAPHIC_LOGIC_FORAGER_H

#include "../../Control System/headers/Forager Control Sytem.h"
#include "DrawSystem.h"

class GraphicForagerLogic : public ForagerControlSystem, public DrawSystem {
public:
    GraphicForagerLogic(Level &lvl, std::shared_ptr<Forager> &forager) : ForagerControlSystem(lvl, forager),
                                                                         DrawSystem(lvl) {};

    void takeStep();

    void takeItems();

    void throwItems();

    void setForager(std::shared_ptr<Forager> &forager);

    void makeMove();


};

#endif //LAB4_GRAPHIC_LOGIC_FORAGER_H
