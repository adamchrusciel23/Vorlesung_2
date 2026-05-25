/**
 * @file inspection.hpp
 * @brief Creates an abstract inspection class
 */

#ifndef INSPECTION_HPP
#define INSPECTION_HPP

#include "Reportable.hpp"
#include <string>

/**
 * @brief Constroctur of abstract class Inspection
 *
 * Inspection has attributes for statistics and defines common behavior
 */
class Product;
class Inspection : public Reportable {
    protected:
        double performed_inspections;
        double successful_inspections;
        bool last_inspection_passed;

    public:
        /**
         *@brief Creates an Inspection with emty attributes
        */
        Inspection() : performed_inspections(0), successful_inspections(0), last_inspection_passed(false) { };

        /**
         * @brief Returns the performed inspections.
         *
         * @return performed inspections
         */
        int get_performed_inspections() const {
            return performed_inspections;
        }

        /**
         * @brief Returns the succesful inspections.
         *
         * @return succesful inspections
         */
        int get_successful_inspections() const {
            return successful_inspections;
        }

        /**
         * @brief Returns if the last inspection was succesful.
         *
         * @return inspection passed
         */
        bool get_last_inspection_passed() const {
            return last_inspection_passed;
        }

        /**
         * @brief Returns the name
         *
         * @return name
         */
        virtual std::string get_name() const = 0;

        /**
         * @brief Does an Inspection
         *
         * @return true for passed an false for failed
         */
        virtual bool inspect(const Product &product) = 0;

        /**
         * @brief Calculates the success rate
         *
         * @return succes rate 
         */
        double get_success_rate() const {
            return (successful_inspections / performed_inspections);
        }

        /**
         * @brief Generates an inspection report.
         *
         * @return Inspection report as string
         */
        std::string report() const override;

        /**
         * @brief Virtual default destructor for polymorphic inspection usage.
         */
        virtual ~Inspection() = default;
 };

class WeightCheck : public Inspection {
    private:
        int minimum_weight;
        int maximum_weight;
    public:
        /**
         * @brief Constroctur of the class WeigtCheck
         * 
         * @param[in] minimum_weight Minimum allowed Weight
         * @param[in] maximum_weight Maximum allowed Weight
         */
        WeightCheck(int minimum_weight, int maximum_weight) : minimum_weight(minimum_weight), maximum_weight(maximum_weight) { };

        /**
         * @brief Returns the name
         *
         * @return name
         */
        std::string get_name() const override {
            return "Weight Check";
        }

        /**
         * @brief Does an Inspection
         *
         * @return true for passed an false for failed
         */
        virtual bool inspect(const Product &product) override;
};

class TemperatureTest : public Inspection {
    private:
        double max_temp;
        double min_temp;
    public:
        /**
         * @brief Constroctur of the class TemperatureTest
         * 
         * @param[in] max_temp Max allowed temp
         * @param[in] maximum_weight Min allowed temp
         */
        TemperatureTest(double min_temp, double max_temp) : min_temp(min_temp), max_temp(max_temp) { };

        /**
         * @brief Returns the name
         *
         * @return name
         */
        std::string get_name() const override {
            return "Temperature Check";
        }

        /**
         * @brief Does an Inspection
         *
         * @return true for passed an false for failed
         */
        virtual bool inspect(const Product &product) override;

};

class VisualInspection : public Inspection {
    public:
        /**
         * @brief Returns the name
         *
         * @return name
         */
        std::string get_name() const override {
            return "Visual Inspection";
        }

        /**
         * @brief Does an Inspection
         *
         * @return true for passed an false for failed
         */
        virtual bool inspect(const Product &product) override;

};
#endif