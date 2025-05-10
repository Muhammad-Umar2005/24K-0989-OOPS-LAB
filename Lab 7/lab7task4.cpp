#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr) : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Contact: " << contactNumber << ", Address: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddr) {
        contactNumber = newContact;
        address = newAddr;
        cout << "Updated Contact: " << contactNumber << ", Updated Address: " << address << endl;
    }
};

class Patient : public Person {
private:
    string patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string addr, string id, string history, string doctor) : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << ", Medical History: " << medicalHistory << ", Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    float consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string addr, string spec, float fee) : Person(n, a, contact, addr), specialization(spec), consultationFee(fee) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << ", Consultation Fee: " << consultationFee << endl;
        cout << "Patients List: " << patientsList << endl;
    }

    void addPatient(string patient) {
        patientsList += patient + " ";
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << ", Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    float salary;

public:
    Administrator(string n, int a, string contact, string addr, string dept, float sal) : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddr) override {
        Person::updateInfo(newContact, newAddr);
        cout << "Updated Department: " << department << ", Updated Salary: " << salary << endl;
    }
};

int main() {
    Patient patient("Waseem Khan", 30, "0331-7218490", "Bangla Towers", "P001", "Diabetes", "Dr. Ambreen");
    Doctor doctor("Dr. Ambreen", 45, "0341-4323127", "Ayesha Manzil", "Cardiology", 150.0f);
    Nurse nurse("Ms.Asma Zubair", 35, "0332-7643211", "Nagan Chrowangi", "Ward A", "9 AM - 5 PM");
    Administrator admin("Wasay Khan", 40, "0321-9087654", "DHA", "HR", 50000.0f);

    patient.displayInfo();
    doctor.displayInfo();
    nurse.displayInfo();
    admin.displayInfo();

    doctor.addPatient("P002");
    doctor.displayInfo();

    admin.updateInfo("0321-5432121", "R-212 Rashid Minhas Road");
    admin.displayInfo();

    return 0;
}