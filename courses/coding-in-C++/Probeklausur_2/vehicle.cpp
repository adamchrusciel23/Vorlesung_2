#include "vehicle.hpp"
#include "driver.hpp"

void PKW::printInfo() const {
    std::string license;
    if(needed_driver_license.empty()) {     
        license = "None";
    } 
    else {
        for(auto x : needed_driver_license) {
            license = license + ", " + x;
        }
    }
    
    std::cout   << "Type:             PKW\n" 
                << "Brand:            " << brand << "\n"
                << "Consumption:      " << consumption << "kWh\n"
                << "Available:        " << (available ? "Yes" : "No") << "\n"
                << "Needed License:   " << license << "\n"
                << "Assigned Driver:  " << (driver ? driver->getName() : "None") << "\n";
}

void Electric::printInfo() const {
    std::string license;
    if(needed_driver_license.empty()) {     
        license = "None";
    } 
    else {
        for(auto x : needed_driver_license) {
        license = license + ", " + x;
        }
    }
                
    std::cout   << "Type:             Electric\n" 
                << "Brand:            " << brand << "\n"
                << "Battery Capacity: " << battery_capacity << "kWh\n"
                << "Available:        " << (available ? "Yes" : "No") << "\n"
                << "Needed License:   " << license << "\n"
                << "Assigned Driver:  " << (driver ? driver->getName() : "None") << "\n";
}