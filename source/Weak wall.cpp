#include "../headers/Weak wall.h"

WeakWall::WeakWall(std::string name, unsigned short x, unsigned short y, bool is_transparent, bool is_bullet_stop,
                   Inventory inventory,std::shared_ptr<Unit> unit) :
        Cell(std::move(name), x, y, is_transparent, is_bullet_stop, std::move(inventory),std::move(unit)) {};

void WeakWall::shoot() {
    is_bullet_stop = false;
    is_transparent = true;
};

std::shared_ptr<Item> WeakWall::get_item(size_t id) const {
    if (!is_bullet_stop) {
        return Cell::get_item(id);
    }
    return nullptr;
}

std::shared_ptr<Item> WeakWall::extractItem(size_t id) {
    if (!is_bullet_stop) {
        return Cell::extractItem(id);
    }
    return nullptr;
}

WeakWall &WeakWall::pushItem(std::shared_ptr<Item> newItem) {
    if (!is_bullet_stop) {
        return static_cast<WeakWall&>(Cell::pushItem(newItem));
    }
    return *this;
}

size_t WeakWall::get_count_items() const {
    if (!is_bullet_stop) {
        return Cell::get_count_items();
    }
    return 0;
}


