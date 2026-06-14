#include <iostream>
#include <string>
#include "IInspectionReport.hpp"

#define MAX_WEIGHT_ELECTRIC 3000
#define MIN_WEIGHT_ELECTRIC 1000
#define MAX_WEIGHT_COMBUSTION 2000
#define MIN_WEIGHT_COMBUSTION 500
#define MAX_TEMPERATURE_ELECTRIC 100
#define MIN_TEMPERATURE_ELECTRIC 0
#define MAX_TEMPERATURE_COMBUSTION 150
#define MIN_TEMPERATURE_COMBUSTION 0
#define MAX_VOLTAGE 12
#define MIN_VOLTAGE 11
#define MAX_CONSUMPTION 15
#define MIN_CONSUMPTION 0

bool IInspectionReportElectric::checkWeight(const Vehicle* vehicle) const {
    return (vehicle->getWeight() >= MIN_WEIGHT_ELECTRIC && vehicle->getWeight() <= MAX_WEIGHT_ELECTRIC);
}
bool IInspectionReportElectric::checkTemperatur(const Vehicle* vehicle) const {
    return (vehicle->getTemperature() >= MIN_TEMPERATURE_ELECTRIC && vehicle->getTemperature() <= MAX_TEMPERATURE_ELECTRIC);
}
bool IInspectionReportElectric::checkVoltage(const Electric* vehicle) const {
    return (vehicle->getVoltage() >= MIN_VOLTAGE && vehicle->getVoltage() <= MAX_VOLTAGE);
}
bool IInspectionReportCombustion::checkWeight(const Vehicle* vehicle) const {
    return (vehicle->getWeight() >= MIN_WEIGHT_COMBUSTION && vehicle->getWeight() <= MAX_WEIGHT_COMBUSTION);
}
bool IInspectionReportCombustion::checkTemperatur(const Vehicle* vehicle) const {
    return (vehicle->getTemperature() >= MIN_TEMPERATURE_COMBUSTION && vehicle->getTemperature() <= MAX_TEMPERATURE_COMBUSTION);
}
bool IInspectionReportCombustion::checkConsumption(const Combustion* vehicle) const {
    return (vehicle->getConsumption() >= MIN_CONSUMPTION && vehicle->getConsumption() <= MAX_CONSUMPTION);
}

double IInspectionReportElectric::getSuccesRate() const {
    int totalInspections = succesfullInspections + failedInspections;
    return totalInspections > 0 ? (double)succesfullInspections / totalInspections : 0.0;
}

double IInspectionReportCombustion::getSuccesRate() const {
    int totalInspections = succesfullInspections + failedInspections;
    return totalInspections > 0 ? (double)succesfullInspections / totalInspections : 0.0;
}
void IInspectionReportElectric::printReport(const Vehicle* vehicle) {
    const Electric* electric = dynamic_cast<const Electric*>(vehicle);
    std::cout   << "Product: Electric Motor\n"
                << "- Weight Check: " << (checkWeight(vehicle) ? "PASS" : "FAIL") << "\n"
                << "- Temperature Test: " << (checkTemperatur(vehicle) ? "PASS" : "FAIL") << "\n"
                << "- Visual Inspection: " << (electric->getVisualDefectStatus() ? "FAIL" : "PASS") << "\n"
                << "- Voltage Test: " << (checkVoltage(electric) ? "PASS" : "FAIL") << "\n\n"
                << " Final Result: " << (checkWeight(vehicle) && checkTemperatur(vehicle) && !electric->getVisualDefectStatus() && checkVoltage(electric) ? "APPROVED" : "REJECTED") << "\n";
                if(checkWeight(vehicle) && checkTemperatur(vehicle) && !electric->getVisualDefectStatus() && checkVoltage(electric)) {
                    succesfullInspections++;
                    lastReportResult = true;
                } else {
                    failedInspections++;
                    lastReportResult = false;
                }
}

void IInspectionReportCombustion::printReport(const Vehicle* vehicle) {
    const Combustion* combustion = dynamic_cast<const Combustion*>(vehicle);
    std::cout   << "Product: Combustion Engine\n"
                << "- Weight Check: " << (checkWeight(vehicle) ? "PASS" : "FAIL") << "\n"
                << "- Temperature Test: " << (checkTemperatur(vehicle) ? "PASS" : "FAIL") << "\n"
                << "- Visual Inspection: " << (combustion->getVisualDefectStatus() ? "FAIL" : "PASS") << "\n"
                << "- Consumption Test: " << (checkConsumption(combustion) ? "PASS" : "FAIL") << "\n\n"
                << " Final Result: " << (checkWeight(vehicle) && checkTemperatur(vehicle) && !combustion->getVisualDefectStatus() && checkConsumption(combustion) ? "APPROVED" : "REJECTED") << "\n";
                if(checkWeight(vehicle) && checkTemperatur(vehicle) && !combustion->getVisualDefectStatus() && checkConsumption(combustion)) {
                    succesfullInspections++;
                    lastReportResult = true;
                } else {
                    failedInspections++;
                    lastReportResult = false;
                }
}

