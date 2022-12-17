#include "../headers/Floor.h"

Floor::Floor(std::string name, unsigned short x, unsigned short y, Inventory inventory,std::shared_ptr<Unit> unit):
        Cell(std::move(name),x,y,true,false,std::move(inventory),std::move(unit)){};

void Floor::shoot() {};

