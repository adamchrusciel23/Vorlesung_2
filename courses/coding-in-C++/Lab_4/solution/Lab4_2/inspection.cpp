/**
 * @file inspection.cpp
 * @brief Implements the abstract Inspection base class.
 */

#include "inspection.hpp"
#include "products.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

std::string Inspection::report() const {
    return get_name() + " | Success rate: " + std::to_string(get_success_rate()) + 
       " | Last Test: " + (get_last_inspection_passed() ? "PASS" : "FAIL") + "\n";
}
bool WeightCheck::inspect(const Product &product) {
    performed_inspections++;
    if(product.get_weigt() > maximum_weight || product.get_weigt() < minimum_weight) {
        last_inspection_passed = false;
        return false;
    }
    else {
        successful_inspections++;
        last_inspection_passed = true;
        return true;
    }
}

bool TemperatureTest::inspect(const Product &product) {
    performed_inspections++;
    if(product.get_temperature() > max_temp || product.get_temperature() < min_temp) {
        last_inspection_passed = false;
        return false;
    }
    else {
        successful_inspections++;
        last_inspection_passed = true;
        return true;
    }
}

bool VisualInspection::inspect(const Product &product) {
    performed_inspections++;
    if(product.get_visual_defect()) {
        last_inspection_passed = false;
        return false;
    }
    else {
        successful_inspections++;
        last_inspection_passed = true;
        return true;
    }
}