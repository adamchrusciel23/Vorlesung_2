#pragma once
#include "Product.hpp"

class Electric : public Product {
private:
    float voltage;

public:
    Electric(int id, int weight, float temperature, bool visual_defect_status, float voltage);

    float getVoltage() const;
    void printReport() override;
};