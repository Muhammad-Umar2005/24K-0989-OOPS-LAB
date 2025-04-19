#include<iostream>
using namespace std;

class InventoryManager;

class Car{
private:
string model;
double price;
friend class InventoryManager;
friend void comparePrice(Car, Car);
public:
Car (string m,double p) : model(m) , price(p) {}

};

class InventoryManager{
public:
void update(Car &Obj,string mode,int pri){
    Obj.price=pri;
    Obj.model=mode;
}
void details(Car Obj){
    cout << "Model: " << Obj.model <<"\nPrice: " << Obj.price << endl;
   }
};
void comparePrice(Car Obj,Car c){
    if (Obj.price>c.price){
        cout << "1st car is expensive from other" << endl;
    }
    else if(c.price>Obj.price){
        cout << "2st car is expensive from other" << endl;
    }
    else cout << "Both car have same value" << endl;
}
int main(){
Car c1("Corolla",4040000);
Car c2("Civic",5050000);
InventoryManager I1;
comparePrice(c1,c2);
I1.details(c1);
I1.details(c2);
}