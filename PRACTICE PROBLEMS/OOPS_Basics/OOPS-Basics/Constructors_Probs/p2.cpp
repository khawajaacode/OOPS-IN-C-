#include <iostream>
 

using namespace std;

class Numbers{
public:
int a,b;
Numbers(){
    a = b= 100;
}

void avg() {
   
    cout <<(a+b)/2;
}
};

int main()
{

    Numbers n;
    n.avg();

    return 0;
}