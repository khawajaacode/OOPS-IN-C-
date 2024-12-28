#include <iostream>
#include <fstream>
#include <sstream> // Include this for istringstream
using namespace std;

int main() {
    ifstream file("text.txt");
    string word, line;
    int lines = 0, words = 0, chars = 0;

    if (!file) {
        cout << "File not found!" << endl;
        return 1;
    }

    while (getline(file, line)) { // Read each line
        lines++;
        chars += line.size(); // Count characters
        istringstream iss(line); // Create string stream for the line
        while (iss >> word)      // Extract words
            words++;
    }

    cout << "Lines: " << lines << ", Words: " << words << ", Characters: " << chars << endl;
    return 0;
}
