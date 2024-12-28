#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outfile("user_info.txt", ios::app);

    if(outfile.is_open()) {
        outfile << "Alice Johnson, 27, New York; Ravi Kumar, 32, Mumbai; Hiroshi Tanaka, 45, Tokyo; Emma Müller, 21, Berlin; Carlos Ramirez, 38, São Paulo."<<endl;
        cout << " DATA Appended successfully ";
    }
    else {
        cout << "Failed to Appened";
    }
return 0;
}