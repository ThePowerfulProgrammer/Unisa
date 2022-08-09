#include <iostream>
#include <string>
using namespace std;


struct Flight {
    int flightNumber; // 1 - 5
    string seats[50]; // A1 - I2
    int bookings; // Number bookings presented at end
    float cost; // Economy/First class
    string bookedSeat; // Chosen seat, changed for each book
}

// main Program 
string mainProgram(string flightTimes[][2]) {
    string name;
    string surname;

    cout << "Enter full name" << endl;
    cin >> name >> surname ;

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

    return "";
}

int main() {
    // allowed global vars + size of any other arrays
    float economyTicket = 1600.00;
    string flightTimes[5][2] = {{"7:00","9:30"},{"9:00","11:30"},{"11:00", "13:30"},{"13:00", "15:30"},{"15:00", "17:30"}};

    cout << "Welcome to COS1511 Flight Booking system " << endl << endl;
    cout << mainProgram(flightTimes);

    string rows[9] = {"A","B","C", "D", "E", "F", "G", "H", "I"};
    
    /*
    for (int i = 0; i<9;i++) {
        for (int j=0; j<6; j++) {
            cout << rows[i] << to_string(j+1) << "   " << endl;
        }
    }*/

    return 0;
}