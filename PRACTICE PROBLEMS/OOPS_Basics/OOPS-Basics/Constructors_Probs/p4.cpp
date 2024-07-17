#include <iostream>
#include <string>

using namespace std;

class TV {
public:
    string name;
    string model;
    int price;

    // Constructor to initialize the TV object
    TV(string name, string model, int price) {
        this->name = name;
        this->model = model;
        this->price = price;
    }

    // Method to display all attributes
    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    // Creating the first TV object
    TV t1("SAMSUNG", "LCDTV", 50000);
    t1.getInfo(); // Display the initial attributes

    cout << "\nDisplay Object After Change... " << endl;

    // Directly changing the attributes of the first TV object
    t1.name = "HAIER";
    t1.model = "LEDTV";
    t1.price = 45000;
    t1.getInfo(); // Display the updated attributes

    return 0;
}
// #include <iostream>
// #include <string>

// using namespace std;

// class TV {
// public:
//     // Constructor to initialize the TV object
//     TV(string name, string model, int price) {
//         this->name = name;
//         this->model = model;
//         this->price = price;
//     }

//     // Method to display all attributes
//     void getInfo() const {
//         cout << "Name: " << name << endl;
//         cout << "Model: " << model << endl;
//         cout << "Price: " << price << endl;
//     }

//     // Method to set all attributes
//     void setAttributes(string name, string model, int price) {
//         this->name = name;
//         this->model = model;
//         this->price = price;
//     }

// private:
//     string name;
//     string model;
//     int price;
// };

// int main() {
//     // Creating the first TV object
//     TV t1("SAMSUNG", "LCDTV", 50000);
//     t1.getInfo(); // Display the initial attributes

//     cout << "\nDisplay Object After Change... " << endl;

//     // Changing all attributes of the first TV object
//     t1.setAttributes("HAIER", "LEDTV", 45000);
//     t1.getInfo(); // Display the updated attributes

//     return 0;
// }
