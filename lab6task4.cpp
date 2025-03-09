#include<iostream>
using namespace std;


class Account {
protected:
int accountNum;
float balance;
public:
Account(int AN,float b) : accountNum(AN),balance(b){}
void details(){
cout << "Account Number: " << accountNum <<
"\nBalance: " << balance << endl;
}
};

class SavingsAccount:public Account {
protected:
float interestRate;
public:
SavingsAccount(int AN,float b,float iR): Account(AN,b) , interestRate(iR){}
void details(){
    Account::details();
    cout << "Interest Rate in %: " << interestRate << endl;
}


};
class CheckingAccount: public Account{
protected:
float overdraftlimit;
public:
CheckingAccount(int AN,float b,float ovl) : Account(AN,b), overdraftlimit(ovl){}
void details(){
    Account::details();
    cout << "Over Draft Limit: " << overdraftlimit << endl;
}
};


int main(){
    SavingsAccount S1(1234,400000.00,5);
    S1.details();
    CheckingAccount C1(1234,400000.00,50000.00);
    C1.details();


return 0;
}