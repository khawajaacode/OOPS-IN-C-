#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    char name[50];
    int roll;
    char grade;

    void getData() { cin >> name >> roll >> grade; }
    void showData() { cout << name << " " << roll << " " << grade << endl; }
};

int main() {
    Student s[2];
    ofstream outFile("students.dat", ios::binary);
    for (int i = 0; i < 2; ++i) {
        s[i].getData();
        outFile.write((char*)&s[i], sizeof(s[i]));
    }
    outFile.close();

    ifstream inFile("students.dat", ios::binary);
    for (int i = 0; i < 2; ++i) {
        inFile.read((char*)&s[i], sizeof(s[i]));
        s[i].showData();
    }
    return 0;
}
