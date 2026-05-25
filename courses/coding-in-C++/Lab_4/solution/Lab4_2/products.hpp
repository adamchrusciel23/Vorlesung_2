/**
 * @file prodcuts.hpp
 * @brief Declares the abstract Product base class.
 */

#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include "Reportable.hpp"
#include <string>

/**
 * @brief Abstact base class for all prodcuts
 */
class Product : public Reportable {
    private:
        int product_id;
        std::string name;
        int weight;
        double temperature;
        bool visual_defect;
    
    public:
    /**
     * @brief Creates a product with common measurable values.
     *
     * @param[in] id Unique product ID
     * @param[in] product_name Combustion/Electric
     * @param[in] product_weight Product weight
     * @param[in] product_temperature Product temperature
     * @param[in] visual_defect True if a visual defect exists
     */
     Product(int id, const std::string &product_name, int product_weight,
            double product_temperature, bool visual_defect);
    
    /**
    * @brief Returns id
    *
    * @return Product ID 
    */
    int get_product_id() const {
        return product_id;
    }

    /**
    * @brief Returns name
    *
    * @return name 
    */
    std::string get_name() const {
        return name;
    }

    /**
    * @brief Returns weight
    *
    * @return weight 
    */
    int get_weigt() const {
        return weight;
    }

    /**
    * @brief Returns temperature
    *
    * @return temperature 
    */
    double get_temperature() const {
        return temperature;
    }

    /**
    * @brief Returns visual_defect
    *
    * @return visual_defect 
    */
    bool get_visual_defect() const {
        return visual_defect;
    }

    std::string report() const override;
};

class Combustion : public Product {
    public:
        Combustion(int id, int product_weight,
            double product_temperature, bool visual_defect) : Product(id, "Combustion Engine", product_weight, product_temperature, visual_defect) { };
};

class Electric : public Product {
    private:
        double voltage;
    public:
        Electric(int id, int product_weight,
            double product_temperature, bool visual_defect, double voltage) : Product(id, "Electric", product_weight, product_temperature, visual_defect), voltage(voltage) { };
};
#endif
