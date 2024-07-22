#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
string name;
double average;
int team;
public:
Player(){
  
}

void input(){
      cout << "Enter Player name: ";
    getline(cin>>ws,name);
    cout << "Enter Average of Player: ";
    cin >> average;
    cout << "Enter Team: ";
    cin >> team;
}
void display(){
    cout << name << " has " << average << " average and have " << team << " member of team"<<endl;
}


};

int main()
{

    Player p1;
    p1.input();
    p1.display();

    return 0;
}