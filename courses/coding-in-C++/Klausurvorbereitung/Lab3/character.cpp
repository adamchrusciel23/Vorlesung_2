#include "character.hpp"
#include <iostream>
#include <string>
#include <vector>

#define MAX_LEVEL 10

void Character::LevelUp() {
    if (level < MAX_LEVEL) {
        level++;
        health += 20;
        weapon.setDamage(weapon.getDamage() + 5);
    } else {
        std::cout << "Maximum level reached!" << std::endl;
    }
}

void Warrior::display() const {
    std::cout << "Name: " << getName() << "\nHealth: " << getHealth() << "\nLevel: " << getLevel() << std::endl;
    std::cout << "Weapon: " << getWeapon().getName() << " (Damage: " << getWeapon().getDamage() << ")" << "Weapon Skill Points: " << getWeaponSkillPoints() <<  std::endl;
    std::cout << "Inventory: ";
    getInventory().showItems();
}

void Mage::display() const {
    std::cout << "Name: " << getName() << "\nHealth: " << getHealth() << "\nLevel: " << getLevel() << std::endl;
    std::cout << "Weapon: " << getWeapon().getName() << " (Damage: " << getWeapon().getDamage() << ")" << "Mana Points: " << getManaPoints() <<  std::endl;
    std::cout << "Inventory: ";
    getInventory().showItems();
}