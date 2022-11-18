//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_GLASS_H
#define LAB4_GLASS_H
#include "Cell.h"

class Glass:public Cell{
public:
    Glass(std::string name,unsigned short x,unsigned short y,bool is_transparent,bool is_bullet_stop);

    void virtual shoot() override;
};
#endif //LAB4_GLASS_H
