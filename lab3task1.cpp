#include<iostream>
using namespace std;
class Wallet{
    public:
    string ownerName;
    double totalBalance;
    double amountadd;
    double amountsub;
    double amountad[10];
    double amountsubtract[10];
    int i=0,c=0;
    void addmoney(){
        char a;
        cout << "Do you want to add more money(press y for yes)" << endl;
        cin >> a;
        if(a=='Y' || a=='y'){
            cout << "Enter the amount you want to add" << endl;
            cin >> amountadd;
            totalBalance+=amountadd;
            amountad[i]=amountadd;
            i++;
        }

    }
    void spendmoney(){
        char b;
        cout << "Do you want to spend some money(press y for yes)" << endl;
        cin >> b;
        if(b=='Y' || b=='y'){
            cout << "Enter the amount you spend" << endl;
            cin >> amountsub;
            totalBalance-=amountsub;
            amountsubtract[c]=amountsub;
            c++;
        }
    }

    void transactionHistory(){
        for (int k=0;k<i;k++){
        cout << "Balance of " << amountad[k] << " Rs. is added to your account" << endl;
        }
        for (int k=0;k<c;k++){
            cout << "Balance of " << amountsubtract[k] << " Rs. is deducted from your account" << endl;
            }
        cout << "Available total Balance is " << totalBalance << endl;
    }
};

int main(){
Wallet u1;
int d;
do{
    cout << "1.Add Money\n2.Spend Money\n3.Transaction History\n4.Exit" << endl;
    cout << "Enter your choice" << endl;
cin >>d;
if (d==1){
    u1.addmoney();
}
if(d==2){
    u1.spendmoney();
}
if(d==3){
    u1.transactionHistory();
}
}while(d!=4);
return 0;
}