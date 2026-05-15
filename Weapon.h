#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include <sstream>

class Weapon : public Item

{
protected:
    int _damage;

public:
    Weapon(const std::string &name, double weight, int value, int damage)
        : Item(name, weight, value), _damage(damage) {}

    int getDamage() const { return _damage; }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [W: " << _weight << ", V: " << _value << ", DMG: " << _damage << "]";
        return oss.str();
    }
};

#endif