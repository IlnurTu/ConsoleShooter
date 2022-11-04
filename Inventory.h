#ifndef LAB4_INVENTORY_H
#define LAB4_INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory{
private:
    size_t MAX_COUNT = 50;

    std::vector<Item*> arr;

    void swap(Inventory&) noexcept;

public:
    Inventory();

    ~Inventory();

    Inventory(const Inventory& el);

    Inventory(Inventory&& el) noexcept;

    Inventory& operator =(Inventory el);

    void add(Item* item);

    size_t getCount() const;

    Item* getItem(size_t number);

    std::ostream& show(std::ostream&) const;

    friend std::ostream& operator <<(std::ostream&,const Inventory&);

    Inventory& operator++();

    Item* throwItem(size_t number);
};

#endif //LAB4_INVENTORY_H
