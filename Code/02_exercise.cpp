#include <iostream>

using namespace std;

class BankAccount {
    private:
    int accountno;
    float balance;

    public:

    BankAccount(int accno  ) : accountno(accno){


    }

    
    void deposit() {

        cout << "Enter The Amount you Want to Deposit: "; cin >> balance;
    }

    int withdraw() {

        float withdraw;
        cout << "Enter the Amount you Want to Withdraw "; cin >>withdraw;
        balance -= withdraw;
        return balance;
    }

    void display(){

        cout << "Total balance "; cout  << balance <<endl;
        cout << "Account No. " << accountno;

    }


};






int main() {

    BankAccount B(123456);

    B.deposit();
    B.withdraw();
    B.display();


}