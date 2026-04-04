#include <iostream>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"
#include "Inventory.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Dragon.h"
#include "Player.h"

// Function for a single battle round between player and enemy
void battleRound(Player &player, Enemy &enemy)

{
    std::cout << player.toString() << " attacks " << enemy.getName() << "!\n";
    enemy.takeDamage(player.getAttackPower());

    if (enemy.isAlive())
    {
        int dmg = enemy.attack();
        std::cout << enemy.getName() << " attacks for " << dmg << " damage!\n";
        player.takeDamage(dmg);
    }
    else
    {
        std::cout << enemy.getName() << " has been defeated!\n";
    }

    std::cout << " " << player.toString() << "\n";
    std::cout << " " << enemy.toString() << "\n\n";
}

int main()
{
    std::cout << " Inventory Test: Polymorphic Storage \n";
    Inventory inv(20.0);

    
    Weapon *sword = new Weapon("Iron Sword", 5.2, 150, 25);
    Potion *potion = new Potion("Health Potion", 0.5, 30, 50);
    Armor *chestplate = new Armor("Iron Chestplate", 12.0, 500, 8, "chest");

   // Add the items to the inventory
    inv.addItem(sword);
    inv.addItem(potion);
    inv.addItem(chestplate);

    inv.printInventory();
    std::cout << "\n";

    std::cout << "Weight Limit Enforcement \n";
    Weapon *heavyWeapon = new Weapon("Giant Axe", 10.0, 500, 50);
    if (!inv.addItem(heavyWeapon))
    {
        std::cout << "Could not add " << heavyWeapon->getName() << " due to weight limit.\n";
        delete heavyWeapon;
    }
    std::cout << "\n";

    std::cout << "=== Remove Item Test ===\n";
    inv.removeItem("Health Potion");
    inv.printInventory();
    std::cout << "\n";

    // Create the player and a dragon enemy
    std::cout << "=== Dragon Combat Test ===\n";
    Player hero("Hero", 100, 15);
    Dragon *drake = new Dragon("Fire Dragon", 120, 20);

    for (int i = 0; i < 3; ++i)
        battleRound(hero, *drake);
    delete drake;
    std::cout << "\n";

    std::cout << " Polymorphic Enemy Combat \n";

    std::vector<Enemy *> enemies;
    enemies.push_back(new Goblin("Goblin", 30, 5, true));
    enemies.push_back(new Skeleton("Skeleton Knight", 50, 8, 5));
    enemies.push_back(new Dragon("Fire Dragon", 100, 15));


// Run combat against each enemy
    for (Enemy *e : enemies)
        battleRound(hero, *e);

// Clean up dynamically allocated enemies
    for (Enemy *e : enemies)
        delete e;
    enemies.clear();

    std::cout << "Final Inventory \n";
    inv.printInventory();
    std::cout << "\n";

    std::cout << "Player Status \n";
    std::cout << hero.toString() << "\n";

    return 0;
}