#include <iostream>
#include <fstream>
using namespace std;

class Person {
public:
    char name[50];
    int age;

    void showData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Person person;

    ifstream infile("person.dat", ios::binary);
    if (infile.is_open()) {
        infile.read((char*)&person, sizeof(person));
        cout << "Person data read from file:\n";
        person.showData();
    } else {
        cout << "Failed to open file for reading!" << endl;
    }

    infile.close();
    return 0;
}
