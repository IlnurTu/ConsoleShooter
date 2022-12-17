#include "../headers/Map.h"

Map::Map(std::vector<std::vector<std::shared_ptr<Cell>>> map, size_t sizeMapX, size_t sizeMapY) : map(std::move(map)) {
    if (sizeMapX < 1 || sizeMapY < 1)
        throw std::runtime_error("The dimensions must be greater than zero");
    this->sizeX = sizeMapX;
    this->sizeY = sizeMapY;
}

size_t Map::getSizeX() const {
    return sizeX;
}

size_t Map::getSizeY() const {
    return sizeY;
}

std::shared_ptr<Cell> Map::get_cell(size_t x, size_t y) {
    if (x >= sizeX || x < 0 || y >= sizeY || y < 0 )
        return nullptr;
    return map[x][y];
}
