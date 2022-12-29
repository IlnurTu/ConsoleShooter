cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(googletest)
add_executable(test_app Tests/Unit.cpp Units/source/Unit.cpp Units/source/Wild.cpp Items/source/Item.cpp Items/source/Kit.cpp
        "Items/source/Container of bullets.cpp" Items/source/Weapon.cpp Items/source/Rifle.cpp Items/source/Gun.cpp Items/source/Inventory.cpp
        Units/source/Intelligent.cpp Units/source/Forager.cpp Units/source/Operative.cpp Map/source/Cell.cpp Map/source/Wall.cpp Map/source/Glass.cpp Map/source/Floor.cpp "Map/source/Weak wall.cpp" "Control System/source/Operative control system.cpp" Map/source/Map.cpp)
target_link_libraries(test_app gtest_main gmock_main)

add_executable(app main.cpp Units/source/Unit.cpp Units/source/Wild.cpp Items/source/Item.cpp Items/source/Kit.cpp
        "Items/source/Container of bullets.cpp" Items/source/Weapon.cpp Items/source/Rifle.cpp Items/source/Gun.cpp Items/source/Inventory.cpp
        Units/source/Intelligent.cpp Units/source/Forager.cpp Units/source/Operative.cpp Map/source/Cell.cpp Map/source/Wall.cpp Map/source/Glass.cpp Map/source/Floor.cpp "Map/source/Weak wall.cpp" "Control System/source/Operative control system.cpp" Map/source/Map.cpp "File System/source/LoadUnloadFile.cpp" "Control System/source/Wild Control System.cpp" "Control System/source/Forager Control System.cpp" "Control System/source/Intelligent Control System.cpp" GraphicSystem/headers/DrawSystem.h "GraphicSystem/headers/Graphic Operative Control System.h" "GraphicSystem/headers/Graphic Logic Forager.h" "GraphicSystem/headers/Wild Graphic System.h" "GraphicSystem/headers/Graphic Intelligent System.h" Application/source/Game.cpp GraphicSystem/source/DrawSystem.cpp "GraphicSystem/source/Graphic Intelligent System.cpp" "GraphicSystem/source/Graphic Logic Forager.cpp" "GraphicSystem/source/Graphic Operative Control.cpp" "GraphicSystem/source/Wild Graphic System.cpp")
