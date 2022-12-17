
#ifndef LAB4_OPERATIVE_CONTROL_SYSTEM_H
#define LAB4_OPERATIVE_CONTROL_SYSTEM_H

#include "Level.h"
#include <iostream>

class OperativeControlSystem {
private:
    std::shared_ptr<Level> lvl;
    std::shared_ptr<Operative> current_operative;
public:
    OperativeControlSystem(std::shared_ptr<Level> lvl, std::shared_ptr<Operative> current_operative);

    void shoot(direction drctn);

    void take_step(direction drctn);

    void set_operative(std::shared_ptr<Operative> operative);

    void take_item(size_t id);

    void throw_item(size_t id);
};

#endif
