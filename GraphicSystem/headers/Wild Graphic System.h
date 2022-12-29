#ifndef LAB4_WILD_GRAPHIC_SYSTEM_H
#define LAB4_WILD_GRAPHIC_SYSTEM_H
#include "../../Control System/headers/Wild Control System.h"
#include "DrawSystem.h"

class GraphicWildLogic: public WildControlSystem,DrawSystem{
public:
    GraphicWildLogic(Level& lvl,std::shared_ptr<Wild>& current_wild);

    void takeStep();

    void shoot();

    void setWild(std::shared_ptr<Wild>& wild);

    void makeMove();
};

#endif //LAB4_WILD_GRAPHIC_SYSTEM_H
