#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID;
    string passengerName;
    float price;
    string date;
    string destination;

public:
    Ticket(string id, string name, float p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << endl;
    }

    virtual void cancel() {
        cout << "Ticket canceled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << ", Passenger: " << passengerName << ", Price: " << price << ", Date: " << date << ", Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(string id, string name, float p, string d, string dest, string airline, string flightNum, string seat) : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flightNum), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << ", Flight Number: " << flightNumber << ", Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(string id, string name, float p, string d, string dest, string trainNum, string coach, string depTime) : Ticket(id, name, p, d, dest), trainNumber(trainNum), coachType(coach), departureTime(depTime) {}

    void reserve() override {
        Ticket::reserve();
        cout << "Seat automatically assigned." << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(string id, string name, float p, string d, string dest, string company, int seat) : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        Ticket::cancel();
        cout << "Last-minute refund processed." << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(string id, string name, float p, string d, string dest, string artist, string v, string seat) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << ", Venue: " << venue << ", Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight("FT001", "Salman Hassan", 500.0f, "2025-06-15", "Lahore", "PIA", "FL123", "Economy");
    TrainTicket train("TT001", "Muhammad Ahmed Hussain", 100.0f, "2025-06-16", "Padidan", "Pakistan Express", "First Class", "10:00 AM");
    BusTicket bus("BT001", "Aiman Khan", 50.0f, "2025-06-17", "Multan", "Adil Shah Coach", 25);
    ConcertTicket concert("CT001", "Daniel", 200.0f, "2025-06-18", "Islamabad", "Singer", "G-10", "VIP");

    flight.reserve();
    flight.displayTicketInfo();

    train.reserve();
    train.displayTicketInfo();

    bus.cancel();
    bus.displayTicketInfo();

    concert.displayTicketInfo();

    return 0;
}