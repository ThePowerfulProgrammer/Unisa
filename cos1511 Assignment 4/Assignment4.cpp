#include <iostream>
#include <string>
using namespace std;


struct Flight {
    int flightNumber; // 1 - 5
    string seats[50]; // A1 - I2
    int bookings; // Number bookings presented at end
    float cost; // Economy/First class
    string bookedSeat; // Chosen seat, changed for each book
};

// add A1-I2 to flight.seats[]
void addSeats(Flight & flight) {
    string rows[9] = {"A","B","C", "D", "E", "F", "G", "H", "I"};
    int seat = 0;
    
    // Adds A1 - H6
    for (int i = 0; i<8;i++) {
        for (int j=0; j<6; j++) {
            string seatNo = "";
            seatNo += rows[i];
            seatNo += to_string(j+1);
            flight.seats[seat] = seatNo;
            seat ++;
        }
    }
    // Adds I1 - I2
    for (int i = 0;i<1;i++) {
        for (int j = 0; j<2; j++) {
            string seatNo = "";
            seatNo += rows[i+8];
            seatNo += to_string(j+1);
            flight.seats[seat] = seatNo;
            seat ++;
        }
    }
}

void displaySeats(Flight & flight) {
    cout << "First class(1920.00)" << endl;
    for (int i=0;i<50;i++) {
        if (i == 24) {cout << "Economy class(1600.00)" << endl;}
        cout << "|" << flight.seats[i] << "|";
        if (i+1 == 3 || i+1 == 9 || i+1 == 15 || i+1 == 21 || i+1 == 27 || i+1 == 33 || i+1 == 39 || i+1 == 45) {
            cout << "---" ;
        }
        if (i == 5 || i == 11 || i == 17 || i == 23 || i == 29 || i == 35 || i == 41 || i == 47) {
            cout << endl;
        }
    }
}

// display flighttimes
void displayFlightTimes(string flightTimes[][2]) {
    cout << "The available travel times for flights are " << endl;
    // travel times --> does nothing
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

}

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

// main Program 
string mainProgram(string flightTimes[][2]) {
    string name;
    string surname;
    int flightTime;
    Flight flight1;
    Flight flight2;
    Flight flight3;
    Flight flight4;
    Flight flight5;
    // add seats 
    addSeats(flight1);
    addSeats(flight2);
    addSeats(flight3);
    addSeats(flight4);
    addSeats(flight5);

    cout << "Enter full name" << endl;
    cin >> name >> surname ;

    displayFlightTimes(flightTimes);
    flightTime = bookFlight(flightTime);

    // display seats for specifc flight
    switch (flightTime) {
        case 1:
            cout << "The available flights for " << flightTimes[0][0] << " are as follows:" << endl;
            displaySeats(flight1);
            break;
        case 2:
            cout << "The available flights for " << flightTimes[1][0] << " are as follows:" << endl;
            displaySeats(flight2);
            break;
        case 3:
            cout << "The available flights for " << flightTimes[2][0] << " are as follows:" << endl;
            displaySeats(flight3);
            break;
        case 4:
            cout << "The available flights for " << flightTimes[3][0] << " are as follows:" << endl;
            displaySeats(flight4);
            break;
        case 5:
            cout << "The available flights for " << flightTimes[4][0] << " are as follows:" << endl;
            displaySeats(flight5);
            break;
    }



    return "";
}

int main() {
    // allowed global vars + size of any other arrays
    float economyTicket = 1600.00;
    string flightTimes[5][2] = {{"7:00","9:30"},{"9:00","11:30"},{"11:00", "13:30"},{"13:00", "15:30"},{"15:00", "17:30"}};

    cout << "Welcome to COS1511 Flight Booking system " << endl << endl;
    cout << mainProgram(flightTimes);

    return 0;
}