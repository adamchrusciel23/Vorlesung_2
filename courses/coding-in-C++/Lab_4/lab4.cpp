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

        Vector2D& operator*(double scalar) {
            this->x *= scalar;
            this->y *= scalar; 
            return *this;
        }
};

int main()
{
    // Part 2
    Vector2D vec1(4, 5);
    Vector2D vec2(1, 9);

    // Part 3
    Vector2D vec3 = vec1 + vec2;
    vec3.print();
    vec1 += vec2;
    vec1 = vec1 * 5;

    // Part 4
    Vector2D vec4(1, 9);

    return 0;
}
