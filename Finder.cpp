#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void registration() {
    string login;
    string password;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    ofstream file;
    file.open("data", fstream::app);
    file << login << " " << password << " ";
    file.close();
    cout << "You've been registered" << endl;
}

void enter() {
    string login;
    string password;
    string tmp;
    string tmp1;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    ifstream file;
    file.open("data");
    while (file.peek() != EOF) {
        file >> tmp >> tmp1;
        if ( tmp == login && tmp1 == password) {
            file.close();
            cout << "You're loged in..." << endl;
            return;
        }
    }
    file.close();
    cout << "Error" << endl;
}

int commands() {
    string command;
    cout << "Command: ";
    cin >> command;
    if (command == "register") {
        registration();
    } else if (command == "login") {
        enter();
    } else if (command == "quit") {
        exit(0);
    }
    return 1;
}

int main() {
    while(true) {
        commands();
    }
}

