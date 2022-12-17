#ifndef LAB4_INVENTORY_H
#define LAB4_INVENTORY_H

#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Rifle.h"
#include "Gun.h"
#include "Kit.h"
#include "Container of bullets.h"


class Inventory {
private:
    std::vector<std::shared_ptr<Item>> arr;
public:
    Inventory();

    Inventory(const Inventory &el);

    Inventory(Inventory &&el) noexcept;

    Inventory& operator = (Inventory inventory);

    Inventory &add(std::shared_ptr<Item> item);

    size_t getCount() const;

    size_t getWeight() const;

    std::shared_ptr<Item> eraseItem(size_t id);

    std::shared_ptr<Item> getItem(size_t id) const;

    using ConstIterator = typename std::vector<std::shared_ptr<Item>>::const_iterator;

    ConstIterator cbegin() const;

    ConstIterator cend() const;

    std::string get_info() const;

};

#endif //LAB4_INVENTORY_H
