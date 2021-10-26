#include <iostream>
#include <fstream>
#include <iomanip>
//////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;

// Function Prototype
void CallSeatCancel();

// Array to Store the Seating Info
char bSeatingArray[9][7];
char fSeatingArray[9][7];
char eSeatingArray[9][7];

// Booking class
class Booking {
    private:
        static int eBookSeats;
        static int bBookSeats;
        static int fBookSeats;
        char usrChoice;
        char seat;
        int seatColumn;
        int row;
        char userChoice;
        int condition;
        string lOne, lTwo, lThree;

    public:
        void BussinessClass();
        void FirstClass();
        void EconomyClass();
        void GetUserSeat();
        char GetUserChoice();
        void BookSeat();
        void Initialize();
        void StoreData();
        int GetBusinessSeats();
        int GetFirstSeats();
        int GetEconomySeats();
        void SeatCancel();
        void CountBookedSeats();
        void ResetData();
        void Resetter(string fileName);
        void DisplayBSeats();
        void DisplayFSeats();
        void DisplayESeats();
        string OpenFile(string fileName);
        Booking();
};

// Static Variables Initialization
int Booking::eBookSeats = 0;
int Booking::bBookSeats = 0;
int Booking::fBookSeats = 0;

// Constructor
Booking::Booking(){}

void Booking::Resetter(string fileName) {
    ofstream fout;
    fout.open(fileName);
    for (int i = 0; i < (7 * 9); i++) {
        fout << 'X';
    }
    fout.close();
}

void Booking::ResetData() {
    Resetter("bussiness-class-seating.txt");
    Resetter("first-class-seating.txt");
    Resetter("economy-class-seating.txt");
}

// Function to Count the Booked Seats
void Booking::CountBookedSeats() {
    // Bussiness CLASS booked seats count
    Booking::eBookSeats = 0;
    Booking::bBookSeats = 0;
    Booking::fBookSeats = 0;
    for (int i = 0; lOne[i] != '\0'; i++) {
        if (lOne[i] == '*')
            Booking::bBookSeats += 1;
    }
    // First Class Booked Seats count
    for (int i = 0; lTwo[i] != '\0'; i++) {
        if (lTwo[i] == '*') 
            Booking::fBookSeats += 1;
    }
    // cout << Booking::fBookSeats << endl;
    // Economy Class Booked Seats Count
    for (int i = 0; lThree[i] != '\0'; i++) {
        if (lThree[i] == '*')
            Booking::eBookSeats += 1;
    }
}

string Booking::OpenFile(string fileName) {
    string line;
    ifstream fin;
    fin.open(fileName);
    getline(fin, line);
    return line;
}

// Function to pick the Data from a file and store in the 2-D array
void Booking::Initialize() {
    int inc = 0;
    lOne = OpenFile("bussiness-class-seating.txt");
    lTwo = OpenFile("first-class-seating.txt");
    lThree = OpenFile("economy-class-seating.txt");
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            bSeatingArray[row][col] = lOne[inc];
            fSeatingArray[row][col] = lTwo[inc];
            eSeatingArray[row][col] = lThree[inc];
            inc++;
        }
    }

}

// Business Class Booking Function
void Booking::BussinessClass() {
    cout << "|| WELCOME TO BUSINESS CLASS BOOKING TICKET || \n\n";
    DisplayBSeats();
    condition = true;
    GetUserSeat();

    while (condition) {
        if (bSeatingArray[row][seatColumn] == 'X') {
            bSeatingArray[row][seatColumn] = '*';
            cout << "Your Seat is Booked" << endl;
            condition = false;
            StoreData();
        }
        else {
            cout << "This Seat is Already Booked by another Passenger! Try Another One" << endl;
            GetUserSeat();
        }
    }
    DisplayBSeats();
}
// function to display Seats of Bussiness Class
void Booking::DisplayBSeats() {
     cout << "\n            A       B       C              D       E       F\n\n";
    for (int row = 0; row < 9; row++)
    {
        cout << "Row " << left << setw(3) << row + 1 << ": ";
        for (int col = 0; col < 7; col++)
        {
            if (col == 3)
            {
                cout << "\t";
                continue;
            }
            cout.width(4);
            cout << right << bSeatingArray[row][col] << "    ";
        }
        cout << "\n\n";
    }
}

// End of Business Class Booking Function

// First Class Booking Function

void Booking::DisplayFSeats() {
    cout << "\n            A       B       C              D       E       F\n\n";
    for (int row = 0; row < 9; row++) {
        cout << "Row " << left << setw(3) << row + 1 << ": ";
        for (int col = 0; col < 7; col++) {
            if (col == 3) {
                cout << "\t";
                continue;
            }
            cout.width(4);
            cout << right << fSeatingArray[row][col] << "    ";
        }
        cout << "\n\n";
    }

}
void Booking::FirstClass() {
    cout << "|| WELCOME TO THE FIRST CLASS BOOKING || \n\n";
    DisplayFSeats();
    condition = true;
    GetUserSeat();

    while (condition) {
        if (fSeatingArray[row][seatColumn] == 'X') {
            fSeatingArray[row][seatColumn] = '*';
            cout << "Your Seat is Booked" << endl;
            condition = false;
            StoreData();
        }
        else {
            cout << "This Seat is Already Booked by another Passenger! Try Another One" << endl;
            GetUserSeat();
        }
    }
    DisplayFSeats();
}

// End of First Class Booking Function

// Economy Class Booking Function

void Booking::DisplayESeats() {
    cout << "\n            A       B       C              D       E       F\n\n";
    for (int row = 0; row < 9; row++) {
        cout << "Row " << left << setw(3) << row + 1 << ": ";
        for (int col = 0; col < 7; col++) {
            if (col == 3) {
                cout << "\t";
                continue;
            }
            cout.width(4);
            cout << right << eSeatingArray[row][col] << "    ";
        }
        cout << "\n\n";
    }
}

void Booking::EconomyClass() {
    cout << "\n\n";
    cout << "|| WELCOME TO THE ECONOMY CLASS BOOKING || \n\n";
    DisplayESeats();

    condition = true;
    GetUserSeat();

    while (condition) {
        if (eSeatingArray[row][seatColumn] == 'X') {
            eSeatingArray[row][seatColumn] = '*';
            cout << "Your Seat is Booked" << endl;
            condition = false;
            StoreData();
        }
        else {
            cout << "This Seat is Already Booked by another Passenger! Try Another One" << endl;
            GetUserSeat();
        }
    }
    DisplayESeats();
}

// End of Economy Class Booking Function

// Function to Get Input from user of Row Number and Column Number
void Booking::GetUserSeat() {
    cout << "Enter the Row Number: ";
    cin >> row;

    cout << "Enter the Column Name ( A || B ... || F ): ";
    cin >> seat;
    // Column Logic
    if (seat == 'A')
        seatColumn = 0;
    else if (seat == 'B')
        seatColumn = 1;
    else if (seat == 'C')
        seatColumn = 2;
    else if (seat == 'D')
        seatColumn = 4;
    else if (seat == 'E')
        seatColumn = 5;
    else if (seat == 'F')
        seatColumn = 6;
    row -= 1;
}

// Function that will Get Input from User Which type of ticket user Want
char Booking::GetUserChoice() {
    cout << "Enter What you Want to Select Business || FirstClass || EconomyClass (B || F || E ):   ";
    cin >> usrChoice;
    return usrChoice;
}

// Function to Book Seats
void Booking::BookSeat() {
    char temp;
    Initialize();
    char userChoice = GetUserChoice();

    if (userChoice == 'B') {
        do {
            BussinessClass();
            cout << "Do You Want to Book the Seat: (Y || N) : ";
            cin >> temp;
            if (temp == 'N' || temp == 'n') {
                cout << " ||        Thanks for Coming          ||" << endl;
                break;
            }
        } while (true);
    }

    else if (userChoice == 'F') {
        do {
            FirstClass();
            cout << "Do You Want to Book the Seat: (Y || N) : ";
            cin >> temp;
            if (temp == 'N' || temp == 'n')  {
                cout << " ||        Thanks for Coming          ||" << endl;
                break;
            }
        } while (true);
    }

    else if (userChoice == 'E') {
        do {
            EconomyClass();
            cout << "Do You Want to Book the Seat: (Y || N) : ";
            cin >> temp;
            if (temp == 'N' || temp == 'n') {
                cout << " ||        Thanks for Coming          ||" << endl;
                break;
            }
        } while (true);
    }
}

// Function to Store the Data in the file
void Booking::StoreData() {
    ofstream fout;
    fout.open("bussiness-class-seating.txt");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 7; col++) {
            if (col == 3) {
                fout << "\t";
                continue;
            }
            fout << bSeatingArray[row][col];
        }
    }
    fout.close();

    ofstream foout;
    foout.open("first-class-seating.txt");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 7; col++) {
            if (col == 3) {
                foout << "\t";
                continue;
            }
            foout << fSeatingArray[row][col];
        }
    }
    foout.close();

    ofstream fouut;
    fouut.open("economy-class-seating.txt");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 7; col++) {
            if (col == 3) {
                fouut << "\t";
                continue;
            }
            fouut << eSeatingArray[row][col];
        }
    }
    fouut.close();
}

// Function that will tell about the Booked Seats
int Booking::GetBusinessSeats() {
    OpenFile("bussiness-class-seating.txt");
    Initialize();
    CountBookedSeats();
    return Booking::bBookSeats;
}

int Booking::GetFirstSeats() {
    OpenFile("first-class-seating.txt");
    Initialize();
    CountBookedSeats();
    return Booking::fBookSeats;
}

int Booking::GetEconomySeats() {
    OpenFile("economy-class-seating.txt");
    Initialize();
    CountBookedSeats();
    return Booking::eBookSeats;
}

// Seat Cancellation
void Booking::SeatCancel() {
    char userChoice = GetUserChoice();
    GetUserSeat();
    condition = true;
    CountBookedSeats();
    Initialize();

    if (userChoice == 'B') {
        while (condition)
        {
            DisplayBSeats();
            if (Booking::bBookSeats == 0) {
                cout << "Sorry, There is no Seat Booked in this class!!!" << endl;
                break;
            }

            else if (bSeatingArray[row][seatColumn] == 'X')
            {
                cout << "This Seat is not Booked by any Passenger, Please select the Correct Seat" << endl;
                // DisplayBSeats();
                GetUserSeat();
            }
            else if (bSeatingArray[row][seatColumn] == '*')
            {
                bSeatingArray[row][seatColumn] = 'X';
                cout << "Your Booking has been cancelled!!!" << endl;
                DisplayBSeats();
                StoreData();
                condition = false;
            }
        }
    }

    else if (usrChoice == 'F') {
        while (condition) {
            // DisplayFSeats();
            if (Booking::fBookSeats == 0) {
                cout << "Sorry, there is no Booked Seat in this Class!!!" << endl;
                break;
            }

            else if (fSeatingArray[row][seatColumn] == 'X') {
                cout << "This Seat is not Booked by any Passenger, Please select the Correct Seat" << endl;
                DisplayFSeats();
                GetUserSeat();
            }
            else if (fSeatingArray[row][seatColumn] == '*') {
                fSeatingArray[row][seatColumn] = 'X';
                cout << "Your Booking has been cancelled!!!" << endl;
                DisplayFSeats();
                StoreData();
                condition = false;
            }
        }
    }

    else if (userChoice == 'E') {
        while (condition) {
            // DisplayESeats();
            if (Booking::eBookSeats == 0) {
                cout << "Sorry, there is no Seat Booked in this Class!!!" << endl;
                break;
            }

            else if (eSeatingArray[row][seatColumn] == 'X') {
                cout << "This Seat is not Booked by any Passenger, Please select the Correct Seat" << endl;
                DisplayESeats();
                GetUserSeat();
            }
            else if (eSeatingArray[row][seatColumn] == '*') {
                eSeatingArray[row][seatColumn] = 'X';
                cout << "Your Booking has been cancelled!!!" << endl;
                DisplayESeats();
                StoreData();
                condition = false;
            }
        }
    }
}
// Function to Reset the Seat info

void CallSeatCancel() {
    Booking b;
    b.Initialize();
    b.SeatCancel();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////