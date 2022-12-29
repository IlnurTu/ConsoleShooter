#ifndef LAB4_WILD_CONTROL_SYSTEM_H
#define LAB4_WILD_CONTROL_SYSTEM_H

#include "../../Application/headers/Level.h"

class WildControlSystem {
protected:
    Level &lvl;
    std::shared_ptr<Wild> &current_wild;
public:

    WildControlSystem(Level &lvl, std::shared_ptr<Wild> &current_wild);

    void set_wild(std::shared_ptr<Wild> &wild);

    void take_step(direction drctn);

    void shoot(direction drctn);

    void shoot();

};


#endif //LAB4_WILD_CONTROL_SYSTEM_H
