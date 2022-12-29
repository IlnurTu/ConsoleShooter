#ifndef LAB4_CONTAINER_OF_BULLETS_H
#define LAB4_CONTAINER_OF_BULLETS_H
#include "Item.h"

struct ContainerBullets_parameters{
    size_t current_number_bullets;
    size_t max_number_bullets;
};

class ContainerBullets:public Item{
protected:
    ContainerBullets_parameters parameters;
    unsigned short type;
public:
    ContainerBullets(std::string name,unsigned short weight,size_t max_bullets,size_t current_bullets,unsigned short type);

    ContainerBullets_parameters get_parameters() const;

    unsigned short get_type() const;

    bool reload(size_t);

    std::string get_info() const override;
};



#endif //LAB4_CONTAINER_OF_BULLETS_H
