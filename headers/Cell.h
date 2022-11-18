#ifndef LAB4_CELL_H
#define LAB4_CELL_H
#include "Unit.h"
#include "Inventory.h"

class Cell{
protected:
    std::string name;
    bool is_transparent;
    Point coordinate;
    bool is_bullet_stop;
public:
    Cell(std::string name,unsigned short x,unsigned short y,bool is_transparent,bool is_bullet_stop);

    virtual void shoot() = 0;

    Point get_coordinate() const;

    bool get_shoot_state() const;

    bool get_view_state() const;

};

#endif //LAB4_CELL_H
