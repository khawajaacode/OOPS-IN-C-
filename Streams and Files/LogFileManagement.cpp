#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    ofstream logFile("log.txt", ios::app);
    time_t now = time(0);
    logFile << "Action logged at: " << ctime(&now);
    cout << "Log updated!" << endl;
    return 0;
}
