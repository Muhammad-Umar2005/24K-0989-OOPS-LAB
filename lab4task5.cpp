#include <iostream>
#include <string>
using namespace std;

class Car{
public:
    string brand;
    string model;
    double rentalPrice;
    string available;
    int id;
    double* revenue;
    Car(int id,string b, string m, double price): id(id),brand(b),model(m),rentalPrice(price) {
        available="Yes";
        revenue=new double(0.0);
    }
    ~Car() {
        cout << "Car " << brand << " " << model << " removed from memory.\n";
        delete revenue;
    }
    
    Car(Car &obj) {
        this->id=obj.id;
        this->brand=obj.brand;
        this->model=obj.model;
        this->rentalPrice=obj.rentalPrice;
        this->available=obj.available;
        revenue=new double;
        this->revenue=obj.revenue;
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
        *revenue = days*rentalPrice;
        available = "No";
        cout << "Car rented successfully for " << days << " days.\n";
    }
    void returnCar(){
        available="Yes";
    }
    void display() const {
        cout << "Id: " << id << endl << "Brand: " << brand << "\nModel: " <<model
             << "\nRental Price: Rs" <<rentalPrice
             << "\nAvailable: " <<available
             << "\nRevenue: Rs" <<*revenue << endl;
    }
};

int main() {
    Car car1(24,"Toyota","Corolla",50000.0);
    Car car2=car1;
    car1.display();
    car2.display();
    car2.brand="Suzuki";
    car2.model="Alto";
    car2.rentalPrice=30000.00;
    car2.id=35;
    car1.rentCar(7);
    car1.display();
    car2.display();
    car1.returnCar();
    car1.display();

    return 0;
}