#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <sstream>

class Enemy

{
protected:
    std::string _name;
    int _health;
    int _baseDamage;

public:
    Enemy(const std::string &name, int health, int baseDamage)
        : _name(name), _health(health), _baseDamage(baseDamage) {}

    virtual int attack() { return _baseDamage; } 

    virtual void takeDamage(int amount)
    {
        _health -= amount;
        if (_health < 0)
            _health = 0;
    }

    bool isAlive() const { return _health > 0; }
    std::string getName() const { return _name; }
    int getHealth() const { return _health; }

    virtual std::string toString() const
    {
        std::ostringstream oss;
        oss << _name << " [HP: " << _health << ", DMG: " << _baseDamage << "]";
        return oss.str();
    }

    virtual ~Enemy() = default;
};

#endif