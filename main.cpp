#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Header-Files/Sign-Up.h"
#include "Header-Files/Log-In.h"

using namespace std;

// Globally declared array for Inquiry (change using arrays for loop)
string TrainDetails[5][8];

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
// Child Class Admin End

// Child Class User
class User : public Person{
    public:
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
};


void User::Inquiry(){
 

    cout << left << "\n|Train No." << "  " << left << "|Train Name" << "  " << left << "|Boarding pt." << "  " << left << "|Destination pt."  <<"  ";
    cout << left << "|Time" << "  " << "|B-Class" << "  " << left << "|F-Class" << "  " << left << "|E-Class" <<"  ";
    cout << left << endl << endl;


    ifstream fin;
    string line;
    fin.open("Header-Files/Inquiry.txt");
    if(fin){
        while(getline(fin,line))
            cout << line << endl;
    }
    fin.close();


}

    // complaint function start
void User::Complaint(){
    cout <<"\n Do you want to give \n1.Suggestion \n2.Complaint \n";
    cin >> userChoice;


    if (userChoice == 1){
        cin.ignore();
        cout <<"Enter Your Name: ";
        getline(cin, userName);

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
        cout <<"Enter Your Name: ";
        getline(cin, userName);

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
	
        do
        {
            cout << "\n MAIN MENU \n";
            cout << "1.Admin mode\n2.User mode\n3.Exit \n";
            cout << "Enter your choice : ";
            cin >> ch;
            cin.ignore();
            switch(ch)
            {
                case 1:
                    if(pOne.display()){
                        cout << "\n1.Create DataBase\n2.Return to MainMenu\n> ";
                        cin >> ch;
                        if(ch == 1){
                            pOne.CreateDataBase();
                            cout << "Done!\n";
                            break;
                        }
                        else if (ch == 2){
                            // Execute();
                            break;
                        }
                    }
                case 2:
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
                            cout <<"\n1.Inquiry \n2.Seat Reservation"; 
                            cout << "\n3.Complaint \n4.Ticket Cancellaton \n5.Return to MainMenu \n";
                            cin >> userModeChoice;
                            switch(userModeChoice){

                                case 1:
                                    pUser.Inquiry();
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    pUser.Complaint();
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    Execute();
                                    break;
                            }
                            
                        }

                    }
                    else{
                        cout <<"\n1.Inquiry \n2.Seat Reservation"; 
                        cout << "\n3.Complaint \n4.Ticket Cancellaton \n5.Return to MainMenu \n";
                        cin >> userModeChoice;
                        switch(userModeChoice){

                            case 1:
                                pUser.Inquiry();
                                break;
                            case 2:
                                break;
                            case 3:
                                pUser.Complaint();
                                break;
                            case 4:
                                break;
                            case 5:
                                Execute();
                                break;
                        }
                    }
                    break;
                default:
                    break;
                    // exit(0);
            }
        }while(ch<3);

}

// Main body

int main(){

    Execute();
    return 0;
}

// Main body
