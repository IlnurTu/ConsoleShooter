//
// Created by Ильнур Тухватулин on 09.11.2022.
//

#ifndef LAB4_WALL_H
#define LAB4_WALL_H

#include "Cell.h"

class Wall : public Cell {
public:
    Wall(std::string name, unsigned short x, unsigned short y);

    void virtual shoot() override;

    virtual Wall &pushItem(std::unique_ptr<Item>) override;

    virtual std::unique_ptr<Item> extractItem(size_t id) override;

    virtual const std::unique_ptr<Item> &get_item(size_t id) const override;

    virtual size_t get_count_items() const override;

    virtual char get_character() const override;


};

#endif //LAB4_WALL_H
