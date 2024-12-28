#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ofstream outfile("books.txt", ios::app);
    string title, author;
    double price;

    cout << "Enter Title, Author and Price: ";
    cin >> title >> author >> price;
    outfile << title << " " << author << " " << price <<endl;
    outfile.close();

    ifstream infile("books.txt");
    while(infile >> title >> author >> price){
        cout << title << " by " << author << " : $ " << price <<endl;

    }
    return 0;
}