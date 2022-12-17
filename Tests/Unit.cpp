#include "../headers/Unit.h"
#include "../headers/Wild.h"
#include "../headers/Intelligent.h"
#include "../googletest/googletest/include/gtest/gtest.h"
#include "../headers/Rifle.h"
#include "../headers/Forager.h"
#include "../headers/Operative.h"
#include "../headers/Operative control system.h"
#include "../headers/Map.h"


TEST(Unit, Constructor) {
    std::string name("Name");
    Unit unit(name, 100, 100, 1, 2, 4, 3, 6, 7);
    ASSERT_EQ("Name", unit.get_general_parameters().name);
    ASSERT_EQ(100, unit.get_general_parameters().max_health);
    ASSERT_EQ(100, unit.get_general_parameters().current_health);
    ASSERT_EQ(1, unit.get_general_parameters().points_time_for_step);
    ASSERT_EQ(2, unit.get_general_parameters().viewing_radius);
    ASSERT_EQ(4, unit.get_general_parameters().max_points_time);
    ASSERT_EQ(3, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(6, unit.get_position().x);
    ASSERT_EQ(7, unit.get_position().y);

    ASSERT_ANY_THROW(Unit unitNew("name", 0, 100, 1, 2, 4, 3, 6, 7));
    ASSERT_ANY_THROW(Unit unitNew("name", 3, 100, 1, 2, 4, 3, 6, 7));
}

TEST(Unit, getDamage) {
    Unit unit("Name", 100, 100, 1, 2, 4, 3, 6, 7);
    ASSERT_EQ(50, unit.get_damage(50).get_general_parameters().current_health);
}

TEST(Unit, takeStep) {
    Unit unit("Name", 100, 100, 1, 2, 4, 3, 6, 7);
    unit.take_step(right_straight);
    ASSERT_EQ(7, unit.get_position().x);
    ASSERT_EQ(8, unit.get_position().y);
    ASSERT_EQ(2, unit.get_general_parameters().current_points_time);
}

TEST(Unit, reloadCurrentTime) {
    Unit unit("name", 100, 100, 1, 2, 4, 3, 6, 7);
    unit.reload_current_time();
    ASSERT_EQ(4, unit.get_general_parameters().current_points_time);
}

TEST(Wild, Constuctor) {
    Wild unit("Name", 100, 100, 1, 2, 4, 3, 6, 7, 11, 12);
    ASSERT_EQ("Name", unit.get_general_parameters().name);
    ASSERT_EQ(100, unit.get_general_parameters().max_health);
    ASSERT_EQ(100, unit.get_general_parameters().current_health);
    ASSERT_EQ(1, unit.get_general_parameters().points_time_for_step);
    ASSERT_EQ(2, unit.get_general_parameters().viewing_radius);
    ASSERT_EQ(4, unit.get_general_parameters().max_points_time);
    ASSERT_EQ(3, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(6, unit.get_position().x);
    ASSERT_EQ(7, unit.get_position().y);
    ASSERT_EQ(11, unit.get_damage());
    ASSERT_EQ(12, unit.get_points_time_for_shoot());
}

TEST(Wild, shoot) {
    Wild unit("Name", 100, 100, 1, 2, 4, 3, 6, 7, 11, 1);
    ASSERT_EQ(11, unit.shoot());
    ASSERT_EQ(2, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(11, unit.get_damage());
}

TEST(Intelligent, constructor) {
    std::shared_ptr<Weapon> weapon(new Rifle("Name", 5, 2, 1,
                                             50, 50, 2, 4,2));
    Intelligent unit("Name", 100, 100, 1, 2, 4,
                     3, 6, 7, 11, 1, weapon);

    ASSERT_EQ(weapon, unit.get_current_weapon());
    ASSERT_EQ(10, unit.shoot());
    ASSERT_EQ(1, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(45, unit.get_current_weapon()->get_parameters().current_number_bullets);
}

TEST(Forager, constructor) {
    Forager unit("name", 100, 100, 1, 2, 5,
                 5, 1, 1, 10, 0, Inventory());
    std::shared_ptr<Item> weapon(new Rifle("Name", 5, 2, 1,
                                           50, 50, 2, 4,2));
    unit.push_inventory(weapon);
    ASSERT_EQ(5, unit.get_current_weight());
    unit.pop_inventory(2);
    ASSERT_EQ(5, unit.get_current_weight());
    unit.pop_inventory(1);
    ASSERT_EQ(0, unit.get_current_weight());
    unit.push_inventory(weapon);
    unit.push_inventory(weapon);
    unit.push_inventory(weapon);
    unit.push_inventory(weapon);
    ASSERT_EQ(2, unit.get_count_items());
}

TEST(Operative, Constructor) {
    std::shared_ptr<Weapon> weapon(new Rifle("Name", 5, 2, 1,
                                             50, 50, 2, 4,2));

    Operative unit("Name", 100, 100, 1, 2,
                   5, 5, 2, 3, 2, 2,
                   weapon, 10, 5, Inventory());

    std::shared_ptr<Item> item(new Item("123", 5));
    unit.push_inventory(item);
    unit.set_current_weapon(1);
    ASSERT_EQ(unit.get_current_weapon()->get_name(), "Name");
    std::shared_ptr<Item> bullets(new ContainerBullets("name1", 2, 100, 100, 1));
    unit.pop_inventory(1);
    unit.push_inventory(bullets);
    unit.shoot();
    unit.shoot();
    ASSERT_EQ(1, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(40, unit.get_current_weapon()->get_parameters().current_number_bullets);
    unit.reload_current_time();
    ASSERT_EQ(5, unit.get_general_parameters().current_points_time);
    unit.reload_weapon();
    ASSERT_EQ(1, unit.get_general_parameters().current_points_time);
    ASSERT_EQ(50, unit.get_current_weapon()->get_parameters().current_number_bullets);
    ASSERT_EQ(90,
              std::static_pointer_cast<ContainerBullets>(unit.get_item(1))->get_parameters().current_number_bullets);
}

TEST(Inventory, constructor) {
    Inventory inventory;
    for (int i = 1; i < 100; i++) {
        std::shared_ptr<Item> item1(new Item("a", i));
        inventory.add(item1);
    }
    ASSERT_EQ(99, inventory.getCount());
    ASSERT_EQ(inventory.getItem(99)->get_weight(), 99);
    ASSERT_EQ(inventory.eraseItem(1)->get_weight(), 1);
    ASSERT_EQ(98, inventory.getCount());

}

TEST(OperativeControlSytem, logic) {
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
    std::shared_ptr<Weapon> weapon(new Rifle("Name", 5, 2, 1,
                                             500, 500, 2, 4,2));

    std::shared_ptr<Operative> unit (new Operative("Name", 100, 100, 1, 2,
                   1000, 100, 1, 1, 2, 2,
                   weapon, 10, 5, Inventory()));
    std::shared_ptr<Operative> unit1 (new Operative("Name", 100, 100, 1, 2,
                                                   5, 5, 0, 0, 2, 2,
                                                   weapon, 10, 5, Inventory()));
    std::shared_ptr<Forager> unit2(new Forager("name", 100, 100, 1, 2, 5,
                 5, 0, 1, 10, 0, Inventory()));
    std::shared_ptr<Item> weapon1(new Rifle("Name", 5, 2, 1,
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
    ASSERT_EQ(2,unit->get_position().x);
    ASSERT_EQ(1,unit->get_position().y);
    tmp.shoot(straight);
    ASSERT_EQ(false,map->get_cell(unit->get_position().x,unit->get_position().y)->get_shoot_state());

    unit->push_inventory(weapon);
    tmp.throw_item(1);
    ASSERT_EQ(0,unit->get_count_items());
    ASSERT_EQ(1,map->get_cell(unit->get_position().x,unit->get_position().y)->get_count_items());
    tmp.take_step(back);
    tmp.shoot(left);
    ASSERT_EQ(100,unit1->get_general_parameters().current_health);
    tmp.take_step(straight);
    for(int k = 0;k<10;k++) {
        tmp.shoot(left);
    }
    ASSERT_EQ(0,unit2->get_general_parameters().current_health);
    ASSERT_EQ(1,map->get_cell(0,1)->get_count_items());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}