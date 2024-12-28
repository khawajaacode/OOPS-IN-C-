#include<iostream>

#include<fstream>

using namespace std;

int main() {

    string name, city;
    int age;

    ofstream outfile("user_info.txt");
    if(outfile.is_open()) {
        cout << "Enter The Name of the user :";
        cin >> name;
        outfile << "Name: " << name <<endl;
        cout << "Enter The Age of the user :";
        cin >> age;
        outfile << "Age : " << age <<endl;
        cout << "Enter The City of the user :";
        cin >>city;
        outfile << "City :  " << city <<endl;
    }
    else {cout << "Failed to open the File";
   

    }

    outfile.close();
     return 0;
}