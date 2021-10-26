#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Header-Files/Sign-Up.h"
#include "Header-Files/Log-In.h"
#include "Header-Files/book-seat.h"

using namespace std;

// Globally declared array for Timing (change using arrays for loop)
string trainDetail[6];
bool _check = false;

// complaint guest check
string guestCheck = "No";

void Execute();

// Person Class

class Person{

    private:
        string userFName;
        string userLName;
        string id;

    public:
        void setName();
        void getName();
        Person();
};


// Setting Name
void Person::setName(){
    cout << "Enter your First Name: ";
        getline(cin, userFName);
    cout << "\nEnter your Last Name: ";
        getline(cin, userLName);
}

// For Getting Name
void Person::getName(){
    cout <<" Name: " << userFName << " " << userLName << endl;
}

Person::Person(){
    userFName = "admin";
    userLName = "aetooc";
}

// Person Class End

// Child Class Admin
class Admin : public Person{
    public:
        bool display();
        void CreateDataBase();
        void DisplayDataBase();
        void NewTrain();
        void SetNextTrainDetails();
        void DispaySuggestions();
        void DisplayComplaints();

    protected:
        string adminPass = "aetooc";        // Admin Password

};

bool Admin::display(){

        string password;
        cout << "Enter your Password: ";
        getline(cin, password);

        if ( password == adminPass ){
            cout << "Correct Password\nWelcome!!!\n";
            return true;
        }
        else{
            cout << "Incorrect! No access granted!";
            return false;
        }
    }

void Admin::CreateDataBase(){
    ifstream fin;
    fin.open("DataBase.csv");
    if(fin) {
        // cout<<"file exists";
   } else {
        ofstream fout;
        fout.open("DataBase.csv");
   }
}

void Admin::DisplayDataBase(){
    int i = 0;
    ifstream fin;
    fin.open("DataBase.csv");
    cout << "User  :  Pass\n\n";
    while(fin){
        string name, pass;
        getline(fin, name , ',');
        if (name != ""){
            cout <<"Name = " << name;
            getline(fin, pass, '\n');
            cout << ", Pass = " << pass << endl;
        }
    }
    fin.close();
}

void Admin::NewTrain(){
    Booking member;
    member.ResetData();
}


void Admin::SetNextTrainDetails(){
    string tDeparture, tArrival, tTime, tDate, tNumber, tPassengerNo = "30";

    cout << "\nEnter Train Number: ";
        getline(cin, tNumber);
    cout << "\nArrival: ";
        getline(cin, tArrival);
    cout << "\nDeparture : ";
        getline(cin, tDeparture);
    cout << "\nEnter Date: ";
        getline(cin, tDate);
    cout << "\nEnter Time: ";
        getline(cin, tTime);

    trainDetail[0] = tDeparture; trainDetail[1] = tArrival; trainDetail[2] = tTime;
    trainDetail[3] = tDate; trainDetail[4] = tNumber; trainDetail[5] = tPassengerNo;

    _check = true;

}

void Admin::DispaySuggestions(){
    string line;
    ifstream outfile("Suggestion.txt");
    while ( getline (outfile,line) )
    {
      cout << line << '\n';
    }
    outfile.close();
}

void Admin::DisplayComplaints(){
    string line;
    ifstream outfile("Complaint.txt");
    while ( getline (outfile,line) )
    {
      cout << line << '\n';
    }
    outfile.close();
}

// Child Class Admin End

// Child Class Users
class User : public Person{
    public:
        void Timing();
        void Inquiry();
        void SeatReserve();
        void Complaint();
        void Cancel();

    private:
        string userName;
        string message;
        int userChoice;
        int seatRow;
        int seatColumn;
        Booking member;
};

void User::SeatReserve()
{
    member.BookSeat();
}


void User::Timing(){


    cout << left << "\n|Train No." << "  " << left << "|Train Name" << "  " << left << "|Boarding pt." << "  " << left << "|Destination pt."  <<"  ";
    cout << left << "|Time";
    cout << left << endl << endl;


    ifstream fin;
    string line;
    fin.open("Header-Files/Timing.txt");
    if(fin){
        while(getline(fin,line))
            cout << line << endl;
    }
    fin.close();


}

void User::Inquiry(){

    string tDeparture, tArrival, tTime, tDate, tNumber, tPassengerNo;
    Booking b, f, e;
    int bNumber = b.GetBusinessSeats() , fNumber = f.GetFirstSeats(), eNumber = e.GetEconomySeats();


    if(_check == true){
        tDeparture = trainDetail[0]; tArrival = trainDetail[1] ; tTime = trainDetail[2];
        tDate = trainDetail[3]; tNumber = trainDetail[4]; tPassengerNo = trainDetail[5];
    }
    else{
        tDeparture = "Abbotabad"; tArrival = "Karachi" ; tTime = "5AM";
        tDate = "July-16,2021"; tNumber = "101"; tPassengerNo = "30";
    }
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";
    cout<<  "\t\t\t|###########################################################################|";
    cout<<"\n\t\t\t|############                                                   ############|";
    cout<<"\n\t\t\t|############                 WELCOME TO INQUIRY                ############|";
    cout<<"\n\t\t\t|############                                                   ############|";
    cout<<"\n\t\t\t|###########################################################################|";
    cout << endl;
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";
    cout<<"\t\t\t                                  GREEN LINE                                   ";
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";

    cout << "\n\n";
    cout << "\t\t\tTRAIN NUMBER: " <<  tNumber << endl << endl;
    cout << "\t\t\tDate: " << tDate << "\t\t\t\t\tTime: " <<  tTime << endl << endl;
    cout << "\t\t\tArrival: " << tArrival << "\t\t\t\t\tDeparture: " <<  tDeparture << endl << endl;
    cout << "\t\t\tFirst Class:    ( " << fNumber << " ) Seats Booked! / ( " << 54 - fNumber <<  " ) Seats Left" << endl << endl;
    cout << "\t\t\tBusiness Class: ( " << bNumber << " ) Seats Booked! / ( " << 54 - bNumber <<  " ) Seats Left" << endl << endl;
    cout << "\t\t\tEconomy Class:  ( " << eNumber << " ) Seats Booked! / ( " << 54 - eNumber <<  " ) Seats Left" << endl << endl;
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";
    cout<<"\t\t\t                                   THANK YOU                                   ";
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";

}

    // complaint function start
void User::Complaint(){
    cout <<"\n Do you want to give \n1.Suggestion \n2.Complaint \n";
    cin >> userChoice;

    if (userChoice == 1){
        cin.ignore();
        if (guestCheck == "Yes")
        {
         cout <<"Enter Your Name: ";
         getline(cin, userName);
        }
        else{
        userName = Name();
        }

        cout << "Enter Your Suggestion: ";
        getline(cin, message);

        ofstream outfile("Suggestion.txt",std::ios_base::app);
        outfile << userName << endl;
        outfile << message << endl;
        outfile << "---------------------------------------------------------------" << endl;
        outfile.close();

        cout << "Thank you for your Suggestion "<<endl;
    }
    else if(userChoice == 2){
        cin.ignore();
        if (guestCheck == "Yes")
        {
         cout <<"Enter Your Name: ";
         getline(cin, userName);
        }
        else{
        userName = Name();
        }

        cout << "Enter Your Complaint: ";
        getline(cin, message);

        ofstream outfile("Complaint.txt",std::ios_base::app);
        outfile << userName << endl;
        outfile << message << endl;
        outfile << "---------------------------------------------------------------" << endl;
        outfile.close();

        cout << "We will look into your Complain" << endl;
    }
}
    // complaint function end


// Child Class User

void Execute(){
    cout << "\t\t\t ================================== \n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||   Railway Reservation System   ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t ================================== \n";

    cout << endl << endl;

    	int ch, userModeChoice;
        Admin pOne;
        User pUser;
        Booking b;

        do
        {
            cout << "\n MAIN MENU \n";
            cout << "1.Admin mode\n2.User mode\n3.Exit \n";
            cout << "Enter your choice : ";
            cin >> ch;
            cin.ignore();
            switch(ch)
            {
                case 1:{
                    if(pOne.display()){
                        do{
                            cout << "\n1.Create DataBase\n2.Display DataBase\n3.Set Train Details\n4.New Train\n5.Display Suggestions\n6.Display Complaints\n7.Return to MainMenu\n> ";
                            cin >> userModeChoice;
                            if(userModeChoice == 1){
                                pOne.CreateDataBase();
                                cout << "Done!\n";
                                
                            }
                            else if(userModeChoice == 2){
                                cin.ignore();
                                pOne.DisplayDataBase();
                                
                            }
                            else if(userModeChoice == 3){
                                cin.ignore();
                                pOne.SetNextTrainDetails();
                                
                            }
                            else if(userModeChoice == 4){
                                pOne.NewTrain();
                                
                            }
                            else if(userModeChoice == 5){
                                pOne.DispaySuggestions();
                                
                            }
                            else if(userModeChoice == 6){
                                pOne.DisplayComplaints();
                                
                            }
                            else if (userModeChoice == 7){
                                // Execute();
                                
                            }
                        }while(userModeChoice < 7);
                    }
                }
                break;
                case 2:
                {
                    cout << "\n1.Sign Up\n2.Log In\n3.Guest Mode\n> ";
                    cin >> ch;
                    if(ch == 1){
                        // cout << "In progress!" << endl;
                        pOne.CreateDataBase();
                        cin.ignore();
                        SignUp();

                    }
                    else if (ch == 2){
                        // cout << "In progress!" << endl;
                        cin.ignore();
                        bool check = LogIn();
                        if (check == true){
                                do{
                            cout <<"\n0.Timing \n1.Inquiry \n2.Seat Reservation";
                            cout << "\n3.Complaint \n4.Ticket Cancellaton \n5.Return to MainMenu \n";
                            cin >> userModeChoice;
                            switch(userModeChoice){

                                case 0:
                                    pUser.Timing();
                                    break;
                                case 1:
                                    pUser.Inquiry();
                                    break;
                                case 2:
                                    pUser.SeatReserve();
                                    break;
                                case 3:
                                    pUser.Complaint();
                                    break;
                                case 4:
                                    CallSeatCancel();
                                    break;
                                case 5:
                                    Execute();
                                    break;
                            }
                                }while(userModeChoice < 5);

                        }

                    }
                    else{
                            do{
                            cout <<"\n0.Timing \n1.Inquiry";
                            cout << "\n2.Complaint\n3.Return to MainMenu \n";
                            cin >> userModeChoice;
                            switch(userModeChoice){

                                case 0:
                                    pUser.Timing();
                                    break;
                                case 1:
                                    pUser.Inquiry();
                                    break;
                                // case 2:
                                //     pUser.SeatReserve();
                                //     break;
                                case 2:
                                    guestCheck = "Yes";
                                    pUser.Complaint();
                                    guestCheck = "No";
                                    break;
                                // case 4:
                                //     CallSeatCancel();
                                //     break;
                                case 3:
                                    Execute();
                                    break;
                                }
                            }while(userModeChoice < 3);

                        }
                }
                break;
                default:
                    ch = 3;
                    break;

                    // exit(0);
            }
        }while(ch < 2);

}

// Main body

int main(){
    Execute();
    return 0;
}

// Main body
