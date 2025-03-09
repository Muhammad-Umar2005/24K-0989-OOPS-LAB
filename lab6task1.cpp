#include<iostream>
using namespace std;


class Employee{
    protected:
    string name;
    float salary;
    public: 
    Employee(string n,float s) : name(n) , salary(s){}
    void display(){
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
};

class Manager:public Employee {
 protected:
 float bonus;
 public:
 Manager(string n,float s,float b) : Employee(n,s), bonus(b){}

void display(){
    Employee::display();
    cout << "Bonus: " << bonus << endl;
}
};
int main(){
Manager M1("Sarim",50000.00,10000.00);
M1.display();
return 0;
}