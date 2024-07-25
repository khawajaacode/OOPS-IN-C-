#include <iostream>
#include <string>

using namespace std;

class DB;
class DM{
    public:
 int meters;
 int cm;
public:
DM(){
    meters = 30;
    cm = 300;
}
friend void show(DM, DB);
};
class DB{
    public:
int feet;
int inches;
public:
DB(){
    feet = 5;
    inches = 50;
}
friend void show (DM, DB);
};

void show(DM x, DB y){
    int result;
    result = x.meters + x.cm + y.feet + y.inches;
    cout << "Sum of ALL : " << result;
}
int main()
{

        DM obj1;
        DB obj2;
        show(obj1, obj2);

    return 0;
}