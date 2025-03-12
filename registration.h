#ifndef REGISTRATION_H
#define REGISTRATION_H

#include<bits/stdc++.h>
using namespace std;

#include "db.h"
#include "users.h"

class registration {
public:
    registration() {
        run();
    }
    
    void run() {
        
        string name;
        string mobile;
        bool validInput = false;
        db::user_data u;
        // Loop until both inputs are valid
        while (!validInput) {
            cout << "\tEnter name: ";
            getline(cin, name);
            
            // Validate name: not empty and only alphabets/spaces
            if (name.empty()) {
                cout << "Error: Name cannot be empty. Please try again.\n" << endl;
                continue;
            }
            if (!regex_match(name, regex("^[A-Za-z ]+$"))) {
                cout << "Error: Name must contain only alphabets and spaces. Please try again.\n" << endl;
                continue;
            }
            
            cout << "\tEnter mobile number: ";
            getline(cin, mobile);
            
            // Validate mobile: exactly 10 digits
            if (!regex_match(mobile, regex("^\\d{10}$"))) {
                cout << "Error: Mobile number must be exactly 10 digits. Please try again.\n" << endl;
                continue;
            }
            if(!u.mobile_already_exist(mobile))
            {
                cout << "ALREADY EXIST NUMBER ..";
                continue;
            }
            validInput = true;
        }
        

        //adding stuf to db
        users::user new_user(name , mobile);
        
        u.insert_user(new_user, mobile);

        cout << "\nregistration successful!" << endl;
        cout << "Name: " << name << endl;
        cout << "Mobile: " << mobile << endl;

        
    }
};

#endif  // rEGISTRATION_H
