#include <iostream>
#include <string>

constexpr int MAX_SUGAR = 5;
constexpr int MIN_SUGAR = 0;
constexpr int MIN_TEMP = 0;
constexpr int MAX_TEMP = 99;

class DrinkBuilder {
    private:
        std::string name;
        int sugar = 0;
        int temperature = 0;
        bool withMilk;
    
    public:
        std::string getName() const {
            return name;
        }

        int getSugar() const {
            return sugar;
        }

        int getTemperature() const {
            return temperature;
        }

        bool isWithMilk() const {
            return withMilk;
        }

        DrinkBuilder& setName(std::string name) {
            this->name = name;
            return *this;
        }

        DrinkBuilder& setSugar(int sugar) {
            this->sugar = sugar;
            return *this;
        }

        DrinkBuilder& setTemperature(int temperature) {
            this->temperature = temperature;
            return *this;
        }

        DrinkBuilder& setWithMilk(bool withMilk) {
            this->withMilk = withMilk;
            return *this;
        }

        void print() {
            std::cout << "\nDrink: " << getName() << "\nSugar: " << getSugar() << "\nTemperature: " << getTemperature() << "\nWith milk:" << isWithMilk();
        }
};      

int main() {
    DrinkBuilder builder;
    builder.setName("Tea").setSugar(2).setTemperature(65).setWithMilk(true).print();
}