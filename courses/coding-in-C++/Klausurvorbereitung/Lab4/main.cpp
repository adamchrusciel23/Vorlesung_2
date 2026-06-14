#include <iostream>
#include <string>
#include "IInspectionReport.hpp"

int main() {
    IInspectionReportElectric electricMotorInspection;
    IInspectionReportCombustion combustionEngineInspection;

    auto electricMotor = Electric(1500, 25.0, false, 12.0);
    auto combustionEngine = Combustion(1800, 90.0, false, 10.0);
    auto faultyElectricMotor = Electric(3500, 25.0, true, 10.0);
    auto faultyCombustionEngine = Combustion(2500, 160.0, true, 20.0);
    auto electricMotor2 = Electric(2000, 50.0, false, 11.5);
    auto faultyCombustionEngine2 = Combustion(1500, 100.0, true, 5.0);

    electricMotorInspection.printReport(&electricMotor);
    electricMotorInspection.printReport(&faultyElectricMotor);
    electricMotorInspection.printReport(&electricMotor2);
    combustionEngineInspection.printReport(&combustionEngine);
    combustionEngineInspection.printReport(&faultyCombustionEngine);
    combustionEngineInspection.printReport(&faultyCombustionEngine2);

    std::cout << "Electric Motor Inspection Success Rate: " << electricMotorInspection.getSuccesRate() * 100 << "%\n";
    std::cout << "Combustion Engine Inspection Success Rate: " << combustionEngineInspection.getSuccesRate() * 100 << "%\n";

    return 0;
}