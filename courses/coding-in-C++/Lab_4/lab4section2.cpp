#include <iostream>
#include <string>

virtual class Shape {
    public:
        virtual ~Shape() {}
        virtual double area() const { return 0.0; }
}