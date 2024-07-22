#include <iostream>
#include <string>

using namespace std;

class Account{
private:
string name;
int acc_number;
string type;
int balance;
public:
Account(){
    name = "Bob";
    acc_number = 767;
    type = "Saving Acc";
    balance = 560000;
}
void deposit(int dep){
    // int dep;
    // cout << "Deposit Amount : ";
    // cin >> dep;
    // return dep + balance;


}
void Withdraw(int with){
    // int withdraw;
    // cin >> withdraw;
    // return withdraw - balance;
}
void display(){
    cout << "Name of ACC holder " << name << endl;
    cout << "Total Balance in your ACC : " << balance << endl;
}
};





int main()
{
    Account A1;
    A1.deposit(2000);
    A1.Withdraw(2000);
    A1.display();
    

    return 0;
}