#ifndef LAB4_MAP_H
#define LAB4_MAP_H

#include "Cell.h"
#include "Glass.h"
#include "Weak wall.h"
#include "Wall.h"
#include "Floor.h"

class Map {
private:
    std::vector<std::vector<std::shared_ptr<Cell>>> map;
    size_t sizeX;
    size_t sizeY;
public:
    Map(std::vector<std::vector<std::shared_ptr<Cell>>> map, size_t sizeMapX, size_t sizeMapY);

    size_t getSizeX() const;

    size_t getSizeY() const;

    std::shared_ptr<Cell> get_cell(size_t x,size_t y);

};


#endif
