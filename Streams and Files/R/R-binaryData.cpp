#include<iostream>
#include<fstream>

using namespace std;

int main() {

    int numbers[5];

    ifstream infile("data.bin",ios::binary);
    if(infile.is_open()){
        infile.read((char*)numbers, sizeof(numbers));
        cout << "Binary data read successfully" << endl;
        
        for (int i = 0; i < 6; i++)
        {
            cerr << " Numbers : " << i + 1 << ": " << numbers[i]<<endl;
        }
        
    
    }
    else {
        cout << "Failed to open file for binary writhing"; 
    }

    infile.close();
    return 0;
}