#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <vector>

class Weapon {
    private:
        std::string name;
        int damage;
    
    public:
        Weapon(std::string name, int damage) : name(name), damage(damage) { };

        std::string getName() const {
            return name;
        }

        int getDamage() const {
            return damage;
        }

        void setName(std::string newName) {
            name = newName;
        }
        void setDamage(int newDamage) {
            damage = newDamage;
        }
};
#endif