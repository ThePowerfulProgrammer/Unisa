#include <iostream>

using namespace std; 

// struct 
struct Flight {
    int flightNumber;           // five flights(1-5)
    string seats[50];           // Each flight will be assigned 50 unique seats
    string bookedSeats[50];     // seats that have been booked -> Added after each successful book
    int bookings = 0 ;          // Number bookings presented at end 
    float cost;                 // assigned using economyTicket
    string travelTicketClass;   // Economy/First class
    string bookedSeat;          // Chosen seat, changed for each book
    string flightTime;          // 7.00 -> 15.00
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

// function to book flightTime -> flight1-flight5 based on time -> validates user input on flight number 
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
int displayFlightTimes(const string flightTimes[][2]) {
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
    return flightTime;
}




// displays seats A1-I2 work PRE booking and POST booking by making use of an additional array, assuming I do not need to print values using economyTicket :)
void displaySeats(Flight & flight) {
    cout << "First class(1920.00)" << endl;
    
    // for loop to print seats 
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

// functions that works with bookSeat function -> returns a value used to validate chosen seat
bool checkBookedSeats(Flight & flight, string & seat) {
    for (int i = 0;i<50;i++) {
        if (seat == flight.bookedSeats[i]) {
            return true;
        } 
    }
    return false;
   
}

// function to validate and book seat based on user input --> Adds additional info for Flight
void bookSeat(Flight & flight, int economyTicket) {
    // get seat
    cout.setf(ios::fixed);
    cout.precision(2);
    int n=0; // used to add to booked array
    string seat;
    cout << "Please key in a seat number to choose a seat(eg:A2)" << endl;
    cin >> seat;

    // while loop to validate seat 
    while (checkBookedSeats(flight, seat)) {
        cout <<  "Sorry that seat is taken. Please choose a seat that is available" << endl;
        cin >> seat;
    }
    
    // if seat free --> Book seat, add cost of flight, set travelClass, and add 1 to number of bookings, ASSUMES user does not choose seat outside A1-I2, not stated to validate in pdf
    for (int i = 0; i<50;i++) {
        if (seat == flight.seats[i]) {
            flight.seats[i] = "**";
            flight.bookedSeat = seat;
            if (i <= 23) {
                flight.cost = economyTicket + (economyTicket * 0.20);
                flight.travelTicketClass = "First class";
            } 
            else { 
                flight.cost = economyTicket;
                flight.travelTicketClass = "Economy class";
            }
            flight.bookings += 1;
        }
    }
    // add seat to bookedSeats
    flight.bookedSeats[n] = seat;
    n +=1;
}


// function to displayTicket reduces redundancy -> needs work done on spacing
void displayTicket(string & name, string & surname, Flight & flight, const string flightTimes[][2], int & flightTime) {
    cout << "**************************" << endl;
    cout << "Travel ticket for FLIGHT " << endl;
    cout << "**************************" << endl;
    cout << "Name            :    " << name << " " << surname ;
    cout << "                                     " << "Travel ticket class: " << flight.travelTicketClass << endl;


    cout << "                                                                       Seat No            : " << flight.bookedSeat << endl;
    cout << "Departure       :    " << "Johannesburg" << "                                      Departure Time     : " << flight.flightTime << endl;
    
    switch (flightTime) {
        case 1:
            cout << "Destination     :    " << "Cape Town" << "                                         Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 2:
            cout << "Destination     :    " << "Cape Town" << "                                         Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 3:
            cout << "Destination     :    " << "Cape Town" << "                                         Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 4:
            cout << "Destination     :    " << "Cape Town" << "                                         Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 5:
            cout << "Destination     :    " << "Cape Town" << "                                         Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
    }
    cout << "************************" << endl;
    cout << "Amount: R" << flight.cost << " Thank you for booking with COS1511. Your travel agents for queries is Annie Mathew" << endl;
    cout << "************************" << endl;

}


int main() {
    // allowed gloval vars But I will not use any 
    // all variables here are local to main()
    float economyTicket = 1600.00;
    const string flightTimes[5][2] = {{"7:00","9:30"},{"9:00","11:30"},{"11:00", "13:30"},{"13:00", "15:30"},{"15:00", "17:30"}};
    string name;
    string surname;
    int flightTime;
    
    // create 5 flight objects
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
    // add flightTime
    flight1.flightTime = "7.00";
    flight2.flightTime = "9.00";
    flight3.flightTime = "11.00";
    flight4.flightTime = "13.00";
    flight5.flightTime = "15.00";

    string moreBookings; // variable to Continue loop
    
    cout << "Welcome to COS1511 Flight Booking system " << endl << endl;
    
    // do while loop
    do {
        // get fullname
        cout << "Enter full name" << endl;
        cin >> name >> surname ;
    
        // display flight time and book flight
        flightTime = displayFlightTimes(flightTimes);
    
        // display seats for specific flight
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
    

        switch (flightTime) {
            case 1:
                bookSeat(flight1, economyTicket);
                break;
            case 2:
                bookSeat(flight2, economyTicket);
                break;
            case 3:
                bookSeat(flight3, economyTicket);
                break;
            case 4:
                bookSeat(flight4, economyTicket);
                break;
            case 5:
                bookSeat(flight5, economyTicket);
                break;    
        }
        cout << endl;
    
        // Output ticket    
    
        switch (flightTime) {
            case 1:
                displayTicket(name, surname,flight1, flightTimes, flightTime);
                break;
            case 2:
                displayTicket(name, surname,flight2, flightTimes, flightTime);
                break;
            case 3:
                displayTicket(name, surname,flight3, flightTimes, flightTime);
                break;
            case 4:
                displayTicket(name, surname,flight4, flightTimes, flightTime);
                break;
            case 5:
                displayTicket(name, surname,flight5, flightTimes, flightTime);
                break;    
        }
        cout << "Do you want to make another booking(Y/N)?" << endl;
        cin >> moreBookings ;
    } while ((moreBookings != "N") && (moreBookings !="No") && (moreBookings != "no"));
        
    cout << "Number of bookings made for 7.00 a.m:" << flight1.bookings << endl;
    cout << "Number of bookings made for 9.00 a.m:" << flight2.bookings << endl;
    cout << "Number of bookings made for 11.00 a.m:" << flight3.bookings << endl;
    cout << "Number of bookings made for 13.00 p.m:" << flight4.bookings << endl;
    cout << "Number of bookings made for 15.00 p.m:" << flight5.bookings << endl;


    

    return 0;
}