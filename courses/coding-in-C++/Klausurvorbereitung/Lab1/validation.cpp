#define MAX_AGE 125
#define MIN_AGE 0

#include <iostream>
#include <string>
#include <limits>

namespace validation
{
    bool isAdult(int age) {
        if (age >= 18) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isSenior(int age) {
        if(age >= 65) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    int age = 0;
    std::cout << "Please enter your age: ";
    while (!(std::cin >> age) || age < MIN_AGE || age > MAX_AGE) {
        std::cout << "Invalid input! Please enter a valid age (0-125): ";
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\nYour are " << age << " years old.\n";
    if(validation::isAdult(age)) {
        if(validation::isSenior(age)) {
            std::cout << "That means that you are a senior citizen.\n";
        }
        else {
            std::cout << "That means that your are an adult.\n";
        }
    }
    else {
        std::cout << "That means that your are still a kid or teenager.\n";
    }
}