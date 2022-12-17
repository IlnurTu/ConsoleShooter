//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_WALL_H
#define LAB4_WALL_H
#include "Cell.h"

class Wall:public Cell{
public:
    Wall(std::string name,unsigned short x,unsigned short y);

    void virtual shoot() override;

    virtual Wall& pushItem(std::shared_ptr<Item>) override;

    virtual std::shared_ptr<Item> extractItem(size_t id) override;

    virtual std::shared_ptr<Item> get_item(size_t id) const override;

    virtual size_t get_count_items() const override;


};

#endif //LAB4_WALL_H
