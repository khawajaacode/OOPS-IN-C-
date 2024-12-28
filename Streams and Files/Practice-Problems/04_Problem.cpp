#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    ofstream outFile("binary_data.bin", ios::binary);
    outFile.write((char*)nums, sizeof(nums));
    outFile.close();

    int readNums[5];
    ifstream inFile("binary_data.bin", ios::binary);
    inFile.read((char*)readNums, sizeof(readNums));
    for (int n : readNums)
        cout << n << " ";
    return 0;
}
