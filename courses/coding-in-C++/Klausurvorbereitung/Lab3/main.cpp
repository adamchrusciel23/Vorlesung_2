#include "character.hpp"
#include "Inventory.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

int main() {
    Inventory inventory;
    inventory.addItem("Health Potion");
    inventory.addItem("Mana Potion");
    inventory.addItem("Sword");

    Weapon sword("Excalibur", 50);

    Warrior* hero = new Warrior("Arthur", 100, inventory, sword, 10);

    hero->display();
    hero->LevelUp();
    hero->display();
    hero->getInventory().removeItem("Health Potion");
    hero->getInventory().addItem("Shield");
    hero->display();

    delete hero;
    return 0;
}