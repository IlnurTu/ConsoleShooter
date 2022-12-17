#include "Level.h"
#ifndef LAB4_INTELLIGENT_CONTROL_SYSTEM_H
#define LAB4_INTELLIGENT_CONTROL_SYSTEM_H

class IntelligentControlSystem {
private:
    std::shared_ptr<Level> lvl;
    std::shared_ptr<Operative> current_intelligent;
public:
    IntelligentControlSystem(std::shared_ptr<Level> lvl, std::shared_ptr<Operative> current_operative);

    void shoot(direction drctn);

    void take_step(direction drctn);

    void set_intelligent(std::shared_ptr<Operative> operative);

    void take_item(size_t id);
};


};

#endif
