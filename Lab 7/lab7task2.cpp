#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string productID;
    string productName;
    float price;
    int stockQuantity;

public:
    Product(string id, string name, float p, int qty) : productID(id), productName(name), price(p), stockQuantity(qty) {}

    virtual float applyDiscount(float discountRate) {
        price -= price * discountRate;
        return price;
    }

    virtual float calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << ", Name: " << productName << ", Price: " << price << ", Stock: " << stockQuantity << endl;
    }
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(string id, string name, float p, int qty, int warranty, string b) : Product(id, name, p, qty), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " years, Brand: " << brand << endl;
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(string id, string name, float p, int qty, string s, string c, string fabric) : Product(id, name, p, qty), size(s), color(c), fabricMaterial(fabric) {}

    float applyDiscount(float discountRate) override {
        if (discountRate > 0.5) {
            discountRate = 0.5;
        }
        return Product::applyDiscount(discountRate);
    }
};

class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(string id, string name, float p, int qty, string exp, int cal) : Product(id, name, p, qty), expirationDate(exp), calories(cal) {}

    float calculateTotalPrice(int quantity) override {
        if (quantity >= 10) {
            return Product::calculateTotalPrice(quantity) * 0.9;
        }
        return Product::calculateTotalPrice(quantity);
    }
};

class Book : public Product {
private:
    string author;
    string genre;

public:
    Book(string id, string name, float p, int qty, string auth, string gen) : Product(id, name, p, qty), author(auth), genre(gen) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << ", Genre: " << genre << endl;
    }
};

float operator+(const Product& a, const Product& b) {
    return a.price + b.price;
}

ostream& operator<<(ostream& os, const Product& p) {
    os << "Product ID: " << p.productID << ", Name: " << p.productName << ", Price: " << p.price << ", Stock: " << p.stockQuantity;
    return os;
}

int main() {
    Electronics e("E001", "Laptop", 1000.0f, 50, 1, "Lenovo");
    Clothing c("C001", "T-Shirt", 20.0f, 100, "M", "Red", "Cotton");
    FoodItem f("F001", "Chocolate", 5.0f, 200, "2025-05-10", 500);
    Book b("B001", "Fiction Book", 15.0f, 30, "Dr. Sohail Irteza", "Fiction");

    e.displayProductInfo();
    c.displayProductInfo();
    f.displayProductInfo();
    b.displayProductInfo();

    cout << "Total price of e and c: " << e + c << endl;
    cout << "Formatted output of e: " << e << endl;

    return 0;
}