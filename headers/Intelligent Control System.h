#include "Level.h"

#ifndef LAB4_INTELLIGENT_CONTROL_SYSTEM_H
#define LAB4_INTELLIGENT_CONTROL_SYSTEM_H

class IntelligentControlSystem {
protected:
    Level &lvl;
    std::shared_ptr<Intelligent>& current_intelligent;
public:
    IntelligentControlSystem(Level& lvl, std::shared_ptr<Intelligent>& current_intelligent);

    void shoot(direction drctn);

    void take_step(direction drctn);

    void set_intelligent(std::shared_ptr<Intelligent>& intelligent);

    void take_weapon(size_t id);

    void shoot();

    void changeWeapon();
};


#endif
