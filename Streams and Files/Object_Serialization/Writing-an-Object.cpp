#include <iostream>
#include <fstream>
using namespace std;

class Person {
public:
    char name[50];
    int age;

    void getData() {
        cout << "Enter name: ";
        cin.getline(name, 50);
        cout << "Enter age: ";
        cin >> age;
    }
};

int main() {
    Person person;
    person.getData();

    ofstream outfile("person.dat", ios::binary);
    if (outfile.is_open()) {
        outfile.write((char*)&person, sizeof(person));
        cout << "Person data written to file!" << endl;
    } else {
        cout << "Failed to open file for writing!" << endl;
    }

    outfile.close();
    return 0;
}
