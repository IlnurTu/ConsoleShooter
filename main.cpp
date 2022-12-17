#include "headers/Unit.h"
#include "headers/Rifle.h"
#include <iostream>
#include "headers/Forager.h"
#include "headers/Rifle.h"
#include "headers/Inventory.h"
#include "headers/MyVector.h"
#include "headers/Map.h"
#include <thread>
#include <chrono>
#include "headers/Operative control system.h"
#include "headers/LoadUnloadFile.h"






int main() {
    std::vector<std::vector<std::shared_ptr<Cell>>> ArrayCells(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(i==2 && j==2){
                std::shared_ptr<Cell> tmp(new Glass("floor", i, j,true, Inventory(), nullptr));
                ArrayCells[i].push_back(tmp);
            }
            else {
                std::shared_ptr<Cell> tmp(new Floor("floor", i, j, Inventory(), nullptr));
                ArrayCells[i].push_back(tmp);
            }
        }
    }
    std::shared_ptr<Map> map(new Map(std::move(ArrayCells), 3, 3));
    std::shared_ptr<Weapon> weapon(new Rifle("Rifle", 5, 2, 1,
                                             500, 500, 2, 4,2));

    std::shared_ptr<Operative> unit (new Operative("Name", 100, 100, 1, 2,
                                                   1000, 100, 1, 1, 2, 2,
                                                   weapon, 10, 5, Inventory()));
    std::shared_ptr<Operative> unit1 (new Operative("Name", 100, 100, 1, 2,
                                                    5, 5, 0, 0, 2, 2,
                                                    weapon, 10, 5, Inventory()));
    std::shared_ptr<Forager> unit2(new Forager("name", 100, 100, 1, 2, 5,
                                               5, 0, 1, 10, 0, Inventory()));
    std::shared_ptr<Item> weapon1(new Rifle("Rifle", 5, 2, 1,
                                            50, 50, 2, 4,2));
    unit2->push_inventory(weapon1);
    map->get_cell(0,1)->set_unit(unit2);
    map->get_cell(1,1)->set_unit(unit);
    map->get_cell(0,0)->set_unit(unit1);
    std::vector<std::shared_ptr<Operative>> operatives;
    operatives.push_back(unit);
    operatives.push_back(unit1);
    std::vector<std::shared_ptr<Forager>> foragers;
    foragers.push_back(unit2);
    std::shared_ptr<Level> lvl(new Level());
    lvl->operatives = operatives;
    lvl->map = map;
    OperativeControlSystem tmp(lvl,unit);
    tmp.shoot(right);
    tmp.take_step(right);
    std::cout<<unit->get_info();
    //LoadStoreSystem::unload_operatives(lvl->operatives);
    std::vector<std::shared_ptr<Operative>> operatives1;
    operatives1 = LoadStoreSystem::load_operatives();
    std::cout<<operatives1[1]->get_item(1)->get_info();

    std::cout<<std::to_string(true);



    return 0;
}
