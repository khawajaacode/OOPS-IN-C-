

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int arr[5] = {39, 54, 45, 44, 88};
    int max = INT_MIN;
    int lowest = INT_MAX;
    for (int i = 0; i< 5; i++){
        if (arr[i] > max)
        max = arr[i];
        
    }

    cout << max<<endl;

    for (int i = 0; i< 5; i++){
        if (arr[i] < lowest)
        lowest = arr[i];
        
    }

    cout << lowest <<endl;
    



    return 0;
}