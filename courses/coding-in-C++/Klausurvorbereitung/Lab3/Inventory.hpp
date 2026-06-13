#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <string>
#include <vector>

class Inventory {
    private:
        std::vector<std::string> items;

    public:
        Inventory() { };

        void addItem(std::string item);

        void removeItem(std::string item);

        void showItems() const;

        bool searchItem(std::string item) const;
};
#endif