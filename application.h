#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "users.h"

class application {
    std::unique_ptr<users::user> user_details;
public:
    // Constructor that takes ownership of the unique_ptr.
    application(std::unique_ptr<users::user> u)
        : user_details(std::move(u)) { }

    void run() {
        // Use the user_details pointer.
        cout << "Welcome, " << user_details->get_name() << "!" << endl;
        // Additional application logic here.
    }
};

#endif
