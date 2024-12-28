#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream src("source.txt");
    ofstream dest("dest.txt");
    string line;
    while (getline(src, line))
        dest << line << endl;
    cout << "File copied successfully!" << endl;
    return 0;
}

