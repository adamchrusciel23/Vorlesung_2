#include <iostream>
#include <string>

class Vector2D{
    
    private:
        double x;
        double y;
    
        public:
        
        Vectro2D(double x, double y) : x(x), y(y){}
        
        double getX(){
            return x;
        }
        
        double getY(){
            return y;
        }
        
        void print(){
            std::cout   << "X: " << x
                        << "Y: " << y << std::enl;
        }
        
}