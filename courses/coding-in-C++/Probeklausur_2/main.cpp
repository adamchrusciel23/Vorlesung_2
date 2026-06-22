#include "driver.hpp"
#include "vehicle.hpp"

int main() {
    Driver driver1("Max Mustermann", {"B"});
    Driver driver2("Erika Musterfrau", {"C", "D"});
    Driver driver3("John Doe", {});

    PKW car1("VW Golf", {"B"}, 5.5);
    PKW car2("Audi A4", {"B"}, 6.0);
    Electric car3("Tesla Model 3", {"B"}, 75.0);

    car1.setDriver(&driver1);
    car2.setDriver(&driver2);
    car3.setDriver(&driver3);


    car1.printInfo();
    std::cout << "\n";
    car2.printInfo();
    std::cout << "\n";
    car3.printInfo();

    driver2.delete_driver_license("C");
    driver2.add_driver_license("B");

    car2.setDriver(&driver2);
    std::cout << "\n";
    car2.printInfo();

    for(auto x : driver2.getDriverLicense()) {
        std::cout << x << "\n" << std::endl;
    }

    return 0;
}