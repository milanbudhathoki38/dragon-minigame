#ifndef GOBLIN_H
#define GOBLIN_H
#include "Enemy.h"
#include <sstream>

class Goblin : public Enemy
{
protected:
    bool _hasWeapon;

public:
    Goblin(const std::string &name, int health, int baseDamage, bool hasWeapon)
        : Enemy(name, health, baseDamage), _hasWeapon(hasWeapon) {}

    int attack() override
    {
        return _hasWeapon ? _baseDamage * 2 : _baseDamage;
    }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [HP: " << _health << ", DMG: " << _baseDamage
            << ", WEAPON: " << (_hasWeapon ? "yes" : "no") << "]";
        return oss.str();
    }
};

#endif