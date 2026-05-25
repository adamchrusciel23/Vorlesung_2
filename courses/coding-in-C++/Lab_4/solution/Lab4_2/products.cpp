/**
 * @file products.cpp
 * @brief Implements the abstract Products base class.
 */

#include "products.hpp"
#include "inspection.hpp"


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

Product::Product(int id, const std::string &product_name, int product_weight,
                 double product_temperature, bool visual_defect)
    : product_id(id), name(product_name), weight(product_weight), 
      temperature(product_temperature), visual_defect(visual_defect) {
    // Der Rumpf bleibt leer, da die Variablen oben in der Liste zugewiesen werden.
}

std::string Product::report() const {
    std::string report_str = "Product: " + get_name() + "\n";
    bool all_passed = true;

    // 1. Weight Check (Beispiel-Grenzwerte: Min 10, Max 1000 — passe diese an deine Aufgabe an!)
    // Wir übergeben *this (das aktuelle Produkt selbst) an den Test
    WeightCheck weight_test(10, 1000); 
    bool weight_passed = weight_test.inspect(*this);
    report_str += " - Weight Check: " + std::string(weight_passed ? "PASS" : "FAIL") + "\n";
    if (!weight_passed) all_passed = false;

    // 2. Temperature Test (Beispiel-Grenzwerte: Min 15.0, Max 80.0 — passe diese an!)
    TemperatureTest temp_test(15.0, 80.0);
    bool temp_passed = temp_test.inspect(*this);
    report_str += " - Temperature Test: " + std::string(temp_passed ? "PASS" : "FAIL") + "\n";
    if (!temp_passed) all_passed = false;

    // 3. Visual Inspection
    VisualInspection visual_test;
    bool visual_passed = visual_test.inspect(*this);
    report_str += " - Visual Inspection: " + std::string(visual_passed ? "PASS" : "FAIL") + "\n";
    if (!visual_passed) all_passed = false;

    // Finale Zeile (genau wie auf dem Screenshot)
    report_str += "\nFinal Result: " + std::string(all_passed ? "APPROVED" : "REJECTED") + "\n";

    return report_str;
}