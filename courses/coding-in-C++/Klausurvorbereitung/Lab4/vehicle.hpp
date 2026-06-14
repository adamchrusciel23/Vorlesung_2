#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle {
    private:
        int weight;
        double temperature;
        bool visual_defect_status;
    
    public:
        Vehicle(int weight, double temperature, bool visual_defect_status) : weight(weight), temperature(temperature), visual_defect_status(visual_defect_status) {}
        
        int getWeight() const { return weight; }
        
        double getTemperature() const { return temperature; }

        bool getVisualDefectStatus() const { return visual_defect_status; }

        void setWeight(int weight) { this->weight = weight; }

        void setTemperature(double temperature) { this->temperature = temperature; }    
        
        void setVisualDefectStatus(bool visual_defect_status) { this->visual_defect_status = visual_defect_status; }    

        virtual ~Vehicle() = default;
};

class Combustion : public Vehicle {
    private:
        double consumption;
    
    public:
        Combustion(int weight, double temperature, bool visual_defect_status, double consumption) : Vehicle(weight, temperature, visual_defect_status), consumption(consumption) {}
        
        double getConsumption() const { return consumption; }
        
        void setConsumption(double consumption) { this->consumption = consumption; }
};

class Electric : public Vehicle {
    private:
        double voltage;

    public:
        Electric(int weight, double temperature, bool visual_defect_status, double voltage) : Vehicle(weight, temperature, visual_defect_status), voltage(voltage) { }

        double getVoltage() const { return voltage; }

        void setVoltage(double voltage) { this->voltage = voltage; }
};

#endif
