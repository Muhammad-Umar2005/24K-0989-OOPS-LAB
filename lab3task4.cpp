#include<iostream>
using namespace std;

class car{
    public:
string brand;
string model;
int fuelcapacity;
int fuelquantity;
int cc;
float fuelconsumption;
int distance;
int currentfuel;
int refuel;

car(string b,string m,int fc){
   brand=b;
   model=m;
   fuelcapacity=fc;
}
void calculatefuel(){
   cout << "Enter the quantity of fuel in litres before starting a travel" << endl;
   cin >> fuelquantity;
   cout << "Enter your car CC" << endl;
   cin >> cc;
   cout << "Enter the distance in Kms you travel; " << endl;
   cin >> distance;
   if (cc<=1000){
   fuelconsumption=distance/18;
   }
   if (cc>1000 && cc<=2000){
fuelconsumption=distance/13;
   }
   if (cc>2000){
 fuelconsumption=distance/10;
   }
   currentfuel=fuelquantity-fuelconsumption;
   cout << "Current Fuel : " << currentfuel << "Litres"  << endl;
}

void refueltank(){
    char a;
    cout << "You want to refuel your tank(Press y for yes)" << endl;
    cin >> a;
    if (a=='y' || a=='Y'){
      cout <<  "Enter the refuel quantity" << endl;
      cin >> refuel;
      currentfuel=fuelquantity+refuel;
    }
}

void Fuelstatus(){
 if (currentfuel>=15){
  cout << "Status: High" << endl;
 }
 if (currentfuel<15 && currentfuel>=5){
    cout << "Status: Normal" << endl;
   }
   if (currentfuel<5){
    cout << "Status: Low" << endl;
   }    
}
};
int main(){
car c1("Suzuki","Alto",20);
c1.calculatefuel();
c1.refueltank();
c1.Fuelstatus();
 return 0;
}