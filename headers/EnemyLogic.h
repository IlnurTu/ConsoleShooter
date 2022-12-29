

#ifndef LAB4_ENEMYLOGIC_H
#define LAB4_ENEMYLOGIC_H

#include "Wild Control System.h"
#include "Intelligent Control System.h"
#include "Forager Control Sytem.h"
#include "DrawSystem.h"


class EnemyLogic
        : public WildControlSystem, public IntelligentControlSystem, public ForagerControlSystem, public DrawSystem {
private:
    Level &lvl;

    void stepWild();

    void stepIntelligent();

    void stepForager();

    void shootWild();

    void shootIntelligent();

    void takeItemForager();

    void throwItemsForager();

    void takeWeaponIntelligent();

public:
    EnemyLogic(Level& lvl);

    void makeMoveWilds();

    void makeMoveIntelligents();

    void makeMoveForagers();

};

#endif //LAB4_ENEMYLOGIC_H
