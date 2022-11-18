#ifndef LAB4_INTELLIGENT_H
#define LAB4_INTELLIGENT_H
#include "Wild.h"
#include "Weapon.h"

class Intelligent:public Wild{
protected:
    std::shared_ptr<Weapon> current_weapon;
public:
    Intelligent(const std::string&);

    Intelligent(const std::string &name, unsigned short max_health, unsigned short time_step,
                unsigned short viewing_radius, unsigned short max_points_time, unsigned short accuracy,
                unsigned short time_shoot);

    Intelligent(const Intelligent&);

    Intelligent(Intelligent&&) noexcept;

    std::shared_ptr<Weapon> get_current_weapon() const;

    std::shared_ptr<Weapon> set_current_weapon(std::shared_ptr<Weapon>);

    virtual size_t shoot() override;
};

#endif
