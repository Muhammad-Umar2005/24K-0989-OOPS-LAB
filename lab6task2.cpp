#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string name;
    int speed;
    public:
    Vehicle(string n,int s) : name(n) , speed(s){}

    void display(){
        cout << "Name of Car :" << name << endl << "Speed of car in KMs:" << speed << endl;
    }
};
class Car : public Vehicle{
protected:

int seats;

public:
Car(string n,int s,int se) : Vehicle(n, s) , seats(se){}
void display(){
    Vehicle::display();
    cout << "Number of Seats :" << seats<< endl;
}

};

class ElectricCar : public Car{
protected:
int BatteryLife;
public:
ElectricCar(string n,int s,int se, int BL) : Car(n,s,se), BatteryLife(BL){}
void display(){
    Car::display();
    cout << "Battery Life in Hrs :" << BatteryLife << endl;
}

};

int main(){
  ElectricCar Car1("Corolla",280,5,3);
 Car1.display();

    return 0;
}