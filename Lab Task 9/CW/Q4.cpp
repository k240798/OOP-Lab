#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string flightNum, string dep, string arr, int cap)
        : flightNumber(flightNum), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            cout << "Seat booked successfully on flight " << flightNumber << "\n";
            return true;
        } else {
            cout << "No available seats on flight " << flightNumber << "\n";
            return false;
        }
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            cout << "Seat canceled successfully on flight " << flightNumber << "\n";
            return true;
        } else {
            cout << "No booked seats to cancel on flight " << flightNumber << "\n";
            return false;
        }
    }

    bool upgradeSeat() {
        if (bookedSeats > 0) {
            cout << "Seat upgraded successfully on flight " << flightNumber << "\n";
            return true;
        } else {
            cout << "No booked seats to upgrade on flight " << flightNumber << "\n";
            return false;
        }
    }

    int getBookedSeats() const { return bookedSeats; }
    int getAvailableSeats() const { return capacity - bookedSeats; }
    string getFlightNumber() const { return flightNumber; }
};

class Passenger {
private:
    string name;
    string passengerID;

public:
    Passenger(string passengerName, string id) : name(passengerName), passengerID(id) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat()) {
            cout << name << " successfully booked a seat on flight " << flight.getFlightNumber() << "\n";
        } else {
            cout << "Booking failed for " << name << " on flight " << flight.getFlightNumber() << "\n";
        }
    }

    void requestCancellation(Flight& flight) {
        if (flight.cancelSeat()) {
            cout << name << " successfully canceled a seat on flight " << flight.getFlightNumber() << "\n";
        } else {
            cout << "Cancellation failed for " << name << " on flight " << flight.getFlightNumber() << "\n";
        }
    }

    void requestUpgrade(Flight& flight) {
        if (flight.upgradeSeat()) {
            cout << name << " successfully upgraded their seat on flight " << flight.getFlightNumber() << "\n";
        } else {
            cout << "Upgrade failed for " << name << " on flight " << flight.getFlightNumber() << "\n";
        }
    }
};

int main() {
    Flight flight1("EK73", "New York", "Dubai", 5);
    Flight flight2("QR756", "Chicago", "Doha", 3); 

    Passenger passenger1("Rasheed Ahmed", "ID001");
    Passenger passenger2("Qasim Gangohi", "ID002");
    Passenger passenger3("Zaheer Nanotvi", "ID003");
    Passenger passenger4("Ahmed Raza", "ID004");
    Passenger passenger5("Syed Ahmed", "ID005");
    Passenger passenger6("Shah Wali", "ID006");

    passenger1.requestBooking(flight1); 
    passenger2.requestBooking(flight1); 
    passenger3.requestBooking(flight1); 
    passenger4.requestBooking(flight1); 
    passenger5.requestBooking(flight1); 
    passenger6.requestBooking(flight1); // Should fail since there are no seats available

    passenger2.requestCancellation(flight1);

    passenger3.requestUpgrade(flight1);
    // Trying to cancel a non-existing booking
    passenger6.requestCancellation(flight1); // Should fail as passenger 6 is not booked onto flight1

    // Try to upgrade a non-existing booking
    passenger6.requestUpgrade(flight1); // Should fail as p6 is not booked onto flight1

    return 0;
}
