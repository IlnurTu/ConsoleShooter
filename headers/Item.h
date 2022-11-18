#ifndef LAB4_ITEM_H
#define LAB4_ITEM_H
#include <string>

class Item{
protected:
    std::string name;
    unsigned short weight;
public:
    Item(std::string name,unsigned short weight);

    virtual ~Item();

    std::string get_name() const;

    unsigned short get_weight() const;

};

#endif
