#pragma once
#include "IInspectionReport.hpp"

class Combustion; // Forward Declaration

class InspectionReportCombustion : public IInspectionReport {
private:
    Combustion& c;

public:
    InspectionReportCombustion(Combustion& c);

    bool checkWeight() override;
    bool checkTemperatur() override;
    bool checkVisualDefectStatus() override;
};