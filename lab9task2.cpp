#include<iostream>
using namespace std;

class MenuItem{
public:
string dishname;
double price;

MenuItem(string dm,double p) : dishname(dm), price(p) {}
virtual void prepare()=0;
virtual void showdetails()=0;
};

class Appetizer:public MenuItem{
    public:
    Appetizer(string dm,double p) : MenuItem(dm,p) {}
    void prepare(){
        cout << "This dish is prepared by fresh and hygenic Ingredients" << endl;
    }
    void showdetails(){
        cout << "Dish Name: " << dishname <<"\nPrice: " << price << endl;
}
    };

    class MainCourse:public MenuItem{
        public:
        MainCourse(string dm,double p) : MenuItem(dm,p) {}
        void prepare(){
            cout << "This is our restaurant's signature item" << endl;
        }
        void showdetails(){
            cout << "Dish Name: " << dishname <<"\nPrice: " << price << endl;
    }
        };

int main(){
    MenuItem *m1=new Appetizer("Mushrooms",400);
    m1->prepare();
    m1->showdetails();
    cout << "\n";
    m1=new MainCourse("Chicken Biryani",350);
    m1->prepare();
    m1->showdetails();
}