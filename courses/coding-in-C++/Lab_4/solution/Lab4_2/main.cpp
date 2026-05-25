#include <iostream>
#include <vector>
#include <memory>

#include "products.hpp"
#include "inspection.hpp"

int main() {
    // Wir nutzen std::unique_ptr und einen Vector, um alle Produkte elegant zu verwalten
    std::vector<std::unique_ptr<Product>> pipeline;

    // 1. Zwei Combustion Engines erstellen
    // Parameter: id, weight, temperature, visual_defect
    pipeline.push_back(std::make_unique<Combustion>(101, 500, 45.0, false)); // Sollte PASSEN
    pipeline.push_back(std::make_unique<Combustion>(102, 50, 95.0, true));   // Sollte FAILEN (zu heiß & Defekt)

    // 2. Zwei Electric Engines erstellen
    // Parameter: id, weight, temperature, visual_defect, voltage
    pipeline.push_back(std::make_unique<Electric>(201, 300, 25.0, false, 400.0)); // Sollte PASSEN
    pipeline.push_back(std::make_unique<Electric>(202, 1200, 30.0, false, 230.0)); // Sollte FAILEN (zu schwer)

    std::cout << "========================================\n";
    std::cout << "       PRODUCTION QUALITY REPORT        \n";
    std::cout << "========================================\n\n";

    // Schleife läuft durch alle Produkte und gibt den Live-Report aus
    for (const auto& prod : pipeline) {
        std::cout << prod->report();
        std::cout << "----------------------------------------\n";
    }

    return 0;
}