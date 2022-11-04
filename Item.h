#include <string>

#ifndef LAB4_ITEM_H
#define LAB4_ITEM_H

class Item{
public:
    virtual std::string getName() = 0;
    virtual std::ostream& getInfo(std::ostream&) = 0;
    virtual void use() = 0;
};

#endif
