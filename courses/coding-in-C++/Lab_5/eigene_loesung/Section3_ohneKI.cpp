#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
void swapt(T& num1, T& num2) {
    std::cout << num1 << " " << num2 <<std::endl;
    T temp = num1;
    num1 = num2;
    num2 = temp;
    std::cout << num1 << " " << num2 <<std::endl;
}

template<typename T>
void print(const std::vector<T> nums) {
    std::cout << "[";
    for(int i = 0; i < nums.size(); i++) {
        if(i == nums.size() - 1) {
            std::cout << nums[i];
        }
        else {
            std::cout << nums[i] << ", ";
        }
        
    }
    std::cout << "]" << std::endl;
}

template<typename T>
T smallest(const std::vector<T> nums) {
    T smallest_var = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] < smallest_var) {
            smallest_var = nums[i];
        }
    }
    return smallest_var;
}

template<typename T, typename U>
void print_report(const std::string& label1, const T value1, const std::string& label2, const U value2) {
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << std::endl;
}

int main() {
    std::vector<int> ganzzahl = {42, 17, 42, 5, 99, 17, 63, 12};
    std::vector<int> ganzzahl2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};

    for(const auto& zahl : ganzzahl) {
        std::cout << zahl << " ";
    }
    std::cout << std::endl;

    std::sort(ganzzahl.begin(), ganzzahl.end());
    print(ganzzahl);

    bool gefunden = false;
    for(const auto& zahl : ganzzahl) {
        if(zahl == 63) {
            std::cout << zahl << std::endl;
            gefunden =  true;
        }
    }
    if(!gefunden) {
        std::cout << "nicht gefunden" << std::endl;
    }

    print(ganzzahl2);
    std::replace(ganzzahl2.begin(), ganzzahl2.end(), -1, 0);
    int anzahl8 = std::count(ganzzahl2.begin(), ganzzahl2.end(), 8);
    print(ganzzahl2);
    std::cout << anzahl8 << "\n";

    for(std::vector<int>::iterator it = ganzzahl.begin(); it != ganzzahl.end(); ++it){
        std::cout << *it << std::endl;
    }
}