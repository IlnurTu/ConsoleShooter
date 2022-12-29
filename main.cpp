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
#include "SFML/Graphics.hpp"
#include <ncurses.h>
#include "headers/Game.h"


int main() {

    try {
        Game application;
        application.run();
    }catch (std::runtime_error& e){
        std::cout<<e.what();
    }

//    for(int i = 1;i<10;i++){
//        for (int j = 1;j<10;j++) {
//            std::cout << "Floor" << " " << i << " " << j << " " << 1 << " " << 0 << "\n";
//            std::cout<<0<<"\n";
//        }
//
//    }

    return 0;
}
