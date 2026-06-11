#include "car.hpp"
#include "driver.hpp"
#include <iostream>
#include <string>
#include <vector>

int Car::car_id = 1;
int Driver::driver_id = 1;

void Driver::ausleihen(Car* vehicle) {
    if(lend_car == nullptr && vehicle->getAssignedDriver() == nullptr) {
        lend_car = vehicle;
        vehicle->setAssignedDriver(this);
        std::cout << "Ausleihen war erfolgreich\n";
    }
    else {
        std::cout << "Ausliehen war nicht erfolgreich\n";
    }
}

void Combustion::printInfo() const {
    std::string driver;
    if(assigned_driver == nullptr) {
        driver = "No";
    }
    else {
        driver = assigned_driver->getName();
    }
    
    std::cout   << "ID:             " << id
                << "\nType            " << type 
                << "\nBrand           " << brand
                << "\nConsumption     " << consumption
                << "\nAvailable       " << available
                //<< "\nNeeded_licence  " << needed_licence
                << "\nAssigned Driver " << driver << "\n\n";
}

void Electric::printInfo() const {
    std::cout   << "Type            " << type 
                << "\nBrand           " << brand
                << "\nBattery Capacity     " << battery_capacity
                << "\nAvailable       " << available
                //<< "\nNeeded_licence  " << needed_licence
                << "\nAssigned Driver " << assigned_driver->getName() << "\n\n";
}

int main() {

    std::vector<std::string> fuehrerscheine = {"B"};

    Driver fahrer1 = Driver("Max", fuehrerscheine);
    Combustion PKW1 = Combustion("Volkswagen", 6.5, true, fuehrerscheine);
    Combustion PKW2 = Combustion("Volkswagen", 6.5, true, fuehrerscheine);
    Combustion PKW3 = Combustion("Volkswagen", 6.5, true, fuehrerscheine);

    fahrer1.ausleihen(&PKW1);
    PKW1.printInfo();
    PKW2.printInfo();
    PKW3.printInfo();
    return 0;
}