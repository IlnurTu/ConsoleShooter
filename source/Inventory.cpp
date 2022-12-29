#include "../headers/Inventory.h"

Inventory::Inventory(){};


Inventory::Inventory(Inventory &&el) noexcept: arr(std::move(el.arr)) {}

Inventory &Inventory::operator=(Inventory inventory) {
    arr = std::move(inventory.arr);
}

Inventory &Inventory::add(std::unique_ptr<Item> item) {
    arr.push_back(std::move(item));
    return *this;
}

size_t Inventory::getCount() const {
    return arr.size();
}

size_t Inventory::getWeight() const {
    size_t result = 0;
    for (auto &el: arr) {
        result += el->get_weight();
    }
    return result;
}

std::unique_ptr<Item> Inventory::eraseItem(size_t id) {
    if (arr.size() < id) {
        return nullptr;
    }
    auto tmp = this->getItem(id).release();
    arr.erase(arr.begin() + id - 1);
    return std::unique_ptr<Item>(tmp);
}

const std::unique_ptr<Item>& Inventory::getItem(size_t id)const{
    if(this->getCount()<id)
        return nullptr;
    return arr.at(id - 1);
}

std::unique_ptr<Item>& Inventory::getItem(size_t id){
    return arr.at(id - 1);
}

Inventory::ConstIterator Inventory::cbegin() const {
    return arr.cbegin();
}

Inventory::ConstIterator Inventory::cend() const {
    return arr.cend();
}

std::string Inventory::get_info() const {
    std::string result;
    result += std::to_string(getCount()) + "\n";
    auto iter = this->cbegin();
    for (; iter != this->cend(); ++iter) {
        result+=(*iter)->get_info();
    }
    return result;
}
