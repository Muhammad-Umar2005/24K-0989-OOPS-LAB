#include <iostream>
#include <string>
using namespace std;

struct Car {
    string brand;
    string model;
    double rentalPrice;
   string available;

    Car(string b, string m, double price, string avail) {
        brand=b;
        model=m;
        rentalPrice=price;
        available=avail;
    }

    void updateDetails(double price, string avail) {
        rentalPrice=price;
        available=avail;
    }

    void rentCar(int days) {
        if (available=="No") {
            cout << "Car is not available.\n";
            return;
        }
        
        if (days > 10) {
            rentalPrice *= 0.90;
        } else if (days > 5) {
            rentalPrice *= 0.95;
        }
        
        available ="No";
        cout << "Car rented successfully for " << days << " days.\n";
    }

    void display(){
        cout << "Brand: " << brand << "\n Model: " << model
             << "\n Rental Price: Rs" << rentalPrice
             << "\n Available: " << available << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 40000.0,"Yes");
    car1.display();

    car1.updateDetails(45000.0,"No");
    car1.display();

    car1.rentCar(7);
    car1.display();

    return 0;
}
