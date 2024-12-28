#include<iostream>
#include<fstream>

using namespace std;

int main() {

    int numbers[] = {1,2,3,4,5,6,7};

    ofstream outfile("data.bin",ios::binary);
    if(outfile.is_open()){
        outfile.write((char*)numbers, sizeof(numbers));
        cout << "Binary data written successfully" << endl;

    
    }
    else {
        cout << "Failed to open file for binary writhing"; 
    }

    outfile.close();
    return 0;
}