
#ifndef LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H
#define LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H

#include "Operative control system.h"
#include "DrawSystem.h"

class GraphicOperativeControlSystem : public OperativeControlSystem, public DrawSystem {
public:
    GraphicOperativeControlSystem(Level &lvl, std::shared_ptr<Operative> &operative) :
            OperativeControlSystem(lvl, operative), DrawSystem(lvl) {};

    void takeStep(direction drctn) {
        OperativeControlSystem::take_step(drctn);
        drawDefolt();
    }

    void reloadWeapon(){
        current_operative->reload_weapon();
        drawDefolt();
    }

    void shoot(direction drctn) {
        OperativeControlSystem::shoot(drctn);
        drawDefolt();
    }

    void drawItemsOnCell() {
        DrawSystem::drawInventoryCell(current_operative);
    };

    void drawDefolt() {
        DrawSystem::drawMap();
        DrawSystem::drawInfoCurrentOperative(current_operative);
        DrawSystem::drawInfoEnemy();
    }

    void drawInventory(){
        DrawSystem::drawInventoryOperative(current_operative);
    }

    void takeItem() {
        drawItemsOnCell();
        size_t n;
        std::cin >> n;
        if (std::cin.good()) {
            OperativeControlSystem::take_item(n);
            drawDefolt();
        }
        if (std::cin.eof())
            throw std::runtime_error("Eof");
    }

    void changeWeapon(){
        drawInventoryOperative(current_operative);
        size_t n;
        std::cin >> n;
        if (std::cin.good()) {
            current_operative->set_current_weapon(n);
            drawDefolt();
        }
        if (std::cin.eof())
            throw std::runtime_error("Eof");
    }

    void throwItem() {
        drawInventoryOperative(current_operative);
        size_t n;
        std::cin >> n;
        if (std::cin.good()) {
            OperativeControlSystem::throw_item(n);
            drawDefolt();
        }
        if (std::cin.eof())
            throw std::runtime_error("Eof");
    }

    bool isPoints() {
        for (const auto &el: OperativeControlSystem::lvl.operatives) {
            if (el->get_general_parameters().current_health != 0 &&
                el->get_general_parameters().current_points_time != 0)
                return true;
        }
        return false;
    }

    void setOperative() {
        drawListOperatives();
        size_t n;
        std::cin >> n;
        if (std::cin.good()) {
            if (n > OperativeControlSystem::lvl.operatives.size()) {
                drawDefolt();
                return;
            }
            auto &operative = OperativeControlSystem::lvl.operatives[n - 1];
            if (operative->get_general_parameters().current_health == 0) {
                drawDefolt();
                return;
            }

            OperativeControlSystem::set_operative(operative);
            drawDefolt();
        }
        if (std::cin.eof())
            throw std::runtime_error("Eof");
    }

    void makeMove() {
        drawDefolt();
        std::string command;
        while (isPoints()){
            std::cin>>command;
            if(command == "w")
                takeStep(straight);
            if(command == "s")
                takeStep(back);
            if(command == "d")
                takeStep(right);
            if(command == "a")
                takeStep(left);
            if(command == "sw")
                shoot(straight);
            if(command == "ss")
                shoot(back);
            if(command == "sd")
                shoot(right);
            if(command == "sa")
                shoot(left);
            if(command == "e")
                takeStep(right_straight);
            if(command == "q")
                takeStep(left_straight);
            if(command == "z")
                takeStep(left_back);
            if(command == "c")
                takeStep(right_back);
            if(command == "co")
                setOperative();
            if(command == "b")
                drawItemsOnCell();
            if(command == "i")
                drawInventory();
            if(command == "m")
                drawDefolt();
            if(command == "ti")
                takeItem();
            if(command == "pi")
                throwItem();
            if(command == "cw")
                changeWeapon();
            if(command == "sho")
                DrawSystem::drawListOperatives();
            if(command == "she")
                DrawSystem::drawListEnemy();
            if(std::cin.eof())
                throw std::runtime_error("Eof");
            if(command == "qw")
                break;
            if(command == "se")
                shoot(right_straight);
            if(command == "sq")
                shoot(left_straight);
            if(command == "sz")
                shoot(left_back);
            if(command == "sc")
                shoot(right_back);
            if(command == "r")
                reloadWeapon();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        for(auto& el: OperativeControlSystem::lvl.operatives){
            if(el->get_general_parameters().current_health!=0)
                el->reload_current_time();
        }

    }
};

#endif //LAB4_GRAPHIC_OPERATIVE_CONTROL_SYSTEM_H
