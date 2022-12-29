#ifndef LAB4_FLOOR_H
#define LAB4_FLOOR_H

#include "Cell.h"

class Floor : public Cell {
private:
    Inventory inventory;
public:
    Floor(std::string name, unsigned short x, unsigned short y, Inventory inventory, std::shared_ptr<Unit> unit);

    virtual void shoot() override;

    virtual char get_character() const override;

};

#endif //LAB4_FLOOR_H
