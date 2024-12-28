// Formatted I/O: Write a program that stores a list of product names and prices in a file. Ensure that:

// Each line contains the product name and its price, separated by a space.
// Display all products and their prices formatted neatly when the file is read back.#

#include <iostream>
#include <fstream>
#include<string>

using namespace std;


int main(){

    ofstream outfile("product_list.txt");

    if (outfile.is_open()){
        outfile << "Apple 1.50" <<endl;
        outfile  << "Banana 0.75 " <<endl;
        outfile  << "Laptop 799.99 " <<endl;
        outfile  << "Headphones 29.99 " <<endl;
        outfile  << "Coffee Mug 12.50 " <<endl;
    }

    else {
        cout << "Failed to Open the file";

    }

    ifstream infile("product_list.txt");
    string line;

    if(infile.is_open()) {
        while(getline(infile,line)){
            cout  << line <<endl;

        }
        infile.close();

    }
    return 0;
   
    
} 
