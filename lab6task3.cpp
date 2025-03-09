#include<iostream>
using namespace std;

class Person{
 protected:
 string name;
 int age;
 public:
 Person(string n,int a) : name(n) , age(a) {}
 void display(){
    cout << "Name of Person: " << name <<"\nAge of person:" << age << endl;
 }

};

class Teacher: public Person{
protected:
 string subject;
 public:
 Teacher(string n,int a,string s) : Person(n,a) , subject(s){}
 void display(){
 Person::display();
 cout << "Subject is: " << subject <<endl;
 }

};
class Researcher : public Teacher{
 protected:
 string researchArea;
 Researcher(string n,int a,string s,string rA) : Teacher(n,a,s) , researchArea(rA) {}
 void display(){
    Teacher::display();
    cout << "Research Area: " << researchArea<<endl;
 }

};
class Professor: public Researcher{
protected:
int publications;
public:
Professor(string n,int a,string s,string rA,int p): Researcher(n,a,s,rA) , publications(p){}
void display(){
    Researcher::display();
    cout << "Number of publications: " << publications<<endl;
}
};


int main(){
Professor p1("Wasay",55,"Computer","Quantum Computing",6);
p1.display();
    return 0;
}