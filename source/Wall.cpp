#include "../headers/Wall.h"

Wall::Wall(std::string name, unsigned short x, unsigned short y) :
        Cell(std::move(name), x, y, false, true, Inventory(), nullptr) {};

void Wall::shoot() {};

Wall &Wall::pushItem(std::shared_ptr<Item>) { return *this; }

std::shared_ptr<Item> Wall::extractItem(size_t id) { return nullptr; }

std::shared_ptr<Item> Wall::get_item(size_t id) const { return nullptr; }

size_t Wall::get_count_items() const { return 0; }

