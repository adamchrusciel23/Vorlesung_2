#include <iostream>
#include <string>

class Shape {
    public:
        virtual ~Shape() {}
        virtual double area() const { return 0.0; }
};

class Circle : public Shape {
    public:
        Circle(double radiant) : radiant(radiant) { }
        double area() override {
            return 2*3.14*this->radiant*this->radiant;
        }
    
    private:
        double radiant;    
};

class Rectangle : public Shape {
    public:
        Rectangle(double width, double lenght) : lenght(lenght), width(width) { }
        double area() override {
            return this->width * this->lenght;
        }    
};

int main(){
    Circle kreis = Circle(1);
    Rectangle rechteck = Rectangle(2,4);
    std::cout << "Rechteck: " << rechteck.area() << std::endl;
    std::cout << "Kreis: "  << kreis.area() << std::endl;
}