#include "../headers/Glass.h"

Glass::Glass(std::string name, unsigned short x, unsigned short y, bool is_bullet_stop,
             Inventory inventory, std::shared_ptr<Unit> unit) :
        Cell(std::move(name), x, y, true, is_bullet_stop, std::move(inventory), std::move(unit)) {}

void Glass::shoot() {
    is_bullet_stop = false;
};

std::shared_ptr<Item> Glass::get_item(size_t id) const {
    if (!is_bullet_stop) {
        return Cell::get_item(id);
    }
    return nullptr;
}

std::shared_ptr<Item> Glass::extractItem(size_t id) {
    if (!is_bullet_stop) {
        return Cell::extractItem(id);
    }
    return nullptr;
}

Glass &Glass::pushItem(std::shared_ptr<Item> newItem) {
    if (!is_bullet_stop) {
        return static_cast<Glass &>(Cell::pushItem(newItem));
    }
    return *this;
}

size_t Glass::get_count_items() const {
    if (!is_bullet_stop) {
        return Cell::get_count_items();
    }
    return 0;
}




