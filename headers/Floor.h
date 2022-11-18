#ifndef LAB4_FLOOR_H
#define LAB4_FLOOR_H
#include "Cell.h"
class Floor: public Cell{
private:
    Inventory inventory;
public:
    Floor(std::string name,unsigned short x,unsigned short y,bool is_transparent,bool is_bullet_stop,
          Inventory inventory = Inventory());

    virtual void shoot() override;

    std::string show_items() const;

    std::shared_ptr<Item> extractItem(size_t id);

    Floor& pushItem(std::shared_ptr<Item>);
};
#endif //LAB4_FLOOR_H
