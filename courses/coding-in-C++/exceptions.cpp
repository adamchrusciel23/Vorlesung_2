#include <iostream>
#include <stdexcept>
#include <string>

class SystemConfigError : public std::runtime_error {
    public:
        SystemConfigError(const std::string& msg) : std::runtime_error(msg) {}

};

class ConfigLoader {
    public:
        void load(const std::string& filename) {
            if(filename.empty()) {
                throw std::invalid_argument("Dateiname darf nicht leer sein.");
            }

            if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".cfg") {
                throw std::invalid_argument("Ungueltige Dateiendung. Nur .cfg erlaubt.");
            }

            if(filename == "missing.cfg") {
                throw std::runtime_error("Datei konnte nicht geoeffnet werden: " + filename);
            }

            if(filename == "invalid.cfg") {
                throw SystemConfigError("Systemspezifische Konfiguration ist fehlerhaft: " + filename);
            }
        }
};

void testLoad(ConfigLoader& loader, const std::string& filename) {
    try  {
        loader.load(filename);
    }
    catch (const SystemConfigError& e) {
        std::cout << "SystemConfigError " << e.what() << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid Argument " << e.what() << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << "[runtime_error]     " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "[exception]         " << e.what() << "\n";
    }
    std::cout << "\n";
}
int main() {
    ConfigLoader loader;

    testLoad(loader, "");            // leerer Name
    testLoad(loader, "config.txt"); // falsche Endung
    testLoad(loader, "missing.cfg");// nicht öffenbar
    testLoad(loader, "invalid.cfg");// fehlerhafte Systemkonfig
    testLoad(loader, "app.cfg");    // Erfolgsfall

    return 0;
}