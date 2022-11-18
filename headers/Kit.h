#ifndef LAB4_KIT_H
#define LAB4_KIT_H
#include "Item.h"

class Kit: public Item{
protected:
    unsigned short points_time_for_use;
    unsigned short restored_health;
public:

    Kit(std::string name,unsigned short weight,unsigned short points_time_for_use,unsigned short restored_health);

    unsigned short get_points_time_for_use() const;

    unsigned short get_restored_health() const;

};

#endif //LAB4_KIT_H
