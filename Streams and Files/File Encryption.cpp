#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("text.txt");
    ofstream outFile("encrypted.txt");
    char ch;
    while (inFile.get(ch))
        outFile.put(ch + 3); // Shift ASCII
    return 0;
}
