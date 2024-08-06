#include <iostream>
#include <string>

using namespace std;

class Book{
private:
string title,author;
int pages;
public:
Book(){
    title = "";
    author = "";
    pages = 0;
}
void getdetails(){
    cout << "\n Enter Book Title : ";
    getline(cin>>ws,title);
    cout << "Enter Author ";
    getline(cin>>ws,author);
    cout << "\n Enter Book Pages : ";
    cin >> pages;
      cin.ignore();

}
void showdetails(){
    cout << "You Entered " << title << " by " << author << endl;
    cout << "Book Pages : " << pages << endl;
}
void comaparePages(Book b){
    if (pages > b.pages) {
        cout << title << " has more pages than " << b.title << endl;

    }
    else if(pages < b.pages) {
        cout << title << " has less pages than " << b.title << endl;

    }
    else {
        cout << title << " and " << b.title << " has same pages" << endl;
    }


}

};

int main()
{

    Book b1,b2;
    cout << "Enter Details of Book 1: ";
    b1.getdetails();
    b1.showdetails();
cout << "Enter Details of Book 2: ";
    b2.getdetails();
    b2.showdetails();
      cout << "\nComparing the number of pages of the two books:" << endl;
        b1.comaparePages(b2);
    return 0;
}