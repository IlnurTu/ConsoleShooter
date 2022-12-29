#ifndef LAB4_GAME_H
#define LAB4_GAME_H

#include "../../File System/headers/LoadUnloadFile.h"
#include "../../GraphicSystem/headers/Graphic Intelligent System.h"
#include "../../GraphicSystem/headers/Graphic Logic Forager.h"
#include "../../GraphicSystem/headers/Graphic Operative Control System.h"
#include "../../GraphicSystem/headers/Wild Graphic System.h"


class Game {
private:
    Level level;
public:
    Game();

    void run();
};

#endif
