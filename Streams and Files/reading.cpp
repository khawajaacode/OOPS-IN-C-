#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("sample.txt"); // Open file for reading
    string line;

    if (infile.is_open()) {
        while (getline(infile, line)) { // Read line by line
            cout << line << endl; // Print each line to the console
        }
        infile.close(); // Close the file
    } else {
        cout << "Failed to open the file for reading!" << endl;
    }

    return 0;
}
