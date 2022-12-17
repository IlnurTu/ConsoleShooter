#ifndef LAB4_WILD_CONTROL_SYSTEM_H
#define LAB4_WILD_CONTROL_SYSTEM_H
#include "Level.h"
class WildControlSystem{
private:
    std::shared_ptr<Level> lvl;
    std::shared_ptr<Wild> current_wild;
public:
    WildControlSystem(std::shared_ptr<Level> lvl,std::shared_ptr<Wild> current_wild);

    void set_wild(std::shared_ptr<Wild> wild);

    void take_step(direction drctn);

    void shoot(direction drctn);

};

#endif //LAB4_WILD_CONTROL_SYSTEM_H