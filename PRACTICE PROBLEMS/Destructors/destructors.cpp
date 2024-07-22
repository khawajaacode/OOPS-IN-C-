#include <iostream>
#include <conio.h>

using namespace std;

class Test{
private:
int n;
public:
Test(){
    cout << "Constructor.\n";

}

~Test(){
    cout << "Destructor\n";
}
};

int main()
{

    Test a,b;


    return 0;
}