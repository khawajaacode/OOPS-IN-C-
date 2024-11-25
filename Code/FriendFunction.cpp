#include<iostream>

using namespace std;

class Box{
  private:
  int length;
  int width;
  int height;
  public:

  Box(int l, int w, int h) : length(l), width(w), height(h) {}

   friend int vol(Box b);
};

int vol(Box b) {
    return b.length * b.width * b.height;
}

int main() {
    Box box(3,4,8);

    cout << vol(box);

}