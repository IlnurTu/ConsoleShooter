#ifndef LAB4_CELL_H
#define LAB4_CELL_H
#include "Unit.h"
#include "Inventory.h"


class Cell{
protected:
    std::string name;
    Point coordinate;
    Inventory inventory;
    bool is_transparent;
    bool is_bullet_stop;
    std::shared_ptr<Unit> unit;
public:
    Cell(std::string name,unsigned short x,unsigned short y,bool is_transparent,bool is_bullet_stop,
         Inventory inventory,std::shared_ptr<Unit> unit);

    virtual void shoot() = 0;

    Point get_coordinate() const;

    bool get_shoot_state() const;

    bool get_view_state() const;

    std::shared_ptr<Unit> get_unit() const;

    void set_unit(std::shared_ptr<Unit> unit);

    virtual std::unique_ptr<Item> extractItem(size_t id);

    virtual Cell& pushItem(std::unique_ptr<Item>);

    virtual const std::unique_ptr<Item>& get_item(size_t id) const;

    virtual size_t get_count_items() const;

    std::string get_info() const ;

    virtual char get_character() const = 0;

};

#endif //LAB4_CELL_H
