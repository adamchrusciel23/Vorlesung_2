#include <iostream>
#include <string>
#include <cmath>
class Combustion;
class Electric;

class IInspectionReport {
public:
    virtual ~IInspectionReport() {}
    virtual bool checkWeight() = 0;
    virtual bool checkTemperatur() = 0;
    virtual bool checkVisualDefectStatus() = 0;
};

class InspectionReportCombustion : public IInspectionReport {
    private:
        Combustion& c;
    
    public:
        InspectionReportCombustion(Combustion& c) : c(c) {}
        bool checkWeight() override {
            if(c.getWeight() < 500 || c.getWeight() > 2000) {
                return false;
            }
            else {
                return true;
            }
        }

        bool checkTemperatur() override {
            if(c.getTemperature() > 100 || c.getTemperature() < 0) {
                return false;
            }
            else {
                return true;
            }
        }

        bool checkVisualDefectStatus() override {
            if(c.getVisualDefectStatus()){
                return false;
            }
            else {
                return true;
            }
        }
};

class InspectionReportElectric : public IInspectionReport {
    private:
        Electric& c;
    
    public:
        InspectionReportElectric(Electric& c) : c(c){}
        bool checkWeight() override {
            if(c.getWeight() < 500 || c.getWeight() > 2000) {
                return false;
            }
            else {
                return true;
            }
        }

        bool checkTemperatur() override {
            if(c.getTemperature() > 100 || c.getTemperature() < 0) {
                return false;
            }
            else {
                return true;
            }
        }

        bool checkVisualDefectStatus() override {
            if(c.getVisualDefectStatus()){
                return false;
            }
            else {
                return true;
            }
        }

        bool checkVoltage()  {
            if(c.getVoltage() > 12 || c.getVoltage() < 0) {
                return false;
            }
            else {
                return true;
            }
        }
};

class Product {
    protected:
        int id;
        std::string name;
        int weight;
        float temperature;
        bool visual_defect_status;

    public:
        Product(int id, std::string name, int weight, float temperature, bool visual_defect_status) : id(id), name(name), weight(weight), temperature(temperature), visual_defect_status(visual_defect_status) {}
        
        virtual ~Product() {}

        int getId() const {
            return id;
        }

        std::string getName() const {
            return name;
        }

        int getWeight() const {
            return weight;
        }
        
        float getTemperature() const {
            return temperature;
        }

        bool getVisualDefectStatus() const {
            return visual_defect_status;
        }

        virtual void printReport() = 0;
};

class Combustion : public Product {
    public:
        Combustion(int id, std::string name, int weight, float temperature, bool visual_defect_status) : Product(id, name, weight, temperature, visual_defect_status) {
            name = "Combustion Motor";
        }

        void printReport() override {
            InspectionReportCombustion report(*this);
            std::cout   << "Product: " << name
                        << "Weight Check: " << report.checkWeight()
                        << "Temperature Check: " << report.checkTemperatur()
                        << "Visual Inspection: " << report.checkVisualDefectStatus() << std::endl;
        }
};

class Electric : public Product {
    private:
        float voltage;
    public:
        Electric(int id, std::string name, int weight, float temperature, bool visual_defect_status, float voltage) : Product(id, name, weight, temperature, visual_defect_status), voltage(voltage) {
            name = "Electric Engine";
        }

        float getVoltage() const {
            return voltage;
        }

        void printReport() override {
            InspectionReportElectric report(*this);
            std::cout   << "Product: " << name
                        << "Weight Check: " << report.checkWeight()
                        << "Temperature Check: " << report.checkTemperatur()
                        << "Visual Inspection: " << report.checkVisualDefectStatus()
                        << "Voltage Check: " << report.checkVoltage() << std::endl;
        }
};



int main() {
    // 1. Array für Produkte erstellen (Polymorphie über Product-Pointer)
    // Wir erstellen jeweils 2 Objekte (Combustion und Electric)
    Product* products[4];

    // Parameter: id, name (wird intern überschrieben), weight, temp, visual_defect, [voltage]
    products[0] = new Combustion(101, "", 1200, 85.5f, false);
    products[1] = new Combustion(102, "", 2500, 110.0f, true); // Sollte FAILen
    
    products[2] = new Electric(201, "", 800, 45.0f, false, 12.0f);
    products[3] = new Electric(202, "", 600, 50.0f, false, 15.0f); // Voltage FAIL

    std::cout << "--- QUALITY CONTROL PIPELINE START ---" << std::endl << std::endl;

    // 2. Alle Produkte durchlaufen und Reports drucken
    for (int i = 0; i < 4; i++) {
        // Zugriff über Pointer
        products[i]->printReport();
        std::cout << "--------------------------------------" << std::endl;
    }

    // 3. Speicher aufräumen
    for (int i = 0; i < 4; i++) {
        delete products[i];
    }

    return 0;
}