#ifndef LAB4_GAME_H
#define LAB4_GAME_H

#include "LoadUnloadFile.h"
#include "Graphic Intelligent System.h"
#include "Graphic Logic Forager.h"
#include "Graphic Operative Control System.h"
#include "Wild Graphic System.h"


class Game {
private:
    Level level;
public:
    Game() : level(LoadStoreSystem::load()) {};

    void run() {
        while (level.countEnemy != 0 && level.countOperative != 0) {
            for (auto &el: level.operatives) {
                if (el->get_general_parameters().current_health != 0) {
                    GraphicOperativeControlSystem OperativeSystem(level, el);
                    OperativeSystem.makeMove();
                    break;
                }
            }
            for (auto &el: level.wilds) {
                if (el->get_general_parameters().current_health != 0) {
                    GraphicWildLogic WildSystem(level, el);
                    WildSystem.makeMove();
                }
            }

            for (auto &el: level.intelligents) {
                if (el->get_general_parameters().current_health != 0) {
                    GraphicIntelligentLogic IntelligentSystem(level, el);
                    IntelligentSystem.makeMove();
                }
            }
            for (auto &el: level.foragers) {
                if (el->get_general_parameters().current_health != 0) {
                    GraphicForagerLogic ForagerSystem(level, el);
                    ForagerSystem.makeMove();
                }
            }
        }

        std::cout<<"THAT`S ALL\n";

    }
};

#endif
