#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <string>
#include <vector>
#include <memory>

#include "bugHunt_vehicle.hpp"

class AssistanceFeature 
{
    public:
        virtual void evaluate(Vehicle &vehicle) = 0;

        virtual void print_name() const = 0;

        virtual ~AssistanceFeature() = default;
};

class DistanceSensor
{
private:
    std::string position;
    bool active;
    double measured_distance_m;

public:

    DistanceSensor(const std::string &sensor_position,
                   double initial_distance_m);

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator<(const DistanceSensor &other) const;
    bool is_exactly_at_warning_distance(double warning_distance) const;

    void print_info() const;
};

class EmergencyBrakeSystem  : public AssistanceFeature
{
private:
    double critical_distance_m;
    DistanceSensor* front_sensor;

public:
    EmergencyBrakeSystem(double critical_distance, DistanceSensor* front_sensor);

    void evaluate(Vehicle &vehicle) override;

    void print_name() const override {
        std::cout << "EmergencyBrakeSystem" << std::endl;
        return;
    }


};

class LaneKeepingAssist : public AssistanceFeature
{
private:
    double max_allowed_offset_m;
    double correction_angle;

public:
    LaneKeepingAssist(double max_offset, double correction);

    void evaluate(Vehicle &vehicle) override;

    void print_name() const override {
        std::cout << "LaneKeepingAssist" << std::endl;
        return;
    }
};

class AdaptiveCruiseControl : public AssistanceFeature
{
private:
    double target_speed_kmh;
    double minimum_distance_m;
    DistanceSensor* front_sensor;

public:
    AdaptiveCruiseControl(double target_speed,
                          double minimum_distance,
                          DistanceSensor* sensor);

    void evaluate(Vehicle &vehicle) override;

    void print_name() const override {
        std::cout << "AdaptiveCruiseControl" << std::endl;
        return;
    }
};

class ParkingAssistant
{
private:
    std::vector<std::unique_ptr<DistanceSensor>> sensors;
    double warning_distance_m;

public:
    ParkingAssistant(double warning_distance);

    void add_sensor(std::unique_ptr<DistanceSensor> sensor);
    void print_warnings() const;
};

#endif