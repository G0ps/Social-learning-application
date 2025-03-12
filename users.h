#ifndef user_H
#define user_H

#include<bits/stdc++.h>
using namespace std;


namespace users{
    class user{
        string name;
        string mobile_number;
        string password;
        public:
        user(string name , string mobile_number){
            this->name = name;
            this->mobile_number = mobile_number;
        }
        //setter and getter
        void set_mobile_number(string number)
        {
            this->mobile_number = number;
        }
        string get_mobile_number()
        {
            return this->mobile_number;
        } 

        void set_name(string name)
        {
            this->name = name;
        }
        string get_name()
        {
            return this->name;
        }

        void set_password(string pass)
        {
            this->password = pass;
        }
        bool check_password(string pass)
        {
            return pass == this->password;
        }
    };

    // class learner:public user{
    //     vector<string> courses_enrolled;
    //     public:
    //     learner()
    //     {
            
    //     }
    //     void join_courses()
    //     {

    //     }
    //     void
        
    // };
}


#endif 