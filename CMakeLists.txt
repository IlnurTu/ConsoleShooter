cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(googletest)
add_executable(test_app Tests/Unit.cpp source/Unit.cpp source/Wild.cpp source/Item.cpp source/Kit.cpp
        "source/Container of bullets.cpp" source/Weapon.cpp source/Rifle.cpp source/Gun.cpp source/Inventory.cpp
        source/Intelligent.cpp source/Forager.cpp source/Operative.cpp source/Cell.cpp source/Wall.cpp source/Glass.cpp source/Floor.cpp "source/Weak wall.cpp" "source/Operative control system.cpp" source/Map.cpp)
target_link_libraries(test_app gtest_main gmock_main)

add_executable(app main.cpp source/Unit.cpp source/Wild.cpp source/Item.cpp source/Kit.cpp
        "source/Container of bullets.cpp" source/Weapon.cpp source/Rifle.cpp source/Gun.cpp source/Inventory.cpp
        source/Intelligent.cpp source/Forager.cpp source/Operative.cpp source/Cell.cpp source/Wall.cpp source/Glass.cpp source/Floor.cpp "source/Weak wall.cpp" "source/Operative control system.cpp" source/Map.cpp source/LoadUnloadFile.cpp "source/Wild Control System.cpp" "source/Forager Control System.cpp" "source/Intelligent Control System.cpp" headers/EnemyLogic.h headers/DrawSystem.h "headers/Graphic Operative Control System.h" "headers/Graphic Logic Forager.h" "headers/Wild Graphic System.h" "headers/Graphic Intelligent System.h")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(app
        sfml-system sfml-window sfml-graphics sfml-audio sfml-network curses)