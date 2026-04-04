#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include <sstream>
#include <iostream>

class Potion : public Item
{
protected:
    int _healAmount;
    bool _isConsumed;

public:
    Potion(const std::string &name, double weight, int value, int healAmount)
        : Item(name, weight, value), _healAmount(healAmount), _isConsumed(false) {}

    int getHealAmount() const { return _healAmount; }
    bool isConsumed() const { return _isConsumed; }

    void use()
    {
        if (!_isConsumed)
        {
            _isConsumed = true;
            std::cout << "Used " << _name << ". Healed " << _healAmount << " HP.\n";
        }
        else
        {
            std::cout << _name << " has already been used.\n";
        }
    }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [W: " << _weight << ", V: " << _value
            << ", HEAL: " << _healAmount << ", USED: " << (_isConsumed ? "yes" : "no") << "]";
        return oss.str();
    }
};

#endif