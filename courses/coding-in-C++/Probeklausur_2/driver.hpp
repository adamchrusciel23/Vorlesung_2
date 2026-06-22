#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Driver {
    private:
        std::string name;
        std::vector<std::string> driver_license;
        inline static int id_counter = 0;
        int driver_id;

    public:
        Driver(const std::string& name, std::vector<std::string> driver_license) : driver_id(++id_counter), name(name), driver_license(driver_license) { }

        std::string getName() const {
            return name;
        }
        std::vector<std::string> getDriverLicense() const {
            return driver_license;
        }
        void setName(std::string& name) {
            this->name = name;
        }
        void setDriverLicense(std::vector<std::string>& driver_license) {
            this->driver_license = driver_license;
        }

        void delete_driver_license(const std::string& license);

        void add_driver_license(const std::string& license);
};


#endif
