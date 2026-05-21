#include <iostream>
#include <string>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
    std::cout << "swapping " << a << " with " << b << std::endl;

    T value = a;
    a = b;
    b = value;
}

template <typename T, int N>
void print(T (&a)[N]) {
    std::cout << "[";
    for(int i = 0; i < N; i++) {
        std::cout << a[i];
        if(i < (N - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]" <<  std::endl;
}

template <typename T, int N>
T smallest(T (&a)[N]) {
    int smallest_index = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] < a[smallest_index]) {
            smallest_index = i;
        }
    }
    return a[smallest_index];
}

template <typename T, typename U>
void print_data(const std::string& first_label, const T& first, const std::string& second_label, const U& second) {
    std::cout << first_label << ": " << first << " | " << second_label << ": "<< second << std::endl;
}



int main() {
    /*std::cout << "--- Teste Task 1: Emergency Payload Switch ---\n\n";

    // Test 1: Ganzzahlen (int) - z.B. Sensor-IDs oder Fehlercodes
    int codeA = 101;
    int codeB = 404;
    std::cout << "--- Teste INT ---\n";
    swap(codeA, codeB);
    std::cout << "Kontrolle in main -> codeA: " << codeA << ", codeB: " << codeB << "\n\n";

    // Test 2: Fließkommazahlen (double) - z.B. Kalibrierungswerte
    double voltA = 11.1;
    double voltB = 14.8;
    std::cout << "--- Teste DOUBLE ---\n";
    swap(voltA, voltB);
    std::cout << "Kontrolle in main -> voltA: " << voltA << ", voltB: " << voltB << "\n\n";

    // Test 3: Zeichenketten (std::string) - z.B. Payload-Namen
    std::string payloadA = "Kamera_RGB";
    std::string payloadB = "LiDAR_Scanner";
    std::cout << "--- Teste STRING ---\n";
    swap(payloadA, payloadB);
    std::cout << "Kontrolle in main -> payloadA: " << payloadA << ", payloadB: " << payloadB << "\n\n";

    return 0;*/


    /*std::cout << "--- Teste Task 2: Sensor Frame Printer ---\n\n";

    // Test mit Integer-Array (z.B. Fehlercodes)
    int intFrame[] = {12, 15, 18, 21};
    std::cout << "Integer Frame: ";
    print(intFrame, 4);

    // Test mit Double-Array (z.B. GPS-Koordinaten oder Spannungen)
    double doubleFrame[] = {11.1, 14.8, 12.6};
    std::cout << "Double Frame:  ";
    print(doubleFrame, 3);

    // Test mit Character-Array (z.B. Status-Flags)
    char charFrame[] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "Char Frame:    ";
    print(charFrame, 5);
    
    std::cout << "\n";*/



    /*std::cout << "--- Teste Task 3: Weakest Signal Detector ---\n\n";

    // Test mit Integer-Array (z.B. Signalstärken in dBm)
    int intSignals[] = {85, 42, 78, 92, 35, 64};
    int minInt = smallest(intSignals, 6);
    std::cout << "Schwächstes Integer-Signal: " << minInt << "\n";

    // Test mit Double-Array (z.B. Akkuspannungen)
    double doubleVoltages[] = {14.8, 11.2, 12.6, 10.9, 13.1};
    double minDouble = smallest(doubleVoltages, 5);
    std::cout << "Niedrigste Double-Spannung: " << minDouble << "\n\n";*/




    /*std::cout << "--- Teste Task 4: Telemetry Tag Composer ---\n\n";

    // Test 1: Motor-Temperatur (String) und Priorität (Int)
    print_data("Channel", "motor_temp", "Priority", 2);

    // Test 2: GPS-Status (String) und aktuelle Satellitenanzahl (Int)
    print_data("Status", "GPS_Lock", "Satellites", 12);

    // Test 3: Batteriespannung (Double) und Warnungs-Flag (Bool / Text)
    print_data("Voltage", 14.8, "Warning", "LOW_BATTERY");

    std::cout << "\n";*/


    std::cout << "--- Teste Task 5: Fixed-Size Packet Buffer ---\n\n";

    // 1. Test mit einem Integer-Array der Größe 4
    int intFrame[4] = {12, 15, 18, 21};
    
    std::cout << "Integer Array automatisch verarbeiten:\n";
    print(intFrame);        // Gibt das Array aus (ehemals Task 2)
    std::cout << "Kleinstes Element: " << smallest(intFrame) << "\n";    // Findet und druckt das kleinste Element (ehemals Task 3)
    std::cout << "\n";

    // 2. Test mit einem Double-Array der Größe 6
    double doubleFrame[6] = {14.8, 11.2, 12.6, 10.9, 13.1, 15.5};
    
    std::cout << "Double Array automatisch verarbeiten:\n";
    print(doubleFrame);     // Erkennt automatisch Größe 6
    std::cout << "Kleinstes Element: " << smallest(doubleFrame) << "\n"; // Erkennt automatisch Größe 6
    std::cout << "\n";
}