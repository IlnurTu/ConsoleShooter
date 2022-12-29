
#ifndef LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H
#define LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H

#include "../../Control System/headers/Operative control system.h"
#include "DrawSystem.h"

class GraphicOperativeControlSystem : public OperativeControlSystem, public DrawSystem {
public:
    GraphicOperativeControlSystem(Level &lvl, std::shared_ptr<Operative> &operative);

    void takeStep(direction drctn);

    void reloadWeapon();

    void shoot(direction drctn) ;

    void drawItemsOnCell();

    void drawDefolt() ;

    void drawInventory();

    void takeItem() ;

    void changeWeapon();

    void throwItem();

    bool isPoints();

    void setOperative();

    void makeMove();
};

#endif //LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H
