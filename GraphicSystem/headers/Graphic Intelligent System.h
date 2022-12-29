#ifndef LAB4_GRAPHIC_INTELLIGENT_SYSTEM_H
#define LAB4_GRAPHIC_INTELLIGENT_SYSTEM_H

#include "../../Control System/headers/Intelligent Control System.h"
#include "DrawSystem.h"

class GraphicIntelligentLogic : public IntelligentControlSystem, public DrawSystem {
public:
    GraphicIntelligentLogic(Level &lvl, std::shared_ptr<Intelligent> &current_intelligent);

    void takeStep();

    void shoot();

    void changeWeapon();

    void makeMove();
};

#endif
