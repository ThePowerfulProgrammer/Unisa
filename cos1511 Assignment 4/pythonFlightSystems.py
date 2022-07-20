flight_route = "JHB CPT"
flight_time = 2.5
total_seats = 50

class flight:
    def __init__(self,time):
        self.time = time
        self.seats = {1:{1:"A1",2:"A2",3:"A3"},2:{4:"A4",5:"A5",6:"A6"},
                     3:{7:"B1",8:"B2",9:"B3"},4:{10:"B4",11:"B5",12:"B6"},
                     5:{13:"C1",14:"C2",15:"C3"},6:{16:"C4",17:"C5",18:"C6"},
                     7:{19:"D1",20:"D2",21:"D3"},8:{22:"D4",23:"D5",24:"D6"},
                     9:{25:"E1",26:"E2",27:"E3"},10:{28:"E4",29:"E5",30:"E6"},
                     11:{31:"F1",32:"F2",33:"F3"},12:{34:"F4",35:"F5",36:"F6"},
                     13:{37:"G1",38:"G2",39:"G3"},14:{40:"G4",41:"G5",42:"G6"},
                     15:{43:"H1",44:"H2",45:"H3"},16:{46:"H4",47:"H5",48:"H6"},
                     17:{49:"I1",50:"I2"}
                     }
    
    def get_seat(self):
        count = 1
        for dic in self.seats.values():
            for seatN in dic:
                print(dic[seatN], end="|")
                if (count == 3 or count == 9 or count == 15 or count == 21 or count == 27 or count == 33 or count == 39 or 
                    count == 45): 
                    print("---", end="|")
                if (count == 6 or count == 12 or count  == 18 or count == 24 or count == 30 or count  == 36 
                   or count == 42 or count == 48):
                    print()
                count += 1                
        return ""
        
    def book_seat(self, seat_number):
        for dictionary in self.seats.values():    
            for seatN in dictionary:
                if (seat_number == dictionary[seatN]):
                    dictionary[seatN] = "**"
                

    

flight1 = flight("7:00")
flight2 = flight("9:00")
flight3 = flight("11:00")
flight4 = flight("13:00")
flight5 = flight("15:00")

def flights_available():
    print("     Depart   Arrival")
    print("1.   7:00    9:30")
    print("2.   9:00    11:30")
    print("3.   11:00   13:30")
    print("4.   13:00   15:30")
    print("5.   15:00   17:30")

    return 0

# begin
start = 1
while (start != 0):
    print("Welcome to COS1511 Flight Booking system")
    print("Enter fullname ")
    name = input("")

    # 1st available flight times
    print("The available travel travel times for flights are ")
    flights_available()

    # Choose flight times
    print("Choose the time by entering the option number from the given list")
    flight_number = int(input(""))
    while (flight_number < 1 or flight_number > 5):
        print("Incorrect option! Please choose from 1-5")
        flight_number = int(input(""))

    # Issue 5 flights all with mutabilty -> Must be able to book seats using ** 
    # Create a flight object? --> Classes
    print("Please key in a seat number to choose a seat(eg:A2)")
    seat_number = input()
    if (flight_number == 1):
        flight1.book_seat(seat_number)
    elif (flight_number == 2):
        flight2.book_seat(seat_number)
    elif (flight_number == 3):
        flight3.book_seat(seat_number)
    elif (flight_number == 4):
        flight4.book_seat(seat_number)
    else:
        flight5.book_seat(seat_number)
        
    print("Would you like to book another seat? 1 for yes 0 for no ")
    start = int(input())