#include <iostream>
#include <memory>

template <typename T, typename U>
class Pair{
    private:
        T value1;
        U value2;
    public:
        Pair(T value1, U value2): value1(value1), value2(value2) { };
        T getValue1(){
            return this->value1;
        }
        void setValue1(T value1){
            this->value1 = value1;
        }
};