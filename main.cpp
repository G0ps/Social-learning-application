#include<bits/stdc++.h>
using namespace std;

#include "db.h"
#include "registration.h"
#include "login.h"

int main()
{
   string option = "0";
   
   do{
    cout << R"(
    option 0 -> exit
    option 1 -> register
    option 2 -> login
    )";
    cout << "\tEnter option : ";
    cin >> option;
    if(option == "1")
    {
        registration reg;
    }
    else if(option == "2")
    {
        login log;
    }
   }while(option != "0");
}