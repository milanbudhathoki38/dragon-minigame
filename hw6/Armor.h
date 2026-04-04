#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include <sstream>

class Armor : public Item

{
protected:
    int _defense;
    std::string _slot;

public:
    Armor(const std::string &name, double weight, int value, int defense, const std::string &slot)
        : Item(name, weight, value), _defense(defense), _slot(slot) {}

    int getDefense() const { return _defense; }
    std::string getSlot() const { return _slot; }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [W: " << _weight << ", V: " << _value
            << ", DEF: " << _defense << ", SLOT: " << _slot << "]";
        return oss.str();
    }
};

#endif