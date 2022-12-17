//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_SOLID_WALL_H
#define LAB4_SOLID_WALL_H
#include "Cell.h"

class WeakWall:public Cell{
public:
    WeakWall(std::string name,unsigned short x,unsigned short y,bool is_transparent,bool is_bullet_stop,Inventory inventory,std::shared_ptr<Unit> unit);

    void virtual shoot() override;

    virtual std::shared_ptr<Item> get_item(size_t id) const override;

    virtual std::shared_ptr<Item> extractItem(size_t id) override;

    virtual WeakWall& pushItem(std::shared_ptr<Item>) override;

    virtual size_t get_count_items() const override;

};

#endif //LAB4_SOLID_WALL_H
