#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "driver.hpp"
#include <string>
#include <vector>

class Car {
    protected:
        static int car_id;
        int id;
        std::string brand;
        bool available;
        std::vector<std::string> needed_licence;
        Driver* assigned_driver;
    
    public:
        Car(std::string brand, bool available, std::vector<std::string> needed_licence) : brand(brand), available(available), needed_licence(needed_licence), assigned_driver(nullptr) { 
            this->id = car_id;
            car_id++;
        }
        
        virtual Driver* getAssignedDriver() const { 
            return assigned_driver; 
        }
    
        virtual void setAssignedDriver(Driver* driver) {
            this->assigned_driver = driver;
            available = false;
        }

        virtual void printInfo() const = 0;

        virtual ~Car() = default;
};

class Combustion : public Car {
    private:
        std::string type;
        double consumption;

    public:
        Combustion(std::string brand, double consumption, bool available, std::vector<std::string> needed_licence) : Car(brand, available, needed_licence), type("PKW"), consumption(consumption) { }

        void printInfo() const override;
};

class Electric : public Car {
    private:
        std::string type;
        double battery_capacity;

    public:
        Electric(std::string brand, double consumption, bool available, std::vector<std::string> needed_licence) : Car(brand, available, needed_licence), type("Electric"), battery_capacity(battery_capacity) { }

        void printInfo() const override;
};
#endif