#ifndef LAB4_CELL_H
#define LAB4_CELL_H
#include "Point.h"
#include "Inventory.h"

class Cell{
protected:
    bool view_state; // true if it is seen unit
    Point coordinate;
    bool shoot_state; //true if it is
public:
    Cell(unsigned short x,unsigned short y);

    virtual void shoot() = 0;

    const Point& get_coordinate() const;

    bool get_shoot_state() const;

    bool get_view_state() const;

    void set_shoot_state(bool);

    void set_coordinate(const Point&);

    void set_view_state(bool);
};

#endif //LAB4_CELL_H
