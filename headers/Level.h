#ifndef LAB4_LEVEL_H
#define LAB4_LEVEL_H
#include "Operative.h"
#include "Rifle.h"
#include "Gun.h"
#include "Kit.h"
#include "Container of bullets.h"
#include "Cell.h"


class Level{
public:
    std::vector<std::shared_ptr<Operative>> operatives;
    std::vector<std::shared_ptr<Forager>> foragers;
    std::vector<std::shared_ptr<Wild>> wilds;
    std::vector<std::shared_ptr<Intelligent>> intelligents;
    std::vector<std::vector<std::shared_ptr<Cell>>> map;
};

#endif
