//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_GLASS_H
#define LAB4_GLASS_H
#include "Cell.h"

class Glass:public Cell{
public:
    Glass(unsigned short x,unsigned short y);

    void virtual shoot() override;
};
#endif //LAB4_GLASS_H
