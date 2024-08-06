#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <map>

// Base Device class
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() const = 0; // Marked as const
    virtual ~Device() {}
};

// Derived SmartLight class
class SmartLight : public Device {
private:
    bool isOn;
public:
    SmartLight() : isOn(false) {}
    void turnOn() override { isOn = true; }
    void turnOff() override { isOn = false; }
    std::string getStatus() const override { return isOn ? "On" : "Off"; } // Marked as const
};

// Observer pattern for notifications
class Observer {
public:
    virtual void update(const std::string &message) = 0;
    virtual ~Observer() {}
};

class User : public Observer {
private:
    std::string username;
public:
    User(const std::string &user) : username(user) {}
    void update(const std::string &message) override {
        std::cout << "Alert for " << username << ": " << message << std::endl;
    }
};

class Subject {
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* obs) { observers.push_back(obs); }
    void notifyObservers(const std::string &message) {
        for (auto obs : observers) {
            obs->update(message);
        }
    }
};

// Energy Manager for tracking energy usage
class EnergyManager {
private:
    std::map<std::string, double> energyUsage;
public:
    void recordUsage(const std::string &deviceName, double usage) {
        energyUsage[deviceName] += usage;
    }
    void generateReport() {
        for (const auto &entry : energyUsage) {
            std::cout << entry.first << ": " << entry.second << " kWh" << std::endl;
        }
    }
};

// Function to save device status to file
void saveConfiguration(const std::string &filename, const SmartLight &light) {
    std::ofstream file(filename);
    file << light.getStatus() << std::endl;
    file.close();
}

// Function to load device status from file
void loadConfiguration(const std::string &filename, SmartLight &light) {
    std::ifstream file(filename);
    std::string status;
    file >> status;
    if (status == "On") {
        light.turnOn();
    } else {
        light.turnOff();
    }
    file.close();
}

// Display the menu
void displayMenu() {
    std::cout << "1. Turn On Light\n2. Turn Off Light\n3. Check Light Status\n4. Save Configuration\n5. Load Configuration\n6. Exit\n";
}

// Handle user input
void handleUserInput(SmartLight &light, EnergyManager &energyManager, Subject &subject) {
    int choice;
    std::string filename;
    std::cin >> choice;
    switch (choice) {
        case 1:
            light.turnOn();
            energyManager.recordUsage("SmartLight", 0.1); // Example usage value
            subject.notifyObservers("Light turned on");
            break;
        case 2:
            light.turnOff();
            energyManager.recordUsage("SmartLight", 0.05); // Example usage value
            subject.notifyObservers("Light turned off");
            break;
        case 3:
            std::cout << "Light is " << light.getStatus() << std::endl;
            break;
        case 4:
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            saveConfiguration(filename, light);
            break;
        case 5:
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            loadConfiguration(filename, light);
            break;
        case 6:
            std::exit(0);
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

int main() {
    SmartLight light;
    EnergyManager energyManager;
    Subject subject;
    User user("JohnDoe");
    subject.addObserver(&user);

    while (true) {
        displayMenu();
        handleUserInput(light, energyManager, subject);
    }

    return 0;
}
