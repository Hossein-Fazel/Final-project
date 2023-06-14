#include <iostream>

#include "sha256.h"
#include "Display_Class.hpp"
#include "Twitterak_Class.hpp"

void display::login(twitterak app,std:: string user_name, std::string password)
{
    if(app.users.count(user_name) == 1)
    {
        
    }
}

void display::login(twitterak app)
{
    std::string user_name, password;
    std::cout << "$ User Name : \n";
    std::cin >> user_name;

    std::cout << "$ Password : \n";
    std::cin >> password;

    if(app.users.count(user_name) == 1)
    {
        if(app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
        }
    }
}

void display::signup()
{
    std::string Full_Name;
    std::string Username;
    std::string Biography;
    std::string Link;
    std::string Birthday;
    std::string Phone_Number;
    std::string Password;
    std::string Header;


    std:: cout << "$ Name : ";
    std:: cin >> Full_Name;

    std:: cout <<"$ User Name";
    std::cin >> Username;
}