#include <iostream>
using namespace std;



int main() {

    int a = 82, b =0;

    try
    {
        if(b==0) {
            throw "Divison by Zero is not allowed";
        }
        cout << "Result " << a/b <<endl;
    }
    catch(const char* e)
    {
        cerr  << " Error: "<< e << '\n';
    }

    cout  << "Programs Continue...";

    return 0;

    
}


