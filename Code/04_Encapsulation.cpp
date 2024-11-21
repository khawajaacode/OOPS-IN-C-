#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    float balance;

public:
    BankAccount(string accNum, float bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void checkBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("12345678", 500.0);
    account.deposit(100.0);
    account.withdraw(50.0);
    account.checkBalance();
    return 0;
}
