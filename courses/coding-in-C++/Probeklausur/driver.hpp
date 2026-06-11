#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include <vector>

class Car;

class Driver {
    private:
        static int driver_id;
        int id;
        std::string name;
        std::vector<std::string> fuehrerscheine;
        Car* lend_car;
    
    public:
        Driver(std::string name, std::vector<std::string> fuehrerscheine) : name(name), fuehrerscheine(fuehrerscheine), lend_car(nullptr) {
            this->id = driver_id;
            driver_id++;
        }

        void ausleihen(Car* vehicle);

        std::string getName() const { return name; }
};
#endif