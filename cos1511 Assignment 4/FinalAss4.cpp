#include <iostream>

using namespace std; 

// struct 
struct Flight {
    int flightNumber;           // five flights(1-5)
    string seats[50];           // Each flight will be assigned 50 unique seats
    string bookedSeats[50];     // seats that have been booked
    int bookings = 0 ;          // Number bookings presented at end
    float cost;                 // assigned using economyTicket
    string travelTicketClass;   // Economy/First class
    string bookedSeat;          // Chosen seat, changed for each book
    string flightTime;          // 7.00 -> 15.00
};

// function to choose flightTime -> flight1-flight5 based on time -> validates user input on flight number 
int bookFlight(int & flightTime) {
    cout << "Choose the correct time by entering the option from the displayed list:" << endl;
    // validation:
    cin >> flightTime;
    while (flightTime < 1 || flightTime > 5) {
        cout << "Incorrect option! Please choose from 1-5." << endl;
        cin >> flightTime;
    }
    return flightTime;
}

// function to display time options && read and validate user input
void displayFlightTimes(const string flightTimes[][2]) {
    int flightTime;
    cout << "The available travel times for flights are " << endl;
    cout << "    Depart   Arrive" << endl;

    for (int i = 0; i<5;i++) {
        if (i < 2) {
            cout << i+1 << ".  " << flightTimes[i][0] << "     " << flightTimes[i][1] << endl;
        }
        else {
            cout << i+1 << ".  " << flightTimes[i][0] << "    " << flightTimes[i][1] << endl;
        }
    }
    cout << endl;

    flightTime = bookFlight(flightTime);
    cout << flightTime << endl;

}

int main() {
    // allowed global vars + size of any other arrays
    float economyTicket = 1600.00;
    const string flightTimes[5][2] = {{"7:00","9:30"},{"9:00","11:30"},{"11:00", "13:30"},{"13:00", "15:30"},{"15:00", "17:30"}};

    cout << "Welcome to COS1511 Flight Booking system " << endl << endl;
}