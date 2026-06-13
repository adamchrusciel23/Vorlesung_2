#include "Inventory.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MAX_ITEMS 10

void Inventory::addItem(std::string item) {
    if (items.size() < MAX_ITEMS) {
        items.push_back(item);
    } else {
        std::cout << "Inventory is full!" << std::endl;
    }
}

void Inventory::removeItem(std::string item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    } else {
        std::cout << "Item not found in inventory!" << std::endl;
    }
}

void Inventory::showItems() const {
    if (items.empty()) {
        std::cout << "Inventory is empty!" << std::endl;
    }
    else {
        for (const auto& item : items) {
            std::cout << "- " << item << "\n";
        }
    }
}

bool Inventory::searchItem(std::string item) const {
    return std::find(items.begin(), items.end(), item) != items.end();
}