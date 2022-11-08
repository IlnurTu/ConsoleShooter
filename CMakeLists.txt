cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp headers/Item.h headers/Inventory.h headers/Kit.h headers/Weapon.h "headers/Container of bullets.h" headers/Operative.h headers/Unit.h headers/Forager.h "headers/Base parameters.h" headers/Point.h "headers/Direction enum.h" headers/Wild.h headers/Intelligent.h headers/Rifle.h headers/Gun.h)
