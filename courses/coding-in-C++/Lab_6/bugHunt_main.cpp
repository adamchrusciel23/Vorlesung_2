#include <iostream>

#include "bugHunt_vehicle.hpp"
#include "bugHunt_assistance_system.hpp"

int main()
{
    Vehicle ego_vehicle("Vector X1");

    auto front_sensor = std::make_unique<DistanceSensor>("front", 25.0);
    auto rear_sensor = std::make_unique<DistanceSensor>("rear", 1.2);
    auto left_sensor = std::make_unique<DistanceSensor>("left", 0.8);
    auto right_sensor = std::make_unique<DistanceSensor>("right", 3.0);

    ParkingAssistant parking_assistant(1.5);

    std::vector<std::unique_ptr<AssistanceFeature>> assistenten;
    assistenten.push_back(std::make_unique<EmergencyBrakeSystem>(10.0, front_sensor.get()));
    assistenten.push_back(std::make_unique<LaneKeepingAssist>(0.4, 5.0));
    assistenten.push_back(std::make_unique<AdaptiveCruiseControl>(80.0, 15.0, front_sensor.get()));


    parking_assistant.add_sensor(std::move(rear_sensor));
    parking_assistant.add_sensor(std::move(left_sensor));
    parking_assistant.add_sensor(std::move(right_sensor));

    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle.print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle.accelerate(50.0);
    ego_vehicle.print_status();

    std::cout << "--- Adaptive cruise control test ---\n";
    front_sensor->set_distance(12.0);
    for(const auto &assist : assistenten) {
        assist->print_name();
        assist->evaluate(ego_vehicle);
    }
    ego_vehicle.print_status();

    std::cout << "--- Emergency brake system test ---\n";
    front_sensor->set_distance(25.0);
    for(const auto &assist : assistenten) {
        assist->print_name();
        assist->evaluate(ego_vehicle);
    }
    ego_vehicle.print_status();

    std::cout << "--- Lane keeping assist test ---\n";
    ego_vehicle.update_lane_offset(0.7);
    for(const auto &assist : assistenten) {
        assist->print_name();
        assist->evaluate(ego_vehicle);
    }
    ego_vehicle.print_status();

    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();

    std::cout << "--- Manual braking test ---\n";
    ego_vehicle.brake(100.0);
    ego_vehicle.print_status();

    return 0;
}