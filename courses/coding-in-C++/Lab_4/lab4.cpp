#include <iostream>
#include <string>
#include <cmath>

class Vector2D{
    
    private:
        double x;
        double y;
    
        public:
        
        Vector2D(double x, double y) : x(x), y(y) {}
        
        double getX() const {
            return x;
        }
        
        double getY() const {
            return y;
        }
        
        void print() const {
            std::cout   << "X: " << x
                        << "Y: " << y << std::endl;
        }
        
        float getLength() const {
            return sqrt(x*x + y*y);
        }

        float getLength(int precision) const {
            float value = sqrt(x*x + y*y);
            double factor = std::pow(10.0, precision);
            return std::round(value * factor) / factor;
        }

        Vector2D operator+(const Vector2D &vector1) {
            return Vector2D((this->x + vector1.getX()), (this->y + vector1.getY()));
        }
        void operator+=(const Vector2D &vector1) {
            this->x += vector1.getX();
            this->y += vector1.getY();
        }
};