#include<iostream>
using namespace std;

class Patient{
public:
string name;
string id;
public:
Patient(string n,string id) : name(n) ,id(id){}
virtual string displayTreatment(string treat) = 0;
virtual double calculatecost(int days,double cost_oneday) = 0;
};

class Inpatient:public Patient{
private:
string treat;
int currdays;
double cost_oneday;
double cost;
public:
Inpatient(string n,string id) : Patient(n,id) {}
string displayTreatment(string treat){
    this->treat=treat;
return treat;
}
double calculatecost(int currdays,double cost_oneday){
double cost=currdays*cost_oneday;
this->cost=cost;
return cost;
}
void display(){
    cout <<"Name: " << name << endl << "Id: " << id << endl;
cout << "Treatment: " << displayTreatment(treat) << endl;
cout << "Cost: " << calculatecost(currdays,cost_oneday) << endl;
}
};

class Outpatient:public Patient{
private:
string treat;
int totaldays;
double cost_oneday;
double cost;
public:
Outpatient(string n,string id) : Patient(n,id) {}
string displayTreatment(string treat){
    this->treat=treat;
    return treat;
}
double calculatecost(int totaldays,double cost_oneday){
    cost=totaldays*cost_oneday;
    this->cost=cost;
    return cost;
}

void display(){
    cout <<"Name: " << name << endl << "Id: " << id << endl;
cout << "Treatment: " << displayTreatment(treat) << endl;
cout << "Cost: " << calculatecost(totaldays,cost_oneday) << endl;
}
};

int main(){
Inpatient I1("Kamran","21D");
I1.displayTreatment("Typhoid");
I1.calculatecost(4,12000);
I1.display();

}