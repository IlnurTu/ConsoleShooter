#include "../headers/Wall.h"

Wall::Wall(std::string name, unsigned short x, unsigned short y) :
        Cell(std::move(name), x, y, false, true, Inventory(), nullptr) {};

void Wall::shoot() {};

Wall &Wall::pushItem(std::unique_ptr<Item>) { return *this; }

std::unique_ptr<Item> Wall::extractItem(size_t id) { return nullptr; }

const std::unique_ptr<Item>& Wall::get_item(size_t id) const { return nullptr; }

size_t Wall::get_count_items() const { return 0; }

char Wall::get_character() const {

    return '#';
}