#include <iostream>

using namespace std;

class Array{
 private:
     int arr[5];

public:

    void fill();
    void display();
    int max();
    int min();

};

void Array::fill(){
    for(int i = 0; i < 5; i++){
        cout << "Enter Array "<< i <<" "; 
        cin >> arr[i];
    }
}

void Array::display(){
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
}


int Array::max(){
    int high = INT_MIN;
    for(int i = 0; i < 5; i++){
        if (arr[i] > high)
        high = arr[i];
    }
    return high; 

}

int Array::min(){
    int small = INT_MAX;
    for(int i = 0; i < 5; i++){
        if (arr[i] < small)
        small = arr[i];
    }
    return small;

}

int main()
{
    Array a1;
    a1.fill();
    cout << "Your Input : "<< endl;
    a1.display();
    cout << "Maximun value " <<a1.max()<<endl;
   cout << "Minimum value " <<a1.min();
    

    return 0;
}