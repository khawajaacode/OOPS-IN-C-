#include <iostream>
#include <string>

using namespace std;

class Travel{
private:
int km,hours;
public:
Travel(){
    km = hours = 0;
}
void gets(){
    cout << "Enter Km Traveled: ";
    cin >> km;
    cout << "Enter Hours travelled : ";
    cin >> hours;
}

void shows(){
    cout << "You Traveled: " << km << " in " << hours << " Hours "<<endl;
}

void add(Travel p){
    Travel t;
    t.km = km + p.km;
    t.hours = hours + p.hours;

    cout << "Total Travelling is: " << t.km << " in " << t.hours <<" Hours" << endl;

    
}
};


int main()
{
    Travel my, your;
    my.gets();
    my.shows();
    your.gets();
    your.shows();
    my.add(your);
    
    

    return 0;
}