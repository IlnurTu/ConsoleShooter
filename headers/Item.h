#ifndef LAB4_ITEM_H
#define LAB4_ITEM_H
#include <string>

class Item{
protected:
    std::string Name;
    unsigned short weight;
public:
    Item(std::string,unsigned short);

    virtual ~Item();

    const std::string& get_name() const;

    void set_name(const std::string&);

    void set_weight(unsigned short);

};

#endif
