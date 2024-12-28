#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream infile("user_info.txt");
    string line;
    if(infile.is_open()) {
        while(getline(infile,line)){
            cout << line <<endl;
        }
        infile.close();
    }
    else {
        cout << "fAILED to Read from the File";
    }
return 0;

}