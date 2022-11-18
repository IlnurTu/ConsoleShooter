//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_WALL_H
#define LAB4_WALL_H
#include "Cell.h"

class Wall:public Cell{
public:
    Wall(unsigned short x,unsigned short y);

    void virtual shoot() override;
};

#endif //LAB4_WALL_H
