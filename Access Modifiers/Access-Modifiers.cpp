#include <iostream>

#include<string>


using namespace std;

class Student{

  // Public, Private, Protected is Access Modifiers

  private: // Data and Method Accessible inside the Class
    string address;

 public: // Data & Method Accessible to Everone
  string name;
  string id;
  int age;


  // Setter
  void setAddress(string add) {
    address = add;
  }

  // Getter
  string getAddress() {
    return address;
  }
};

int main()
{
  Student s1;
  s1.name = "Ali";
  s1.id = "1234";
  s1.age = 20;
  
  s1.setAddress("Istanbul");
  
  cout << s1.getAddress() << endl;

  cout << s1.age <<endl;
    

    return 0;
}