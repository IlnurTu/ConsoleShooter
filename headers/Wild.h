#ifndef LAB4_WILD_H
#define LAB4_WILD_H
#include "Unit.h"

class Wild: virtual public Unit{
private:
    size_t damage;
protected:
    unsigned int time_shoot;
    unsigned short accuracy;
public:
    Wild(const std::string&);

    Wild(const std::string &name, unsigned short max_health, unsigned short time_step,
         unsigned short viewing_radius, unsigned short max_points_time, unsigned short accuracy,size_t damage,
         unsigned short time_shoot);

    unsigned short getDamage() const;

    unsigned short get_accuracy() const;

    unsigned short get_time_shoot() const;

    void set_time_shoot(unsigned short);

    void set_accuracy(unsigned short);

    void setDamage(unsigned short);

    virtual size_t shoot();

};

#endif //LAB4_WILD_H
