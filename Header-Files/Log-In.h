#include <fstream>
#include <iostream>

using namespace std;

// This is a universal userName and a name function which we will use in main (complaint and suggestion)
string uName;
string Name();

bool LogIn(){

    int totalData = 0;
    bool access = false;
    string userName, password;
    ifstream fin;
    fin.open("DataBase.csv");

    while(fin){
        string line;
        getline(fin, line , ',');
        totalData++;
    }
    fin.close();

    string** arr;
    int rows, columns = 2;
    rows = totalData - 1;

    arr = new string* [rows];

    for (int i = 0; i < rows; i++)
        arr[i] = new string[columns];

    ifstream fiin;
    fiin.open("DataBase.csv");
       
    for (int i = 0; i < rows; i++){
        int j = 0;
        string name, pass;
        getline(fiin, name , ',');
        getline(fiin, pass, '\n');
        arr[i][j] = name;
        arr[i][j+1] = pass;
        
    }
    fiin.close();

    cout << "Enter your name: ";
    getline(cin, userName);
    uName = userName;

    cout << "Enter your Password: ";
    getline(cin, password);

    int j = 0;

    for (int i = 0; i < rows; i++){
        if (arr[i][j] == userName && arr[i][j + 1] == password){
            cout << "Access Granted!\n\n-+-+-+-+-+-+-+-+-+Welcome " << userName << "-+-+-+-+-+-+-+-+-+\n";
            access = true;
            break;
            
        }
    }

    if (access == false){
        cout << "Access Denied!\n";
    }

    return access;
}

string Name()
{
    return uName;
}
