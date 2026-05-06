#pragma once

class IInspectionReport {
public:
    virtual ~IInspectionReport() {}
    virtual bool checkWeight() = 0;
    virtual bool checkTemperatur() = 0;
    virtual bool checkVisualDefectStatus() = 0;
};