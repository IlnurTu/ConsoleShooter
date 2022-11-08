#ifndef LAB4_KIT_H
#define LAB4_KIT_H
#include "Item.h"

class Kit: public Item{
protected:
    unsigned short time_use;
    unsigned short restored_health;
public:
    Kit();

    Kit(std::string name,unsigned short weight,unsigned short time_use,unsigned short restored_health);

    unsigned short get_time_use() const;

    unsigned short get_restored_health() const;

    void set_time_use(unsigned short);

    void set_restored_health(unsigned short);

};

#endif //LAB4_KIT_H
