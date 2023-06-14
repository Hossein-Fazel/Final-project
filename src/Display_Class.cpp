#include <iostream>

#include "sha256.h"
#include "Display_Class.hpp"
#include "Twitterak_Class.hpp"

void display::login(twitterak app, std::string user_name, std::string password)
{
    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your user name is incorrect\n";
    }
}

void display::login(twitterak app, std::string user_name)
{
    std::string password;

    std::cout << "$ Password : \n";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your user name is incorrect\n";
    }
}

void display::login(twitterak app)
{
    std::string user_name, password;
    std::cout << "$ User Name : \n";
    std::cin >> user_name;

    std::cout << "$ Password : \n";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your user name is incorrect\n";
    }
}

void display::signup(twitterak app)
{
    std::string Full_Name;
    std::string Username;
    std::string Biography;
    std::string Link;
    std::string Birthday;
    std::string Phone_Number;
    std::string Password;
    std::string Header;

    user u1;

    while(1)
    {
        std::cout << "$ Name : ";
        std::cin >> Full_Name;
        u1.set_name(Full_Name);

        if(app.users.count(u1.get_username()) == 1)
        {
            std:: cout << "! Your user name is invalid\n";
            std::cout << "$ Name : ";
            std::cin >> Full_Name;
            u1.set_name(Full_Name);
        }
        else
        {
            break;
        }
    }

    std::cout << "$ User Name : ";
    std::cin >> Username;
    u1.set_username(Username);

    std::cout << "$ Biography : ";
    std::cin >> Biography;
    u1.set_biography(Biography);

    std::cout << "$ Link : https://";
    std::cin >> Link;
    u1.set_link(Link);

    std::cout << "Please Enter The Birth Date In This Form : 2003.12.19\n";
    std::cout << "$ Birthday : ";
    std::cin >> Birthday;
    u1.set_birthday(Birthday);

    std::cout << "$ Phone_Number : ";
    std::cin >> Phone_Number;
    u1.set_phone(Phone_Number);

    std::cout << "$ Password : ";
    std::cin >> Password;
    u1.set_password(Password);

    std::cout << "$ Header : ";
    std::cin >> Header;
    u1.set_header(Header);

    app.users[u1.get_username()] = u1;
    std::cout << "* Registration was successful";
}

void display::help(twitterak app)
{
    if(app.is_logedin)
    {
        std:: cout << "==================== Help ====================\n";
        std:: cout << "logout : for log";
    }


}


