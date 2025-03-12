#ifndef DB_H
#define DB_H

#include <bits/stdc++.h>
using namespace std;

#include "users.h"  // This header should define users::user, users::tutor, and users::student

namespace db {
    class user_data {
        // Static member: a map from mobile numbers to unique_ptrs of users::user.
        static map<string, unique_ptr<users::user>> user_credentials;
    public:
        user_data() {}

        // Insert a user and allow upgrade to tutor/student.
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

            // Initially create the base user.
            user_credentials[mobile_number] = make_unique<users::user>(u);
            
            // Prompt for upgrade.
            string upgrade_choice;
            cout << "Would you like to upgrade your account? Enter 'tutor', 'student', or 'none': ";
            getline(cin, upgrade_choice);
            if (upgrade_choice == "tutor") {
                // Instead of passing 'u' (a users::user) directly,
                // pass the name and mobile_number required by users::tutor's constructor.
                user_credentials[mobile_number] = make_unique<users::tutor>(u.get_name(), u.get_mobile_number());
                cout << "Upgraded to tutor." << endl;
            } else if (upgrade_choice == "student") {
                // Similarly, use the appropriate constructor for a student.
                user_credentials[mobile_number] = make_unique<users::student>(u.get_name(), u.get_mobile_number());
                cout << "Upgraded to student." << endl;
            } else {
                cout << "Account remains as basic user." << endl;
            }
        }

        // Returns a unique_ptr to the user by moving it from the map.
        unique_ptr<users::user> get_user_unique(const string &id) {
            auto it = user_credentials.find(id);
            if (it != user_credentials.end()) {
                return std::move(it->second);  // Transfers ownership
            }
            return nullptr;
        }
        
        // Returns true if the mobile number does NOT exist in the map.
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

    // Define the static member.
    map<string, unique_ptr<users::user>> user_data::user_credentials;

    // (Optional) Additional classes can be defined here.
    class course_details {
        course_details(){}
    };
}

#endif
