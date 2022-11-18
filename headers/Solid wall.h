//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_SOLID_WALL_H
#define LAB4_SOLID_WALL_H
#include "Cell.h"

class SolidWall:public Cell{
public:
    SolidWall(unsigned short x,unsigned short y);

    void virtual shoot() override;
};

#endif //LAB4_SOLID_WALL_H
