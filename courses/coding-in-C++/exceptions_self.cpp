#include <iostream>
#include <stdexcept>
#include <string>

class ErrorFinding : public std::runtime_error {
    public:
        ErrorFinding(const std::string& msg) : std::runtime_error(msg) {}
};

class ConfigLoader{
    public:
        void load(const std::string& filename){
            if(filename.empty()) {
                throw std::invalid_argument("Datei darf nicht leer sein");
            }

            if(filename.length() < 4 || filename.rfind(".cfg") != filename.length() - 4) {
                throw std::invalid_argument("Datei muss eine .cfg Datei sein");
            }

            if(filename == "missing.cfg") {
                throw std::invalid_argument("Datei kann nicht geöffnet werden");
            }

            if(filename == "invalid.cfg") {
                throw std::invalid_argument("nicht Systemspezifische Konfiguration");
            }

            std::cout << "Keine Fehler alles supa" << std::endl;
        }
};
void loadTest(ConfigLoader& loader, const std::string& filename) {
    try {
        loader.load(filename);
    }
    catch(const std::invalid_argument& i) {
        std::cout << "invalid Argument " << i.what() << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Allgemeiner Fehler " << e.what() << std::endl;
    }
}

int main() {
    ConfigLoader load;
    loadTest(load, "");
    loadTest(load, "Dokument.pdf");
    loadTest(load, "missing.cfg");
    loadTest(load, "invalid.cfg");
    loadTest(load, "richtig.cfg");
}