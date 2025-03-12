#ifndef LOGIN_H
#define LOGIN_H

#include<bits/stdc++.h>
using namespace std;

#include "db.h"
#include "users.h"
#include "application.h"

#include "users.h"

    class login{
        public:
        login(){
            run();
        }
        void run()
        {
            string mobile;
            bool validInput = false;
            db::user_data user;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (!validInput) {
                cout << "\tEnter mobile number: ";
                getline(cin, mobile);

                
                if (!regex_match(mobile, regex("^\\d{10}$"))) {
                    cout << "Error: Mobile number must be exactly 10 digits. Please try again.\n" << endl;
                    continue;
                }
                if(user.mobile_already_exist(mobile))
                {
                    cout << "NUMBER not exist..";
                    continue;
                }
                users::user u = user.get_user(mobile);
                
                string password;
                do{
                    cout << "\tEnter Correct Password : ";
                    cin >> password;
                    cin.clear();
                }while(!u.check_password(password));
                validInput = true;
            }
            application app;
        }
    };


#endif 