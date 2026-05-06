#pragma once
#include "Product.hpp"

class Combustion : public Product {
public:
    Combustion(int id, int weight, float temperature, bool visual_defect_status);

    void printReport() override;
};