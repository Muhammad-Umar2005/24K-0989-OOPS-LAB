#include <iostream>
#include <string>
using namespace std;

class WeatherSensor{
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer:public WeatherSensor{
public:
    void readData(){
        cout << "Thermometer: Reading temperature data..." << endl;
    }

    void displayReport(){
        cout << "Thermometer: Displaying temperature report - 25°C" << endl;
    }
};

class Barometer:public WeatherSensor{
public:
    void readData(){
        cout << "Barometer: Reading barometric pressure data..." << endl;
    }

    void displayReport(){
        cout << "Barometer: Displaying barometric pressure report - 1013 hPa" << endl;
    }
};

class Hygrometer:public WeatherSensor{
public:
    void readData(){
        cout << "Hygrometer: Reading humidity data..." << endl;
    }

    void displayReport(){
        cout << "Hygrometer: Displaying humidity report - 45%" << endl;
    }
};


int main() {
    WeatherSensor *W1=new Thermometer();
    W1->readData();
    W1->displayReport();

    W1=new Barometer();
    W1->readData();
    W1->displayReport();

    W1=new Hygrometer();
    W1->readData();
    W1->displayReport();

    delete W1;
    return 0;
}