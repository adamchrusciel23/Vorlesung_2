#include <iostream>
#include <string>
#include <cmath>
#include "Product.hpp"
#include "Combustion.hpp"
#include "Electric.hpp"
#include "IInspectionReport.hpp"
#include "IInspectionReportCombustion.hpp"
#include "IInspectionReportElectric.hpp"

InspectionReportCombustion::InspectionReportCombustion(Combustion& c) : c(c) {}
bool InspectionReportCombustion::checkWeight() {
    if(c.getWeight() < 500 || c.getWeight() > 2000) {
        return false;
    }
    else {
        return true;
    }
}

bool InspectionReportCombustion::checkTemperatur() {
    if(c.getTemperature() > 100 || c.getTemperature() < 0) {
        return false;
    }
    else {
        return true;
    }
}
bool InspectionReportCombustion::checkVisualDefectStatus() {
    if(c.getVisualDefectStatus()){
        return false;
    }
    else {
        return true;
    }
}


InspectionReportElectric::InspectionReportElectric(Electric& c) : c(c){}

bool InspectionReportElectric::checkWeight() {
    if(c.getWeight() < 500 || c.getWeight() > 2000) {
        return false;
    }
    else {
        return true;
    }
}

bool InspectionReportElectric::checkTemperatur() {
    if(c.getTemperature() > 100 || c.getTemperature() < 0) {
        return false;
    }
    else {
        return true;
    }
}

bool InspectionReportElectric::checkVisualDefectStatus() {
    if(c.getVisualDefectStatus()){
        return false;
    }
    else {
        return true;
    }
}

bool InspectionReportElectric::checkVoltage()  {
    if(c.getVoltage() > 12 || c.getVoltage() < 0) {
        return false;
    }
    else {
        return true;
    }
}

Product::Product(int id, std::string name, int weight, float temperature, bool visual_defect_status) : id(id), name(name), weight(weight), temperature(temperature), visual_defect_status(visual_defect_status) {}
int Product::getId() const {
    return id;
}

Product::~Product() {}

std::string Product::getName() const {
    return name;
}

int Product::getWeight() const {
    return weight;
}

float Product::getTemperature() const {
    return temperature;
}

bool Product::getVisualDefectStatus() const {
    return visual_defect_status;
}

Combustion::Combustion(int id, int weight, float temperature, bool visual_defect_status)
    : Product(id, "Combustion Engine", weight, temperature, visual_defect_status) {}
void Combustion::printReport() {
    InspectionReportCombustion report(*this);
    std::cout   << "Product: " << name
                << "Weight Check: " << report.checkWeight()
                << "Temperature Check: " << report.checkTemperatur()
                << "Visual Inspection: " << report.checkVisualDefectStatus() << std::endl;
}


Electric::Electric(int id, int weight, float temperature, bool visual_defect_status, float voltage) : Product(id, "Electric Engine", weight, temperature, visual_defect_status), voltage(voltage) {}

float Electric::getVoltage() const {
    return voltage;
}

void Electric::printReport() {
    InspectionReportElectric report(*this);
    std::cout   << "Product: " << name
                << "Weight Check: " << report.checkWeight()
                << "Temperature Check: " << report.checkTemperatur()
                << "Visual Inspection: " << report.checkVisualDefectStatus()
                << "Voltage Check: " << report.checkVoltage() << std::endl;
}


int main() {
    // 1. Array für Produkte erstellen (Polymorphie über Product-Pointer)
    // Wir erstellen jeweils 2 Objekte (Combustion und Electric)
    Product* products[4];

    // Parameter: id, name (wird intern überschrieben), weight, temp, visual_defect, [voltage]
    products[0] = new Combustion(101, 1200, 85.5f, false);
    products[1] = new Combustion(102, 2500, 110.0f, true); // Sollte FAILen
    
    products[2] = new Electric(201, 800, 45.0f, false, 12.0f);
    products[3] = new Electric(202, 600, 50.0f, false, 15.0f); // Voltage FAIL

    std::cout << "--- QUALITY CONTROL PIPELINE START ---" << std::endl << std::endl;

    // 2. Alle Produkte durchlaufen und Reports drucken
    for (int i = 0; i < 4; i++) {
        // Zugriff über Pointer
        products[i]->printReport();
        std::cout << "--------------------------------------" << std::endl;
    }

    // 3. Speicher aufräumen
    for (int i = 0; i < 4; i++) {
        delete products[i];
    }

    return 0;
}