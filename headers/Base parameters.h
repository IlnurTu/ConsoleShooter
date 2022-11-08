#ifndef LAB4_BASE_PARAMETERS_H
#define LAB4_BASE_PARAMETERS_H
#include <string>
struct base_parameters {
    std::string name;
    unsigned short max_health = 100;
    unsigned short current_health = 100;
    unsigned short time_step = 1;
    unsigned short viewing_radius = 5;
    unsigned short current_points_time = 10;
    unsigned short max_points_time = 10;

    base_parameters(std::string name);

    base_parameters(const std::string &name, unsigned short max_health, unsigned short time_step,
                    unsigned short viewing_radius, unsigned short max_points_time);
};

#endif //LAB4_BASE_PARAMETERS_H
