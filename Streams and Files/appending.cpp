#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream outfile("sample.txt", ios::app);

    if(outfile.is_open()){
        outfile << "City: Rawalpindi\n";
        cout << "DATA APPENDED TO THE FILE" <<endl;
    }
    else{
        cout << "Failed to open the file for Append";
    }
    outfile.close();
    return 0;
}