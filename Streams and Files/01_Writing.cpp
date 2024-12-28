//This example demonstrates how to write formatted data to a file.



#include <iostream>
#include <fstream> // For file handling
using namespace std;

int main() {

    ofstream outfile("sample.txt");
    if(outfile.is_open()) {
    outfile << "Name: Babar Naseer"<<endl;
    outfile << "Age : 20\n";
    outfile << "Data Has written successfull";
    }
    else {
        cout << "Failed to open the file" << endl;

    }
    outfile.close();
    return 0;                           

}
