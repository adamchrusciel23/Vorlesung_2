/** 
 * @file Reportable.hpp
 * @brief Declares the Reportable Interface.
 */

#ifndef REPORTABLE_HPP
#define REPORTABLE_HPP

#include <string>

/**
 * @brief Interface for classes that will generate textual ouputs
 */
class Reportable {
    public:
        /**
         * @brief Generate a textual Output.
         * 
         * @return Report as string
         */
        virtual std::string report() const = 0;

        /**
         *@brief Virtual default destructor
         */
        virtual ~Reportable() {};
};

#endif