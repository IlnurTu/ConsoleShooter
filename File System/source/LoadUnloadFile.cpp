#include "../headers/LoadUnloadFile.h"


void LoadStoreSystem::unload_operatives(const std::vector<std::shared_ptr<Operative>> &arr) {
    std::ofstream file("../CONFIG/operatives.txt");
    file << arr.size() << '\n';
    for (const auto &el: arr) {
        file << el->get_info();
    }
}

void LoadStoreSystem::unload_foragers(const std::vector<std::shared_ptr<Forager>> &arr) {
    std::ofstream file("../CONFIG/foragers.txt");
    file << arr.size() << '\n';
    for (const auto &el: arr) {
        file << el->get_info();
    }
}

void LoadStoreSystem::unload_intelligents(const std::vector<std::shared_ptr<Intelligent>> &arr) {
    std::ofstream file("../CONFIG/intelligents.txt");
    file << arr.size() << '\n';
    for (const auto &el: arr) {
        file << el->get_info();
    }
}

void LoadStoreSystem::unload_wilds(const std::vector<std::shared_ptr<Wild>> &arr) {
    std::ofstream file("../CONFIG/wilds.txt");
    file << arr.size() << '\n';
    for (const auto &el: arr) {
        file << el->get_info();
    }
}

void LoadStoreSystem::unload_map(const std::shared_ptr<Map> &map) {
    std::ofstream file("../CONFIG/map.txt");
    file << map->getSizeX() << " " << map->getSizeY() << '\n';
    for (int i = 0; i < map->getSizeY(); i++) {
        for (int j = 0; j < map->getSizeY(); j++) {
            file << map->get_cell(i, j)->get_info();
        }
    }
}

void LoadStoreSystem::unload(Level lvl) {
    unload_operatives(lvl.operatives);
    unload_foragers(lvl.foragers);
    unload_intelligents(lvl.intelligents);
    unload_map(lvl.map);
    unload_wilds(lvl.wilds);
    unload_storage_point(lvl.StoragePoints);
}

void LoadStoreSystem::unload_storage_point(const std::vector<Point> &arr) {
    std::ofstream file("../CONFIG/storage_point.txt");
    file << arr.size() << '\n';
    for (const auto &el: arr) {
        file << el.x << ' ' << el.y << '\n';
    }
}

std::vector<std::shared_ptr<Operative>> LoadStoreSystem::load_operatives() {
    std::ifstream file("../CONFIG/operatives.txt");
    if (!file.is_open()) {
        throw std::runtime_error("error");
    }
    std::vector<std::shared_ptr<Operative>> result;
    size_t countOfOperatives;
    file >> countOfOperatives;
    std::string name;
    unsigned short max_health;
    unsigned short current_health;
    unsigned short points_time_for_step;
    unsigned short viewing_radius;
    unsigned short max_points_time;
    unsigned short current_points_time;
    unsigned short x;
    unsigned short y;
    unsigned short damage_;
    unsigned short points_time_for_shoot_;
    unsigned short max_weight;
    unsigned short current_weight;
    for (int i = 0; i < countOfOperatives; ++i) {
        file >> name;
        file >> max_health;
        file >> current_health;
        file >> points_time_for_step;
        file >> viewing_radius;
        file >> max_points_time;
        file >> current_points_time;
        file >> x;
        file >> y;
        file >> damage_;
        file >> points_time_for_shoot_;
        file >> max_weight;
        file >> current_weight;

        std::unique_ptr<Weapon> currentWeapon = load_weapon(file);
        Inventory inventory = std::move(load_inventory(file));

        std::shared_ptr<Operative> operative(
                new Operative(name, max_health, current_health, points_time_for_step, viewing_radius,
                              max_points_time, current_points_time, x, y, damage_, points_time_for_shoot_,
                              std::move(currentWeapon),
                              max_weight, current_weight, std::move(inventory)));
        result.push_back(operative);
    }
    return result;
}

std::vector<std::shared_ptr<Wild>> LoadStoreSystem::load_wilds() {
    std::ifstream file("../CONFIG/wilds.txt");
    if (!file.is_open()) {
        throw std::runtime_error("error");
    }
    std::vector<std::shared_ptr<Wild>> result;
    size_t countOfOperatives;
    size_t countOfItems;
    file >> countOfOperatives;
    std::string name;
    unsigned short max_health;
    unsigned short current_health;
    unsigned short points_time_for_step;
    unsigned short viewing_radius;
    unsigned short max_points_time;
    unsigned short current_points_time;
    unsigned short x;
    unsigned short y;
    unsigned short damage_;
    unsigned short points_time_for_shoot_;
    for (int i = 0; i < countOfOperatives; ++i) {
        file >> name;
        file >> max_health;
        file >> current_health;
        file >> points_time_for_step;
        file >> viewing_radius;
        file >> max_points_time;
        file >> current_points_time;
        file >> x;
        file >> y;
        file >> damage_;
        file >> points_time_for_shoot_;
        std::shared_ptr<Wild> wild(
                new Wild(name, max_health, current_health, points_time_for_step, viewing_radius,
                         max_points_time, current_points_time, x, y, damage_, points_time_for_shoot_));
        result.push_back(wild);
    }
    return result;
}

std::vector<std::shared_ptr<Intelligent>> LoadStoreSystem::load_intelligents() {
    std::ifstream file("../CONFIG/intelligents.txt");
    if (!file.is_open()) {
        throw std::runtime_error("error");
    }
    std::vector<std::shared_ptr<Intelligent>> result;
    size_t countOfOperatives;
    file >> countOfOperatives;
    std::string name;
    unsigned short max_health;
    unsigned short current_health;
    unsigned short points_time_for_step;
    unsigned short viewing_radius;
    unsigned short max_points_time;
    unsigned short current_points_time;
    unsigned short x;
    unsigned short y;
    unsigned short damage_;
    unsigned short points_time_for_shoot_;
    for (int i = 0; i < countOfOperatives; ++i) {
        file >> name;
        file >> max_health;
        file >> current_health;
        file >> points_time_for_step;
        file >> viewing_radius;
        file >> max_points_time;
        file >> current_points_time;
        file >> x;
        file >> y;
        file >> damage_;
        file >> points_time_for_shoot_;

        std::unique_ptr<Weapon> currentWeapon = std::move(load_weapon(file));

        std::shared_ptr<Intelligent> intelligent(
                new Intelligent(name, max_health, current_health, points_time_for_step, viewing_radius,
                                max_points_time, current_points_time, x, y, damage_, points_time_for_shoot_,
                                std::move(currentWeapon)));
        result.push_back(intelligent);
    }
    return result;
}

std::vector<std::shared_ptr<Forager>> LoadStoreSystem::load_foragers() {
    std::ifstream file("../CONFIG/foragers.txt");
    if (!file.is_open()) {
        throw std::runtime_error("error");
    }
    std::vector<std::shared_ptr<Forager>> result;
    size_t countOfOperatives;
    file >> countOfOperatives;
    std::string name;
    unsigned short max_health;
    unsigned short current_health;
    unsigned short points_time_for_step;
    unsigned short viewing_radius;
    unsigned short max_points_time;
    unsigned short current_points_time;
    unsigned short x;
    unsigned short y;
    unsigned short max_weight;
    unsigned short current_weight;
    for (int i = 0; i < countOfOperatives; ++i) {
        file >> name;
        file >> max_health;
        file >> current_health;
        file >> points_time_for_step;
        file >> viewing_radius;
        file >> max_points_time;
        file >> current_points_time;
        file >> x;
        file >> y;
        file >> max_weight;
        file >> current_weight;

        Inventory inventory = std::move(load_inventory(file));

        std::shared_ptr<Forager> forager(
                new Forager(name, max_health, current_health, points_time_for_step, viewing_radius,
                            max_points_time, current_points_time, x, y,
                            max_weight, current_weight, std::move(inventory)));
        result.push_back(forager);
    }
    return result;
}

std::shared_ptr<Map> LoadStoreSystem::load_map(const std::vector<std::shared_ptr<Operative>> &arrayOperatives,
                                               const std::vector<std::shared_ptr<Forager>> &arrayForagers,
                                               const std::vector<std::shared_ptr<Wild>> &arrayWilds,
                                               const std::vector<std::shared_ptr<Intelligent>> &arrayIntelligents) {
    std::ifstream file("../CONFIG/map.txt");
    size_t sizeX;
    size_t sizeY;
    std::vector<std::vector<std::shared_ptr<Cell>>> map;
    file >> sizeX >> sizeY;
    map.reserve(sizeX);
    for (int i = 0; i < sizeX; i++) {
        map.push_back(std::vector<std::shared_ptr<Cell>>());
        for (int k = 0; k < sizeY; k++) {
            std::string name;
            unsigned short x;
            unsigned short y;
            bool is_transparent;
            bool is_bullet_stop;

            file >> name >> x >> y >> is_transparent >> is_bullet_stop;

            Inventory inventory = std::move(load_inventory(file));

            if (name == "Wall") {
                std::shared_ptr<Wall> cell(new Wall(name, x, y));
                map[i].push_back(cell);
            }
            if (name == "WeakWall") {
                std::shared_ptr<WeakWall> cell(
                        new WeakWall(name, x, y, is_transparent, is_bullet_stop, std::move(inventory), nullptr));
                map[i].push_back(cell);
            }
            if (name == "Glass") {
                std::shared_ptr<Glass> cell(new Glass(name, x, y, is_bullet_stop, std::move(inventory), nullptr));
                map[i].push_back(cell);
            }
            if (name == "Floor") {
                std::shared_ptr<Floor> cell(new Floor(name, x, y, std::move(inventory), nullptr));
                map[i].push_back(cell);
            }
        }
    }
    for (auto el = arrayForagers.begin(); el != arrayForagers.end(); ++el) {
        Point pos = (*el)->get_position();
        if (pos.x >= sizeX || pos.y >= sizeY || map[pos.x][pos.y]->get_unit() != nullptr) {
            throw std::runtime_error("Conflict map with units");
        }
        map[pos.x][pos.y]->set_unit(*el);
    }
    for (auto el = arrayIntelligents.begin(); el != arrayIntelligents.end(); ++el) {
        Point pos = (*el)->get_position();
        if (pos.x >= sizeX || pos.y >= sizeY || map[pos.x][pos.y]->get_unit() != nullptr) {
            throw std::runtime_error("Conflict map with units");
        }
        map[pos.x][pos.y]->set_unit(*el);
    }
    for (auto el = arrayWilds.begin(); el != arrayWilds.end(); ++el) {
        Point pos = (*el)->get_position();
        if (pos.x >= sizeX || pos.y >= sizeY || map[pos.x][pos.y]->get_unit() != nullptr) {
            throw std::runtime_error("Conflict map with units");
        }
        map[pos.x][pos.y]->set_unit(*el);
    }
    for (auto el = arrayOperatives.begin(); el != arrayOperatives.end(); ++el) {
        Point pos = (*el)->get_position();
        if (pos.x >= sizeX || pos.y >= sizeY || map[pos.x][pos.y]->get_unit() != nullptr) {
            throw std::runtime_error("Conflict map with units");
        }
        map[pos.x][pos.y]->set_unit(*el);
    }
    std::shared_ptr<Map> res(new Map(std::move(map), sizeX, sizeY));
    return res;
}

std::vector<Point> LoadStoreSystem::load_storage_point(const std::shared_ptr<Map> &map) {
    std::ifstream file("../CONFIG/storage_point.txt");
    std::vector<Point> res;
    size_t size;
    file >> size;
    for (int i = 0; i < size; ++i) {
        unsigned int x;
        unsigned int y;
        file >> x >> y;
        Point point{x, y};
        res.push_back(point);
    }
    return res;
}

std::unique_ptr<Weapon> LoadStoreSystem::load_weapon(std::ifstream &file) {
    std::string nameCurrentWeapon;
    file >> nameCurrentWeapon;
    std::unique_ptr<Weapon> currentWeapon;
    if (nameCurrentWeapon != "nullptr") {
        if (nameCurrentWeapon == "Gun") {
            unsigned short weight;
            unsigned short damage;
            unsigned short type_bullets;
            unsigned short current_number_bullets;
            unsigned short max_number_bullets;
            unsigned short points_time_for_shoot;
            unsigned short points_time_for_reload;
            unsigned short firing_range;
            file >> weight >> damage >> type_bullets >> current_number_bullets >> max_number_bullets
                 >> points_time_for_shoot
                 >> points_time_for_reload >> points_time_for_reload >> firing_range;
            std::unique_ptr<Gun> item(
                    new Gun(nameCurrentWeapon, weight, damage, type_bullets, current_number_bullets,
                            max_number_bullets,
                            points_time_for_shoot, points_time_for_reload, firing_range));
            currentWeapon = std::move(item);
        }
        if (nameCurrentWeapon == "Rifle") {
            unsigned short weight;
            unsigned short damage;
            unsigned short type_bullets;
            unsigned short current_number_bullets;
            unsigned short max_number_bullets;
            unsigned short points_time_for_shoot;
            unsigned short points_time_for_reload;
            unsigned short firing_range;
            file >> weight >> damage >> type_bullets >> current_number_bullets >> max_number_bullets
                 >> points_time_for_shoot;
            file >> points_time_for_reload >> firing_range;
            std::unique_ptr<Weapon> item(
                    new Rifle(nameCurrentWeapon, weight, damage, type_bullets, current_number_bullets,
                              max_number_bullets,
                              points_time_for_shoot, points_time_for_reload, firing_range));
            currentWeapon = std::move(item);
        } else {
            currentWeapon = nullptr;
        }
    }
    return currentWeapon;
}

Inventory LoadStoreSystem::load_inventory(std::ifstream &file) {
    size_t countOfItems;
    file >> countOfItems;
    Inventory inventory;
    for (int j = 0; j < countOfItems; ++j) {
        std::string nameOfItem;
        unsigned short weight;
        file >> nameOfItem;
        file >> weight;
        if (nameOfItem == "Gun") {
            unsigned short damage;
            unsigned short type_bullets;
            unsigned short current_number_bullets;
            unsigned short max_number_bullets;
            unsigned short points_time_for_shoot;
            unsigned short points_time_for_reload;
            unsigned short firing_range;
            file >> damage >> type_bullets >> current_number_bullets >> max_number_bullets >> points_time_for_shoot
                 >> points_time_for_reload >> firing_range;
            std::unique_ptr<Item> item(
                    new Gun(nameOfItem, weight, damage, type_bullets, current_number_bullets, max_number_bullets,
                            points_time_for_shoot, points_time_for_reload, firing_range));
            inventory.add(std::move(item));
        }
        if (nameOfItem == "Rifle") {
            unsigned short damage;
            unsigned short type_bullets;
            unsigned short current_number_bullets;
            unsigned short max_number_bullets;
            unsigned short points_time_for_shoot;
            unsigned short points_time_for_reload;
            unsigned short firing_range;
            file >> damage >> type_bullets >> current_number_bullets >> max_number_bullets >> points_time_for_shoot
                 >> points_time_for_reload >> points_time_for_reload >> firing_range;
            std::unique_ptr<Item> item(
                    new Rifle(nameOfItem, weight, damage, type_bullets, current_number_bullets, max_number_bullets,
                              points_time_for_shoot, points_time_for_reload, firing_range));
            inventory.add(std::move(item));
        }
        if (nameOfItem == "Kit") {
            unsigned short points_time_for_use;
            unsigned short restored_health;
            file >> points_time_for_use >> restored_health;
            std::unique_ptr<Item> item(
                    new Kit(nameOfItem, weight, points_time_for_use, restored_health));
            inventory.add(std::move(item));
        }

        if (nameOfItem == "ContainerBullets") {
            size_t max_bullets;
            size_t current_bullets;
            unsigned short type;
            file >> max_bullets >> current_bullets >> type;
            std::unique_ptr<Item> item(
                    new ContainerBullets(nameOfItem, weight, max_bullets, current_bullets, type));
            inventory.add(std::move(item));
        }
    }
    return inventory;
}

Level LoadStoreSystem::load() {
    std::vector<std::shared_ptr<Operative>> operatives = load_operatives();
    std::vector<std::shared_ptr<Forager>> foragers = load_foragers();
    std::vector<std::shared_ptr<Intelligent>> intelligents = load_intelligents();
    std::vector<std::shared_ptr<Wild>> wilds = load_wilds();
    std::shared_ptr<Map> map = load_map(operatives, foragers, wilds, intelligents);
    std::vector<Point> storage_point = load_storage_point(map);
    size_t countEnemy = 0;
    size_t countOperative;
    for(const auto& el:foragers){
        if(el->get_general_parameters().current_health != 0)
            ++countEnemy;
    }
    for(const auto& el:intelligents){
        if(el->get_general_parameters().current_health != 0)
            ++countEnemy;
    }
    for(const auto& el:wilds){
        if(el->get_general_parameters().current_health != 0)
            ++countEnemy;
    }
    for(const auto& el:operatives){
        if(el->get_general_parameters().current_health != 0)
            ++countOperative;
    }
    return {operatives, foragers, wilds, intelligents, map, storage_point,countEnemy,countOperative};
}