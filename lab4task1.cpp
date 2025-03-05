#include <iostream>
using namespace std;

struct Car {
    string brand;
    string model;
    double rentalPrice;
    string available;

Car(string b,string m,double rp,string av)  :  brand(b) , model(m) , 
rentalPrice(rp) , available(av) {}

    void updateDetails(double rentalPrice, string available) {
        rentalPrice = rentalPrice;
        available = available;
    }

    void rentCar() {
        if (available=="Yes") {
            available = "No";
            cout << "Car rented successfully.\n";
        } else{
            cout << "Car is already rented.\n";
        }
    }

    void display(){
        cout << "Brand: " << brand << "\n Model: " << model
             << " | Rental Price: Rs" << rentalPrice
             << " | Available: " << available << "\n";
    }
};

int main() {
    Car car1("Toyota","Corolla", 10000.0, "Yes");
    car1.display();

    car1.updateDetails(11000.0, "Yes");
    car1.display();

    car1.rentCar();
    car1.display();

    car1.rentCar();

    return 0;
}