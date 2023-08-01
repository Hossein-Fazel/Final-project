#include <iostream>

#include "Base_User.hpp"
#include "sha256.h"


// ============================================= get functions ===============================================
std::string Base_user::get_name() const                       // returns the name of the user
{
    return Full_Name;
}

std::string Base_user::get_username() const                  // returns the username of the user
{
    return Username;
}

//  ======================================= set functions =====================================
void Base_user::set_name(std::string name)                                               // sets the name of a user
{
    Full_Name = name;
}

void Base_user::set_username(std::string user_name)                                     // sets the username of a user with a validation
{
    while (1)
    {
        if ((Validating_Username(user_name)) == 0)
        {
            std::cerr << "! Username must have at least 5 characters.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }

        else if ((Validating_Username(user_name)) == -1)
        {
            std::cerr << "! Username must not have characters.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }
            
        else if ((Validating_Username(user_name)) == -2)
        {
            std::cerr << "! Username must not be the commands of the program.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }

        else
        {
            if (Username[0] == '@') 
                Username = remove_atsing(user_name);

            Username = to_lower(user_name);

            break;
        }
    }
}

void Base_user::set_password(std::string input_pass)                             // sets the password of the user's account
{
    SHA256 sha256;
    Password = sha256(input_pass);
}

// ============================================= general functions ===============================================

int Base_user::Validating_Username(std::string user_name)                              // the validation of a user's username
{
    if (user_name.length() < 5)
        return 0;

    for (int i = 0; i < user_name.length(); ++i)
    {
        if (!isalnum(user_name[i]))
            return -1;
    }
   
    user_name = to_lower(user_name);

    if ((user_name == "help") or (user_name == "login") or (user_name == "signup") or (user_name == "edit") 
        or (user_name == "exit") or (user_name == "delete account") or (user_name == "like") or (user_name == "profile") 
        or (user_name == "quit")or (user_name == "logout") or (user_name == "delete tweet") or (user_name == "edit tweet"))
    {
        return -2;
    }
        

    return 1;
}

std::string Base_user::to_lower(std::string str)                                                                 // makes a string lowercase
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    return str;
}

std::string Base_user::remove_atsing(std::string str)                                                             // removes @ from the first of the user name
{
    return str.erase(0, 1);
}
