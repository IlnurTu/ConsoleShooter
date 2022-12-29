

#include "Application/headers/Game.h"


int main() {

    try {
        Game application;
        application.run();
    }catch (std::runtime_error& e){
        std::cout<<e.what();
    }

    return 0;
}
