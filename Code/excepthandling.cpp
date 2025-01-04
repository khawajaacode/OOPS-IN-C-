#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Division by zero exception
    try {
        int a = 10, b = 0;
        if (b == 0) throw runtime_error("Division by zero");
        cout << a / b;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // File not found exception
    try {
        ifstream file("nonexistent.txt");
        if (!file) throw runtime_error("File not found");
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
