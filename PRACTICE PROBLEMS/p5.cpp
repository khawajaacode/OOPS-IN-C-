#include <iostream>
#include <string> // Include string for std::string

using namespace std;

class Result {
private:
    int rollNo, M[5];
    string name;

public:

    void input() {
        do{
        cout << "Roll NO. : ";
        cin >> rollNo;
        } while(rollNo<=0);

        cin.ignore(); 

        cout << "Enter Name : ";
        getline(cin, name);
    
        for (int i = 0; i < 5; i++) {
            cout << "Enter Marks for Subject " << (i + 1) << ": ";
            cin >> M[i];
        }
    }

    void show() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Marks " << (i + 1) << ": " << M[i] << endl;
        }
    }

    int Total() {
        int t = 0;
        for (int i = 0; i < 5; i++) {
            t += M[i];
        }
        return t;
    }

    double avg() {
        return Total() / 5.0; 
    }
};

int main() {
    Result R;
    R.input();
    R.show();
    cout << "Total Marks : " << R.Total()  << endl; 
    cout << "Average : " << R.avg()  << endl;       

    return 0; 
}
