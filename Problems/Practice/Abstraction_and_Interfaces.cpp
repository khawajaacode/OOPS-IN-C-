#include <iostream>
#include <cmath>

using namespace std;

class Appliance {
    public:
    virtual void operate() = 0;

};
class WashingMachine : public Appliance{
public: 
     void operate() override {
        cout << "Washing Clothes" << endl;
     }
};

class Refrigerator : public Appliance{
public:
    void operate() override {
        cout << "Refregerator" <<endl;
    }

};


int main()
{

    Appliance* appliance;
    WashingMachine wm;
    Refrigerator rf;

    appliance = &wm;
    appliance->operate();

    appliance = &rf;
    appliance->operate();




    return 0;
}