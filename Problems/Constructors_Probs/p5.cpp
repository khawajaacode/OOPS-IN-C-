#include <iostream>
#include <string>

using namespace std;

class Types{

private:
int num;
char ch;


public:

Types(){

    num = 0;
    ch = 'x';
}

Types(int n, char c){
        num = n;
        ch = c;
    }
    void display(){
        cout  << num;
        cout  << ch<<endl;
    }

};




int main()
{

    Types t1,t2(100,'p');
    t1.display();
    t2.display();


    return 0;
}