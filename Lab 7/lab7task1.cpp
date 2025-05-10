#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(string id, string name, bool stat, string loc) : deviceID(id), deviceName(name), status(stat), location(loc) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " turned on." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " turned off." << endl;
    }

    virtual string getStatus() {
        return status ? "On" : "Off";
    }

    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << ", Name: " << deviceName << ", Status: " << getStatus() << ", Location: " << location << endl;
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(string id, string name, bool stat, string loc, int brightness, string color) : Device(id, name, stat, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << ", Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(string id, string name, bool stat, string loc, float temp, string mod, float targetTemp) : Device(id, name, stat, loc), temperature(temp), mode(mod), targetTemperature(targetTemp) {}

    string getStatus() override {
        return "Current Temperature: " + to_string(temperature) + "°C, Mode: " + mode;
    }
};

class SecurityCamera : public Device {
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(string id, string name, bool stat, string loc, int res, bool rec, bool nightVision) : Device(id, name, stat, loc), resolution(res), recordingStatus(rec), nightVisionEnabled(nightVision) {}

    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << deviceName << " started recording." << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    string timerSetting;

public:
    SmartPlug(string id, string name, bool stat, string loc, float power, string timer) : Device(id, name, stat, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        Device::turnOff();
        cout << "Logged power usage: " << powerConsumption << "W" << endl;
    }
};

int main() {
    Light light("L001", "Living Room Light", false, "Living Room", 70, "Warm");
    light.turnOn();
    light.displayInfo();

    Thermostat thermostat("T001", "Living Room Thermostat", false, "Living Room", 22.5, "Cooling", 20.0);
    thermostat.turnOn();
    cout << "Thermostat Status: " << thermostat.getStatus() << endl;

    SecurityCamera camera("C001", "Front Door Camera", false, "Front Door", 1080, false, true);
    camera.turnOn();

    SmartPlug plug("P001", "Desk Lamp Plug", false, "Office", 50.0, "18:00");
    plug.turnOn();
    plug.turnOff();

    return 0;
}