#include<iostream>
using namespace std;

//Task 5 of lab 5
class Doctor{
public:
string name;
string specialization;
int experience;
Doctor(){

}
Doctor(string n,string s,int e){
    name=n;
    specialization=s;
    experience=e;
}
void display(){
    cout << "Doctor Name: " << name << endl
    << "Specialization: " << specialization << endl
    << "Experience: " << experience << endl;
}
};
class Hospital{
public:
string Hname;
string Haddress;
Hospital(string Hn,string Ha){
   Hname=Hn;
   Haddress=Ha;
}
Doctor *DOC[10];
int count=0;
void addDOC(Doctor *D){
DOC[count++]=D;
}
void details(){
    cout << "___Hospital Details___" << endl <<
    "Hospital Name: " << Hname << endl
    << "Hospital Address: " << Haddress << endl
     << "_____Doctor Details______" << endl;
     for (int i=0;i<count;i++){
     DOC[i]->display();
     }
}
};



int main(){
    Doctor D1("Sohail","Child Specialist",4);
    Doctor D2("Waseem","Surgeon",5);
    Hospital H1("Shifa","I-8 Islamabad");
    H1.addDOC(&D1);
    H1.addDOC(&D2);
    H1.details();
     Hospital H2("Aiwan E Tijarat","Beside Anda Mor");
      Doctor D3("Qasim","Physician",11);
      H2.addDOC(&D3);
      H2.details();
    return 0;
}