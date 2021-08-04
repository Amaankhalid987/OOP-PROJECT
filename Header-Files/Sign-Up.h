#include <fstream>
#include <iostream>

using namespace std;

void SignUp(){
    
    string name, password;
    ofstream fout;
    fout.open("DataBase.csv", std::ios_base::app);
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your Password: ";
    getline(cin, password);

    fout << name << ',' << password<< endl;
    
    fout.close();
}