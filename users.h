#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

namespace users {

    class user {
        string name;
        string mobile_number;
        string password;
    public:
        // Base constructor
        user(string name, string mobile_number) {
            this->name = name;
            this->mobile_number = mobile_number;
        }

        // Setter and getter for mobile number
        void set_mobile_number(string number) {
            this->mobile_number = number;
        }
        string get_mobile_number() {
            return this->mobile_number;
        } 

        // Setter and getter for name
        void set_name(string name) {
            this->name = name;
        }
        string get_name() {
            return this->name;
        }

        // Setter and password check
        void set_password(string pass) {
            this->password = pass;
        }
        bool check_password(string pass) {
            return pass == this->password;
        }
    };

    // Student class derived from user
    class student : public user {
        // A student may have a list of enrolled courses.
        vector<string> courses_enrolled;
    public:
        // Constructor calls the base constructor.
        student(string name, string mobile_number)
            : user(name, mobile_number) { }

        // Method to join a course.
        void join_course(const string &course_title) {
            courses_enrolled.push_back(course_title);
            cout << get_name() << " joined course: " << course_title << endl;
        }

        // Method to list all enrolled courses.
        void list_courses() {
            cout << "Courses enrolled by " << get_name() << ":\n";
            for (const auto &course : courses_enrolled) {
                cout << "- " << course << endl;
            }
        }
    };

    // Tutor class derived from user
    class tutor : public user {
        // A tutor may have a list of created courses.
        vector<string> courses_created;
    public:
        // Constructor calls the base constructor.
        tutor(string name, string mobile_number)
            : user(name, mobile_number) { }

        // Method to create a course.
        void create_course(const string &course_title) {
            courses_created.push_back(course_title);
            cout << get_name() << " created course: " << course_title << endl;
        }

        // Method to list all courses created by the tutor.
        void list_courses() {
            cout << "Courses created by " << get_name() << ":\n";
            for (const auto &course : courses_created) {
                cout << "- " << course << endl;
            }
        }
    };

}

#endif
