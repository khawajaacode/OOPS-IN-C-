#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Car created: " << brand << " " << model << " (" << year << ")" << endl;
    }

    ~Car() {
        cout << "Car destroyed: " << brand << " " << model << " (" << year << ")" << endl;
    }

    void displayDetails() {
        cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << endl;
    }
};

int main() {
    Car car("Toyota", "Corolla", 2020);
    car.displayDetails();
    return 0;
}
