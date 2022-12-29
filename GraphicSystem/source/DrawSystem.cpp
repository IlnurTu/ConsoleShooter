#include "../headers/DrawSystem.h"

DrawSystem::DrawSystem(Level &lvl) : lvl(lvl) {};

void DrawSystem::drawMap() {
    system("clear");
    std::vector<std::string> result;
    for (int i = 0; i < lvl.map->getSizeX(); i++) {
        std::string line;
        for (int j = 0; j < lvl.map->getSizeY(); ++j) {
            line += lvl.map->get_cell(j, i)->get_character();
        }
        line += '\n';
        result.push_back(line);
    }
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[result.size() - i - 1];
};

void DrawSystem::drawInventoryOperative(const std::shared_ptr<Operative> &operative) {
    if (operative->get_count_items() == 0)
        std::cout << "EMPTY INVENTORY\n";
    std::string result;
    for (int i = 0; i < operative->get_count_items(); ++i) {
        std::string line;
        line = std::to_string(i + 1) + ". " + operative->get_item(i + 1)->get_name() + "\n";
        result += line;
    }
    std::cout << result;
};

void DrawSystem::drawInfoCurrentOperative(const std::shared_ptr<Operative> &operative) {
    std::string result;
    result += operative->get_general_parameters().name + " Health: " +
              std::to_string(operative->get_general_parameters().current_health) +
              " Points of time: " + std::to_string(operative->get_general_parameters().current_points_time) +
              " Weapon: " +
              operative->get_current_weapon()->get_name() + " " +
              std::to_string(operative->get_current_weapon()->get_parameters().current_number_bullets) +
              "/" + std::to_string(operative->get_current_weapon()->get_parameters().max_number_bullets) + "\n";
    std::cout << result;
}

void DrawSystem::drawInfoEnemy() {
    std::cout << "Count alive enemy: " << lvl.countEnemy << "\n";
}

void DrawSystem::drawListOperatives() {
    system("clear");
    std::string result;
    for (int i = 0; i < lvl.operatives.size(); ++i) {
        std::string line;
        line += std::to_string(i + 1) + ". " + lvl.operatives[i]->get_general_parameters().name + " Health: " +
                std::to_string(lvl.operatives[i]->get_general_parameters().current_health) + " Points: "
                + std::to_string(lvl.operatives[i]->get_general_parameters().current_points_time) + "\n";
        result += line;
    }
    std::cout << result;
}

void DrawSystem::drawListEnemy() {
    system("clear");
    std::string result;
    for (int i = 0; i < lvl.foragers.size(); ++i) {
        std::string line;
        line += std::to_string(i + 1) + ". " + lvl.foragers[i]->get_general_parameters().name + " Health: " +
                std::to_string(lvl.foragers[i]->get_general_parameters().current_health) + "\n";
        result += line;
    }
    for (int i = 0; i < lvl.wilds.size(); ++i) {
        std::string line;
        line += std::to_string(i + 1) + ". " + lvl.wilds[i]->get_general_parameters().name + " Health: " +
                std::to_string(lvl.wilds[i]->get_general_parameters().current_health) + "\n";
        result += line;
    }
    for (int i = 0; i < lvl.intelligents.size(); ++i) {
        std::string line;
        line += std::to_string(i + 1) + ". " + lvl.intelligents[i]->get_general_parameters().name + " Health: " +
                std::to_string(lvl.intelligents[i]->get_general_parameters().current_health) + "\n";
        result += line;
    }
    std::cout << result;
};

void DrawSystem::drawInventoryCell(const std::shared_ptr<Operative> &operative) {
    std::string result;
    auto cell = lvl.map->get_cell(operative->get_position().x, operative->get_position().y);
    if (cell->get_count_items() == 0) {
        std::cout << "Empty cell\n";
        return;
    }
    for (int i = 0; i < cell->get_count_items(); ++i) {
        std::string line;
        line = std::to_string(i + 1) + ". " + cell->get_item(i + 1)->get_name() + "\n";
        result += line;
    }
    std::cout << result;
}

