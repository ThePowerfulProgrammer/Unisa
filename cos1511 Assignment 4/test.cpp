#include <iostream>
using namespace std;


void displayTicket(string name, string surname, string flightTimes[][2], int flightTime) {
    cout << "**************************" << endl;
    cout << "Travel ticket for FLIGHT " << endl;
    cout << "**************************" << endl;
    cout << "Name            :    " << name << " " << surname ;
    cout << "                                  Seat No            : " << "A1" << endl;
    cout << "Departure       :    " << "Johannesburg" << "                                    Departure Time     : " << "7:00" << endl;
    
    switch (flightTime) {
        case 1:
            cout << "Destination     :    " << "Cape Town" << "                                       Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 2:
            cout << "Destination     :    " << "Cape Town" << "                                       Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 3:
            cout << "Destination     :    " << "Cape Town" << "                                       Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 4:
            cout << "Destination     :    " << "Cape Town" << "                                       Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
        case 5:
            cout << "Destination     :    " << "Cape Town" << "                                       Arrival Time       : " << flightTimes[flightTime-1][1] << endl;
            break;
    }
    cout << "************************" << endl;
    cout << "Amount: R" << 1920.0 << " Thank you for booking with COS1511. Your travel agents for queries is Annie Mathew" << endl;
    cout << "************************" << endl;

}


int main() {
    string flightTimes[5][2] = {{"7:00","9:30"},{"9:00","11:30"},{"11:00", "13:30"},{"13:00", "15:30"},{"15:00", "17:30"}};
    string name;
    string surname;
    int flightTime;

    displayTicket("Ashish", "Ramnath", flightTimes, 2);


    return 0;
}

Create struct
create flight object
greet user
user name and surname
display flight flightTimes
user input -> flightTime
Display seats for flightTime
Book seat 
assigns value to Flight
display ticket
