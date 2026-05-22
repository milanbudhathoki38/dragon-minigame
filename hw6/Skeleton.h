#ifndef SKELETON_H
#define SKELETON_H
#include "Enemy.h"
#include <sstream>

class Skeleton : public Enemy

{
protected:
    int _armorRating;

public:
    Skeleton(const std::string &name, int health, int baseDamage, int armorRating)

        : Enemy(name, health, baseDamage), _armorRating(armorRating)
    {
    }

    void takeDamage(int amount) override
    {
        int reduced = amount - _armorRating;
        if (reduced > 0)
        {
            _health -= reduced;
            if (_health < 0)
                _health = 0;
        }
    }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [HP: " << _health << ", DMG: " << _baseDamage
            << ", ARM: " << _armorRating << "]";
        return oss.str();
    }

};

#endif