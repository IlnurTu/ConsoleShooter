//
// Created by Ильнур Тухватулин on 11.11.2022.
//

#ifndef LAB4_MAP_H
#define LAB4_MAP_H
#include "Cell.h"

class Map{
private:
    std::vector<std::vector<std::shared_ptr<Cell>>>;
public:
    Map(const std::string&);

    void save(const std::string&);
};





#endif //LAB4_MAP_H
