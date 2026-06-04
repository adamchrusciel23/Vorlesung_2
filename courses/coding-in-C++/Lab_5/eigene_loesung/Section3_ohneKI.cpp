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
void print_label(const std::string& label1, const T value1, const std::string& label2, const U value2) {
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << std::endl;
}

template<typename T>
T average(const std::vector<T> nums) {
    T sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return double((sum / nums.size()));
}

template<>
bool average<bool>(const std::vector<bool> nums) {
    float count = 0;
    for (int i = 0; i< nums.size(); i++) {
        if(nums[i]) {
            count++;
        }
    }
    if (count > float((nums.size() / 2 ))) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
T sum(const std::vector<T> nums) {
    T sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
}

template<typename T>
T max(const std::vector<T> nums) {
    T max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if(max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

template<typename T>
void print_report(const std::vector<T> nums) {
    std::cout << "------------" << "\n";
    std::cout << "RAW DATA: ";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
    std::cout << "SUM: " << sum(nums) << "\n";
    std::cout << "MAX: " << max(nums) << "\n";
    std::cout << "AVERAGE: " << average(nums) << "\n";
}

template<>
void print_report<bool>(const std::vector<bool> nums) {
    std::cout << "------------" << "\n";
    std::cout << "RAW DATA: ";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
    if(average(nums)) {
        std::cout << "Motor was active for most of the test run" << "\n";
    }
    else {
        std::cout << "Motor was inactive for most of the test run" << "\n";
    }
}

int main() {
    std::vector<int> temperature = {23, 24, 26, 29, 31, 30, 28};
    std::vector<double> voltage = {12.6, 12.5, 12.3, 11.9, 11.5, 11.2, 11.1};
    std::vector<double> vibration = {0.02, 0.05, 0.12, 0.45, 0.88, 0.32, 0.08};
    std::vector<bool> motor_active = {false, true, true, true, true, true, false};
    std::vector<bool> gps_lock = {false, false, true, true, true, true, true};


    print_report(temperature);
    print_report(voltage);
    print_report(vibration);
    print_report(motor_active);
}