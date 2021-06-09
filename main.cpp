#include <iostream>
#include <string>

using namespace std;

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
        void display();
    protected:
        string adminPass = "aetooc";        // Admin Password

};

void Admin::display(){

        string password;
        cout << "Enter your Password: ";
        getline(cin, password);

        if ( password == adminPass )
            cout << "Correct Password\nWelcome!!!\n";
        else
            cout << "Incorrect! No access granted!";

    }
// Child Class Admin End

// Child Class User
class User : public Person{
    public:
        void Inquiry();
        void SeatReserve();
        void Complaint();
        void Cancel();
};
// Child Class User End

// Main body

int main(){
    cout << "\t\t\t ================================== \n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||   Railway Reservation System   ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t ================================== \n";

    cout << endl << endl;

    	int ch;
        Admin pOne;
	
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
                    pOne.display();
                    break;
                // case 2:
                    
                //     break;
                default:
                break;
                    // exit(0);
            }
        }while(ch<3);

        return 0;


}

// Main body
