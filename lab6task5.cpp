#include<iostream>
using namespace std;

class Device{
 public:
int deviceId;
bool status;
Device(int dI,bool s) : deviceId(dI) , status(s){}

void details(){
    cout << "Device Id: " << deviceId << endl;
    if (status==1)
    cout << "Availability: Yes" << endl;
    else cout << "Availability: No" << endl;
}
};

class SmartPhone:public Device{
public:
float screensize;
SmartPhone(int dI,bool s,float ss): Device(dI,s), screensize(ss){}
void details(){
Device::details();
cout << "Screen Size in cm: " << screensize << endl;
}
};

class Smartwatch:public Device{
    public:
    bool HeartRateMonitor;
    Smartwatch(int dI,bool s,float hrm): Device(dI,s), HeartRateMonitor(hrm){}
    void details(){
    if (HeartRateMonitor==1)
        cout << "Heart Rate Monitor: Yes" << endl;
        else cout << "Heart Rate Monitor: No" << endl;
    }
};

class SmartWearable:public SmartPhone,public Smartwatch{
public:
int stepCounter;
SmartWearable(int dI,bool s,float ss,float hrm,int sc) : SmartPhone(dI,s,ss) , Smartwatch(dI,s,hrm) , stepCounter(sc){}
void details(){
    SmartPhone::details();
    Smartwatch::details();
    cout << "Step Counter: " << stepCounter << endl;
}
};

int main(){
SmartWearable W1(756,true,15.21,true,150);
W1.details();
return 0;
}
