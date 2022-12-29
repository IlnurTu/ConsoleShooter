#include "Level.h"
#ifndef LAB4_FORAGER_CONTROL_SYTEM_H
#define LAB4_FORAGER_CONTROL_SYTEM_H

class ForagerControlSystem{
protected:
    Level& lvl;
    std::shared_ptr<Forager>& current_forager;
public:
    ForagerControlSystem(Level& lvl,std::shared_ptr<Forager>& current_forager);

    void set_forager(std::shared_ptr<Forager>& forager);

    void take_step(direction drctn);

    void take_items();

    void throw_items();

};


#endif //LAB4_FORAGER_CONTROL_SYTEM_H
