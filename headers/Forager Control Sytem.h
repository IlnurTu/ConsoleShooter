#include "Level.h"
#ifndef LAB4_FORAGER_CONTROL_SYTEM_H
#define LAB4_FORAGER_CONTROL_SYTEM_H

class ForagerControlSystem{
private:
    std::shared_ptr<Level> lvl;
    std::shared_ptr<Wild> current_forager;
public:
    ForagerControlSystem(std::shared_ptr<Level> lvl,std::shared_ptr<Wild> current_wild);

    void set_forager(std::shared_ptr<Wild> wild);

    void take_step(direction drctn);

    void take_item(size_t id);

    void throw_item(size_t id);

};


#endif //LAB4_FORAGER_CONTROL_SYTEM_H
