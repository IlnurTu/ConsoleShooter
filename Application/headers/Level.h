#ifndef LAB4_LEVEL_H
#define LAB4_LEVEL_H

#include "../../Units/headers/Operative.h"
#include "../../Items/headers/Rifle.h"
#include "../../Items/headers/Gun.h"
#include "../../Items/headers/Kit.h"
#include "../../Items/headers/Container of bullets.h"
#include "../../Map/headers/Cell.h"
#include "../../Map/headers/Map.h"


struct Level {
    std::vector<std::shared_ptr<Operative>> operatives;
    std::vector<std::shared_ptr<Forager>> foragers;
    std::vector<std::shared_ptr<Wild>> wilds;
    std::vector<std::shared_ptr<Intelligent>> intelligents;
    std::shared_ptr<Map> map;
    std::vector<Point> StoragePoints;
    size_t countEnemy;
    size_t countOperative;
};

#endif
