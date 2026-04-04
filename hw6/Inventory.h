#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <string>
#include <iostream>

class Inventory
{
private:
    std::vector<Item *> _items;
    double _maxWeight;

public:
    Inventory(double maxWeight) : _maxWeight(maxWeight) {}

    ~Inventory()
    {
        for (Item *item : _items)
            delete item; 
    }

    Inventory(const Inventory &other) = delete;
    Inventory &operator=(const Inventory &other) = delete;

    bool addItem(Item *item)
    {
        double totalWeight = 0.0;
        for (Item *i : _items)
            totalWeight += i->getWeight();

        if (totalWeight + item->getWeight() > _maxWeight)
            return false;

        _items.push_back(item);
        return true;
    }

    bool removeItem(const std::string &name)
    {
        for (size_t i = 0; i < _items.size(); ++i)
        {
            if (_items[i]->getName() == name)
            {
                delete _items[i];
                _items.erase(_items.begin() + i);
                return true;
            }
        }
        return false;
    }

    double getTotalWeight() const
    {
        double total = 0.0;
        for (Item *i : _items)
            total += i->getWeight();
        return total;
    }

    int getTotalValue() const
    {
        int total = 0;
        for (Item *i : _items)
            total += i->getValue();
        return total;
    }

    int getCount() const
    {
        return _items.size(); 
    }

    void printInventory() const
    {
        std::cout << "Inventory (" << getCount()
                  << " items, W: " << getTotalWeight()
                  << ", V: " << getTotalValue() << "):\n";

        for (Item *i : _items)
            std::cout << " " << i->toString() << "\n";
    }
};

#endif