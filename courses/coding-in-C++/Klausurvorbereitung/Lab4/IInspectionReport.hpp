#ifndef IINSPECTIONREPORT_HPP
#define IINSPECTIONREPORT_HPP
#include <iostream>
#include <string>
#include "vehicle.hpp"

class IInspectionReport {
    public:
        virtual void printReport(const Vehicle* vehicle) = 0;
        virtual bool checkWeight(const Vehicle* vehicle) const = 0;
        virtual bool checkTemperatur(const Vehicle* vehicle) const = 0;
        ~IInspectionReport() = default;
        virtual double getSuccesRate() const = 0;
};

class IInspectionReportElectric : public IInspectionReport {
    private: 
        bool lastReportResult;
        int succesfullInspections = 0;
        int failedInspections = 0;

    public:
        void printReport(const Vehicle* vehicle) override;
        bool checkWeight(const Vehicle* vehicle) const override;
        bool checkTemperatur(const Vehicle* vehicle) const override;
        bool checkVoltage(const Electric* vehicle) const;
        double getSuccesRate() const override;
};

class IInspectionReportCombustion : public IInspectionReport {
    private:
        bool lastReportResult;
        int succesfullInspections = 0;
        int failedInspections = 0;

    public:
        void printReport(const Vehicle* vehicle) override;
        bool checkWeight(const Vehicle* vehicle) const override;
        bool checkTemperatur(const Vehicle* vehicle) const override;
        bool checkConsumption(const Combustion* vehicle) const;
        double getSuccesRate() const override;
};
#endif