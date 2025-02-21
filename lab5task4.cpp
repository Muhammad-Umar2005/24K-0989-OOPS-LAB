#include<iostream>
using namespace std;
class Alarmsystem{
private:
string securitylevel;
string time;
public:
Alarmsystem(string sl,string time) : securitylevel(s1), time(time) {}
void display(){
    cout << "Security Level: " << securitylevel << endl;
    cout << "Time : " << time << endl;
}

};
class SmartHome{
private:
string personname;
string housename;
string room;
public:
Alarmsystem alarm;
SmartHome(string HN,string R,string personname) : housename(HN) , room(R), personname(personname) {}
void display(){
    cout << "Person Name : " << personname << endl;
    cout << "House Name : " << housenbame << endl;
    cout << "Room : " << room << endl;
}

};
int main(){
Alarmsystem A1("High","Emergency");
A1.display();
SmartHome S1("Luxury Villas", 4 ,"Wasay")
S1.display();

    return 0;
}
