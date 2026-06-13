#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.hpp"
#include "Weapon.hpp"

class Character {
    private:
        std::string name;
        int health;
        int level;
        Inventory& inventory;
        Weapon weapon;
    
    public:
        Character(std::string name, int health, Inventory& inventory, Weapon weapon) : name(name), health(health), level(1), inventory(inventory), weapon(weapon) { }

        std::string getName() const {
            return name;
        }

        int getHealth() const {
            return health;
        }

        int getLevel() const {
            return level;
        }

        void setName(std::string newName) {
            name = newName;
        }
        
        void setHealth(int newHealth) {
            health = newHealth;
        }

        Inventory& getInventory() const {
            return inventory;
        }

        Weapon getWeapon() const {
            return weapon;
        }

        void setWeapon(const Weapon& newWeapon) {
            weapon = newWeapon;
        }
        

        void LevelUp();
};

class Warrior : public Character {
    private:
        int weaponSkillPoints;

    public:
        Warrior(std::string name, int health, Inventory& inventory, Weapon weapon, int weaponSkillPoints) : Character(name, health, inventory, weapon), weaponSkillPoints(weaponSkillPoints) { }

        int getWeaponSkillPoints() const {
            return weaponSkillPoints;
        }

        void setWeaponSkillPoints(int newWeaponSkillPoints) {
            weaponSkillPoints = newWeaponSkillPoints;
        }
        void display() const;
};

class Mage : public Character {
    private:
        int manaPoints;

    public:
        Mage(std::string name, int health, Inventory& inventory, Weapon weapon, int manaPoints) : Character(name, health, inventory, weapon), manaPoints(manaPoints) { }

        int getManaPoints() const {
            return manaPoints;
        }

        void setManaPoints(int newManaPoints) {
            manaPoints = newManaPoints;
        }
        void display() const;
};
#endif