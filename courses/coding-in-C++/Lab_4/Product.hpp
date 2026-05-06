#pragma once
#include <string>

class Product {
protected:
    int id;
    std::string name;
    int weight;
    float temperature;
    bool visual_defect_status;

public:
    Product(int id, std::string name, int weight, float temperature, bool visual_defect_status);
    virtual ~Product();

    int getId() const;
    std::string getName() const;
    int getWeight() const;
    float getTemperature() const;
    bool getVisualDefectStatus() const;

    virtual void printReport() = 0;
};