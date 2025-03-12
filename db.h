#ifndef DB_H
#define DB_H

#include <bits/stdc++.h>
using namespace std;

#include "users.h"


namespace db {
    class user_data {
        // Declare a static member to hold user pointers, keyed by mobile number.
        static map<string, unique_ptr<users::user>> user_credentials;
        // static map<string, posts::courses> course_details; //title key
    public:
        user_data() {}

        void insert_user(users::user u, const string &mobile_number) {
            string password;
            while (true) {
                cout << "Enter a strong password (at least 8 characters, include an uppercase letter, a lowercase letter, a digit, and a special character): ";
                getline(cin, password);
                
                if (isStrongPassword(password)) {
                    cout << "Password accepted." << endl;
                    break;
                } else {
                    cout << "Password is not strong enough. Please try again." << endl;
                }
            }
            u.set_password(password);
            user_credentials[mobile_number] = make_unique<users::user>(u);
        }
        users::user get_user(string id)
        {
            return *user_credentials[id];
        }
        // Returns true if the mobile number does not exist in the map.
        bool mobile_already_exist(const string &number) {
            return (user_credentials.find(number) == user_credentials.end());
        }
        bool isStrongPassword(const string &password) {
            if (password.length() < 8)
                return false;
            
            bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
            
            for (char c : password) {
                if (islower(c))
                    hasLower = true;
                else if (isupper(c))
                    hasUpper = true;
                else if (isdigit(c))
                    hasDigit = true;
                else
                    hasSpecial = true;  // Any non-alphanumeric character
            }
            
            return hasLower && hasUpper && hasDigit && hasSpecial;
        }
    };

    // Correctly define the static member variable for user_data.
    map<string, unique_ptr<users::user>> user_data::user_credentials;
    // map<string, posts::courses> user_data::course_details;
    
}

#endif
