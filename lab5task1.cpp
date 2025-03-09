#include<iostream>
using namespace std;

class Apartment{
public:
   string Id;
   string address;
   string* ownerName;

Apartment(string id,string add,string owner){
      Id=id;
      address=add;
      ownerName=new string;
      *ownerName=owner;
}

Apartment(Apartment &c){
    this->Id=c.Id;
    this->address=c.address;
    ownerName=new string;
    (*ownerName)=*c.ownerName;
}
void details(){
cout << "Id: " << Id << "\nAddress: " << address << "\nOwner Name: " << *ownerName << endl;
}
};
int main(){

Apartment A1("A24-016","R-912@Street 8","Salman");
Apartment A2(A1);
*(A2.ownerName)="Wasay";
Apartment A3(A1);
*(A3.ownerName)="Qasim";
A1.details();
A2.details();
A3.details();
return 0;
}