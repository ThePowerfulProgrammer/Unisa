#include <iostream>

using namespace std;



// main Program 
string mainProgram(string departures[], string arrivals[]) {
    string name;
    string surname;

    cout << "Enter full name" << endl;
    cin >> name >> surname ;

    cout << "The available travel times for flights are " << endl;
    // travel times --> does nothing
    cout << "    Depart   Arrive" << endl;
    for (int i = 0; i < 5; i++) {
        if (i < 2) {
            cout << i << ".  " << arrivals[i] << "     " << departures[i] << endl;
        }
        else {
            cout << i << ".  " << arrivals[i] << "    " << departures[i] << endl;
        }
    }

    return "";
}

int main() {
    // allowed global vars + size of any other arrays
    float economyTicket = 1600.00;
    string arrivals[5] = {"7:00", "9:00", "11:00", "13:00", "15:00"};
    string departures[5] = {"9:30","11:30", "13:30", "15:30", "17:30"};

    cout << "Welcome to COS1511 Flight Booking system " << endl << endl;
    cout << mainProgram(departures, arrivals);

}