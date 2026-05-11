#include <iostream>
#include <string>

class Shape {
    public:
        virtual ~Shape() {}
        virtual double area() const { return 0.0; }
};

class Circle : public Shape {
    private:
        int radiant;
    public:
        Circle(double radiant) : radiant(radiant) { }
        double area() const override {
            return 3.14 * radiant * radiant;
        }
      
};

class Rectangle : public Shape {
    private:
        int lenght;
        int width;
    public:
        Rectangle(double width, double lenght) : lenght(lenght), width(width) { }
        double area() const override {
            return width * lenght;
        }    
};

int main(){
    Circle kreis = Circle(1);
    Rectangle rechteck = Rectangle(2,4);
    std::cout << "Rechteck: " << rechteck.area() << std::endl;
    std::cout << "Kreis: "  << kreis.area() << std::endl;
}