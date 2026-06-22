#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "driver.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Vehicle {
    protected: 

        inline static int id_counter = 0;

        int car_id; 
        std::string brand;
        bool available;
        std::vector<std::string> needed_driver_license;
        Driver* driver;

    public:
        Vehicle(const std::string& brand, std::vector<std::string> needed_driver_license) : car_id(++id_counter), brand(brand), available(true), needed_driver_license(needed_driver_license), driver(nullptr) {
            car_id = ++id_counter;
        }
        
        virtual void printInfo() const = 0;

        int getCarId() const {
            return car_id;
        }
        std::string getBrand() const {
            return brand;
        }
        bool isAvailable() const {
            return available;
        }
        std::vector<std::string> getNeededDriverLicense() const {
            return needed_driver_license;
        }
        Driver* getDriver() const {
            return driver;
        }
        void setBrand(std::string& brand) {
            this->brand = brand;
        }
        void setAvailable(bool available) {
            this->available = available;
        }
        void setDriver(Driver* driver) {
            for(auto x : driver->getDriverLicense()) {
                for(auto y : needed_driver_license) {
                    if(x == y) {
                        available = false;
                        this->driver = driver;
                        return;
                    }
                }
            }
            std::cout << "Fahrer hat nicht die benötigte Führerscheinklasse für dieses Fahrzeug\n";
        }
};

class PKW : public Vehicle {
    private:
        double consumption;
    public:
        PKW(const std::string& brand, std::vector<std::string> needed_driver_license, double consumption) : Vehicle(brand, needed_driver_license), consumption(consumption) { }

        void printInfo() const override;
};

class Electric : public Vehicle {
    private:
        double battery_capacity;
    public:
        Electric(const std::string& brand, std::vector<std::string> needed_driver_license, double battery_capacity) : Vehicle(brand, needed_driver_license), battery_capacity(battery_capacity) { }

        void printInfo() const override;
};


#endif