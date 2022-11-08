#ifndef LAB4_CONTAINER_OF_BULLETS_H
#define LAB4_CONTAINER_OF_BULLETS_H
#include "Item.h"

class ContainerBullets:public Item{
protected:
    size_t current_number_bullets;
    size_t max_number_bullets;
    unsigned short type;
public:
    ContainerBullets(std::string name,unsigned short weight,size_t max_bullets,unsigned short type);

    size_t get_current_number_bullets() const;

    size_t get_max_number_bullets() const;

    unsigned short get_type() const;

    void set_current_number_bullets(size_t);

    void set_max_number_bullets(size_t);

    void set_type(size_t);

    void reload(size_t);
};



#endif //LAB4_CONTAINER_OF_BULLETS_H
