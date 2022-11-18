#ifndef LAB4_INVENTORY_H
#define LAB4_INVENTORY_H
#include <vector>
#include "Item.h"


class Inventory{
private:
    std::vector<std::shared_ptr<Item>> arr;
public:
    Inventory();

    Inventory(const Inventory& el);

    Inventory(Inventory&& el) noexcept;

    Inventory& add(std::shared_ptr<Item> item);

    size_t getCount() const;

    size_t getWeight() const;

    std::shared_ptr<Item> eraseItem(size_t id);

    using Const_Iterator = std::vector<std::shared_ptr<Item>>::const_iterator;

    Const_Iterator сbegin(){return arr.cbegin();}

    Const_Iterator сend(){return arr.cend();}

};

#endif //LAB4_INVENTORY_H
