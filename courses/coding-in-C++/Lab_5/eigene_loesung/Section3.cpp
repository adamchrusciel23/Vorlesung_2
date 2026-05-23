#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
T summe(const std::vector<T>& a) {
    static_assert(!std::is_same<T, bool>::value, "Keine Summe von einem Bool");
    T sum = T();
    for(const T& current_var : a) {
        sum += current_var;
    }
    return sum;
}

template<typename T>
T max(const std::vector<T>& a) {
    T max = a[0];
    for(const T& current_var : a) {
        if(current_var > max){
            max = current_var;
        }
    }
    return max;
}

template<typename T>
T average(const std::vector<T>& a) {
    static_assert(!std::is_same<T, bool>::value, "Keine Summe von einem Bool");
    T sum = T();
    int count = 0;
    for(const T& current_var : a) {
        count++;
    }
    return (summe(a) / count);
}

template<typename T>
void print_report(const std::string& sensor_name, const std::vector<T>& data) {
    std::cout << "=== ANALYSER REPORT: " << sensor_name << " ===\n";
    
    // 1. Raw Data printen
    std::cout << "Raw Data: [ ";
    for(const T& val : data) {
        std::cout << val << " ";
    }
    std::cout << "]\n";
    
    // 2. Metriken ausgeben (ruft deine Funktionen auf)
    std::cout << "Sum:      " << summe(data) << "\n";
    std::cout << "Maximum:  " << max(data) << "\n";
    std::cout << "Average:  " << average(data) << "\n";
    std::cout << "---------------------------------------\n\n";
}

template<typename T, size_t N>
std::vector<T> import(const T (&a)[N]) {
    std::vector<T> data = { };
    for(size_t i = 0; i < N; ++i) {
        data.push_back(a[i]);
    }
    return data;
}

template<>
bool max<bool>(const std::vector<bool>& a) {
    int count = 0;
    int count_true = 0;
    for (const bool val : a) {
        count++;
        if(val) {
            count_true++;
        }
    }
    if(count_true > count/2) {
        return true;
    }
    else {
        return false;
    }
}

template<>
void print_report<bool>(const std::string& sensor_name, const std::vector<bool>& data) {
    std::cout << "=== ANALYSER REPORT (BOOLEAN): " << sensor_name << " ===\n";
    
    std::cout << "Raw Data: [ ";
    for(bool val : data) {
        std::cout << (val ? "true" : "false") << " ";
    }
    std::cout << "]\n";
    
    std::cout << "Maximum:  " << max(data) << "\n";
    std::cout << "---------------------------------------\n\n";
}

int main() {
    std::vector<double> temp = {24.5, 26.8, 29.2, 31.5, 33.1, 32.8, 30.4};
    std::vector<double> voltage = {16.8, 16.5, 16.2, 15.9, 15.7, 15.4, 14.8};
    std::vector<int> vibration = {12, 15, 42, 88, 95, 34, 18, 11};
    std::vector<bool> motor_status = {true, true, true, false, true, true, false, true};
    std::vector<bool> gps = {false, false, true, false, false, true, false};

    print_report("Temperature Sensors (double)", temp);
    print_report("Battery Voltage (double)", voltage);
    print_report("Vibration Scores (int)", vibration);

    int fixed_frame[] = {150, 142, 89, 201, 155};

    // 2. Importieren (C++ findet das 'N = 5' völlig automatisch heraus!)
    std::vector<int> imported_data = import(fixed_frame);

    // 3. Auswerten mit deiner Report-Funktion aus Part A
    print_report("Imported Frame (Part B)", imported_data);

    print_report("Motor Status (bool)", motor_status);
    print_report("GPS Signal (bool)", gps);

    return 0;

}
