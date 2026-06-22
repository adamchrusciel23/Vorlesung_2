#include "driver.hpp"
#include "vehicle.hpp"

void Driver::delete_driver_license(const std::string& license) {
    auto it = find(driver_license.begin(), driver_license.end(), license);
    if (it != driver_license.end()) {
        driver_license.erase(it);
    }
    else {
        std::cout << "Der Fahrer besitzt diese Führerscheinklasse nicht\n";
    }
}

void Driver::add_driver_license(const std::string& license) {
    auto it = find(driver_license.begin(), driver_license.end(), license);
    if (it != driver_license.end()) {
        std::cout << "Der Fahrer besitzt diese Führerscheinklasse bereits\n";
    }
    else {
        driver_license.push_back(license);
    }
}