#ifndef LAB4_KIT_H
#define LAB4_KIT_H
#include "Item.h"

struct kit_parameters{
    unsigned short points_time_for_use;
    unsigned short restored_health;
};

class Kit: public Item{
protected:
    kit_parameters parameters;
public:

    Kit(std::string name,unsigned short weight,unsigned short points_time_for_use,unsigned short restored_health);

    kit_parameters get_parameters() const;

    std::string get_info() const override;

};

#endif //LAB4_KIT_H
