#include <iostream>
#include <string>
using namespace std;

struct Car {
    string brand;
    string model;
    double rentalPrice;
    string available;

    Car(string b, string m, double price, string avail) {
        brand = b;
        model = m;
        rentalPrice = price;
        available = avail;
    }

    Car(Car &obj) {
        brand=obj.brand;
        model=obj.model;
        rentalPrice=obj.rentalPrice;
        available=obj.available;
    }

    ~Car(){
        cout << "Car " << brand << " " << model << " removed from memory.\n";
    }

    void updateDetails(double price, string avail) {
        rentalPrice=price;
        available=avail;
    }

    void rentCar(int days) {
        if (available == "No") {
            cout << "Car is already rented.\n";
            return;
        }
        
        if (days > 10) {
            rentalPrice *= 0.90;
        } else if (days > 5) {
            rentalPrice *= 0.95;
        }
        
        available = "No";
        cout << "Car rented successfully for " << days << " days.\n";
    }

    void display() {
        cout << "Brand: " << brand << "\nModel: " << model
             << "\nRental Price: Rs" << rentalPrice
             << "\nAvailable: " << available << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla",50000.0, "Yes");
    car1.display();

    Car car2 = car1;
    car2.display();

    car1.updateDetails(45000.0, "No");
    car1.display();
    car2.updateDetails(55000.0,"No");
    car1.rentCar(7);
    car1.display();
    car2.rentCar(3);
    car2.display();

    return 0;
}
