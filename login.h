#ifndef LOGIN_H
#define LOGIN_H

#include <bits/stdc++.h>
using namespace std;

#include "db.h"
#include "users.h"
#include "application.h"

class login {
public:
    login() {
        run();
    }

    void run() {
        string mobile;
        bool validInput = false;
        db::user_data userDB;
        // Declare a unique_ptr to store the retrieved user.
        unique_ptr<users::user> u;
        
        // Clear any leftover newline characters.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        while (!validInput) {
            cout << "\tEnter mobile number: ";
            getline(cin, mobile);

            if (!regex_match(mobile, regex("^\\d{10}$"))) {
                cout << "Error: Mobile number must be exactly 10 digits. Please try again.\n" << endl;
                continue;
            }
            // Check if mobile number exists.
            if (userDB.mobile_already_exist(mobile)) {
                cout << "NUMBER not exist.." << endl;
                continue;
            }
            
            // Retrieve the user as a unique_ptr. This moves ownership from the db.
            u = userDB.get_user_unique(mobile);
            
            string password;
            do {
                cout << "\tEnter Correct Password : ";
                cin >> password;
                cin.clear();
            } while (!u->check_password(password));
            
            validInput = true;
        }
        
        // Pass the unique_ptr to the application constructor using std::move to transfer ownership.
        application app(std::move(u));
    }
};

#endif
