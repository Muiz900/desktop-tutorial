#include <iostream>
#include <string>
#include "UserClass.h"
#include "ElectionClass.h"

using namespace std;

Admin a(0,0,"admin", "admin123");

void votemenu() {
    cout << "1. Voter Sign Up" << endl;
    cout << "2. Voter Login" << endl;
}

void mainMenu() {
    cout << "1. Admin Login" << endl;
    cout << "2. Voter Menu" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    int choice = 0;
    cout << "Welcome to E-Voting System" << endl;
    mainMenu();
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (a.userlogin()) {
            
                bool flag = true;
            do{
                cout << "Welcome Admin" << endl;
                a.AdminMenu();
                int choice = 0;
                cout << "Enter choice";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    a.createElections();
                    break;
                }
                case 2: {
                    a.addCandidates();
                    break;
                }
                case 4:
                { flag = false; }
                default:
                    cout << "Invalid Credientials" << endl;
                }

            } while (flag);
        }
        else {
            cout << "Invalid Credentials" << endl;
        }
        break;
    case 2:
        votemenu();
        // Add logic for voter sign up and login here
        break;
    case 3:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }

    return 0;
}
