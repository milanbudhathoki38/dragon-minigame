#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include <sstream>

class Dragon : public Enemy
{
protected:
    bool _fireBreathReady;

public:
    Dragon(const std::string &name, int health, int baseDamage)
        : Enemy(name, health, baseDamage), _fireBreathReady(true) {}

    int attack() override
    {
        if (_fireBreathReady)
        {
            _fireBreathReady = false;
            return _baseDamage * 3;
        }
        else
        {
            _fireBreathReady = true;
            return _baseDamage;
        }
    }

    std::string toString() const override
    {
        std::ostringstream oss;
        oss << _name << " [HP: " << _health
            << ", DMG: " << _baseDamage
            << ", FIRE: " << (_fireBreathReady ? "ready" : "charging") << "]";
        return oss.str();
    }
};

#endif