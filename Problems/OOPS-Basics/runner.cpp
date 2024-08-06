#include <iostream>
#include <string>

using namespace std;

class Run{
private:
string name;
int distance;

public:
void input(){
    cout << "Enter Runners Name : ";
    getline(cin>>ws,name);
    cout << "Input Distance " ;
    cin >> distance;
}
void show(){
    cout << "Name " << name << endl << "Distance: " << distance<<endl;
}
};


int main()
{

    Run r1;
    r1.input();
    r1.show();

    return 0;
}