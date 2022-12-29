
#ifndef LAB4_LOADUNLOADFILE_H
#define LAB4_LOADUNLOADFILE_H

#include "Level.h"
#include <fstream>

class LoadStoreSystem {
private:
    static std::unique_ptr<Weapon> load_weapon(std::ifstream&);

    static Inventory load_inventory(std::ifstream&);

    static std::vector<std::shared_ptr<Operative>> load_operatives();

    static std::vector<std::shared_ptr<Forager>> load_foragers();

    static std::vector<std::shared_ptr<Wild>> load_wilds();

    static std::vector<std::shared_ptr<Intelligent>> load_intelligents();

    static std::shared_ptr<Map> load_map(const std::vector<std::shared_ptr<Operative>> &,

                                         const std::vector<std::shared_ptr<Forager>> &,

                                         const std::vector<std::shared_ptr<Wild>> &,

                                         const std::vector<std::shared_ptr<Intelligent>> &);

    static std::vector<Point> load_storage_point(const std::shared_ptr<Map>&);

    static void unload_operatives(const std::vector<std::shared_ptr<Operative>> &);

    static void unload_foragers(const std::vector<std::shared_ptr<Forager>> &);

    static void unload_wilds(const std::vector<std::shared_ptr<Wild>> &);

    static void unload_intelligents(const std::vector<std::shared_ptr<Intelligent>> &);

    static void unload_map(const std::shared_ptr<Map> &);

    static void unload_storage_point(const std::vector<Point> &);

public:
    static void unload(Level lvl);

    static Level load();
};

#endif
