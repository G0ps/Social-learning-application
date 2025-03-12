#include <bits/stdc++.h>
using namespace std;

#include "db.h"
#include "registration.h"
#include "login.h"

int main() {
    string option;
   
    do {
        cout << R"(
option 0 -> exit
option 1 -> register
option 2 -> login
)";
        cout << "\tEnter option: ";
        cin >> option;
        // Clear any leftover newline characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == "1") {
            registration reg;  // calls registration's constructor which handles registration
        }
        else if (option == "2") {
            login log;  // calls login's constructor which handles login
        }
        else if (option != "0") {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != "0");

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
