#include <iostream>
#include <string> 
using namespace std;

class Person {
public:
    int rollNo, M[5];
    string name;
};


class Result  : public Person{


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
            do {      
                      cout << "Enter Marks for Subject " << (i + 1) << ": ";
                 cin >> M[i];
            }
            while(M[i] < 0 || M[i] > 100);

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

    void grade(){
        int average = avg();

        if(average > 90 && average < 100){
            cout << "You Got A Grade\n";
        }
        else if (average > 80 && average < 89) {
            cout << "You Got B Grade\n";
        }
         else if (average > 70 && average < 79) {
            cout << "You Got C Grade\n";
        }
         else if (average > 60 && average < 69) {
            cout << "You Got D Grade\n";
        }
        else {
            cout << "You Got F Grade\n";
        }

    }

    double highest(){
        int max = INT_MIN;
    
    for (int i = 0; i< 5; i++){
        if (M[i] > max)
        max = M[i];
        
    }
        return max;
    }
    double lowest(){
        int lowest = INT_MAX;
 for (int i = 0; i< 5; i++){
        if (M[i] < lowest)
        lowest = M[i];
        
    }

    return lowest;
    }
   
    
    
    


};

int main() {
    Result R;
    R.input();
    R.show(); 
    
    cout << "Total Marks : " << R.Total()  << endl; 
    cout << "Average : " << R.avg()  << endl;  
    cout << "Highest No. :" << R.highest() << endl;
    cout << "Lowest No. :" << R.lowest() << endl;  


    R.grade();
    

    return 0; 
}
