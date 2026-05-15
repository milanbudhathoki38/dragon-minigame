#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <sstream>

class Item
{
protected:
    std::string _name;
    double _weight;
    int _value;

public:
    Item(const std::string &name, double weight, int value)
        : _name(name), _weight(weight), _value(value) {}

    std::string getName() const { return _name; }
    double getWeight() const { return _weight; }
    int getValue() const { return _value; }

    virtual std::string toString() const
    {
        std::ostringstream oss;
        oss << _name << " [W: " << _weight << ", V: " << _value << "]";
        return oss.str();
    }

    virtual ~Item() = default;
};

#endif