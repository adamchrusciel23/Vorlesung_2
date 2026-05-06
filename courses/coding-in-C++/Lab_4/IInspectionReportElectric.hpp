#pragma once
#include "IInspectionReport.hpp"

class Electric; // Forward Declaration

class InspectionReportElectric : public IInspectionReport {
private:
    Electric& c;

public:
    InspectionReportElectric(Electric& c);

    bool checkWeight() override;
    bool checkTemperatur() override;
    bool checkVisualDefectStatus() override;

    bool checkVoltage();
};