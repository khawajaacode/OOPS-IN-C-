#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;
public:
    void setVehicleDetails(string b, int s) {
        brand = b;
        speed = s;
    }
    void displayVehicleDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;
public:
    void setCarDetails(int s) { seats = s; }
    void displayCarDetails() {
        displayVehicleDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
public:
    void setElectricCarDetails(float bc) { batteryCapacity = bc; }
    void displayElectricCarDetails() {
        displayCarDetails();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    ElectricCar ec;
    ec.setVehicleDetails("Tesla", 200);
    ec.setCarDetails(4);
    ec.setElectricCarDetails(75.0);
    ec.displayElectricCarDetails();
    return 0;
}
