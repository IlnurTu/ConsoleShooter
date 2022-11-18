#ifndef LAB4_FLOOR_H
#define LAB4_FLOOR_H
#include "Cell.h"
class Floor: public Cell{
private:
    Inventory inventory;
public:
    Floor(unsigned int x,unsigned int y);

    virtual void shoot() override;

    std::ostream& show_items(std::ostream&) const;

    std::shared_ptr<Item> extract_item(size_t id);

    void push_item(std::shared_ptr<Item>);
};
#endif //LAB4_FLOOR_H
