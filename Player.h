#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>

class Player

{
private:
    std::string _name;
    int _health;
    int _attackPower;

public:
    Player(const std::string &name, int health, int attackPower)
        : _name(name), _health(health), _attackPower(attackPower) {}

    int getAttackPower() const { return _attackPower; }

    void takeDamage(int amount)
    {
        _health -= amount;
        if (_health < 0)
            _health = 0;
    }

    void heal(int amount)
    {
        _health += amount;

        if (_health > 100)
            _health = 100;
    }

    bool isAlive() const { return _health > 0; }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << _name << " [HP: " << _health << ", ATK: " << _attackPower << "]";
        return oss.str();
    }
};

#endif