#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <sha256.h>
#include "User_Class.hpp"

//==================================================================  Get_Functions =================================================================

std::string user::get_name() const                      // returning the name of the user
{
    return Full_Name;
}


std::string user::get_biography() const                // returning the biography of the user
{
    return Biography[160];
}


std::string user::get_link() const                    // returning the link of the user
{
    return Link;
}


std::string user::get_birthday() const              // returning the date of birth of the user
{
    return Birthday;
}


std::string user::get_phone() const                // returning the phone number of the user
{
    return Phone_Number;
}


std::string user::get_password() const            // returning the password of the user's account
{
    return Password;
}


std::string user::get_header() const            // returning the color of the header that user had chosen 
{
    return Header;
}

//==================================================================  Set_Functions =================================================================

void user::set_name(std::string name)                                         // setting the name of a user
{
    Full_Name = name;
}

//------------------------------------------------------------------------

void user::set_username(std::string user_name)                               // setting the username of a user with a validation
{
    while (!(Validating_Username(user_name)))
    {
        std::cerr << "Please Enter a Valid Username : ";
        std::cin >> user_name;
    }

    Username = user_name;
}

//------------------------------------------------------------------------

bool user::Validating_Username(std::string user_name)                        // the validation of a user's username
{
    if (user_name.length() < 5)
        return false;

    for (int i = 0; i < user_name.length(); ++i)
    {
        int check = user_name[i];
        if ((check >= 33 and check <= 47) and(check >= 58 and check <= 64) and 
            (check >= 91 and check <= 96) and (check >= 123 and check <= 126))
            return false;
    }
    for (int i = 0; i < user_name.length(); ++i)
        user_name[i] = tolower(user_name[i]);

    if ((user_name != "help") and (user_name != "login") and (user_name != "signup") and (user_name != "edit") 
        and (user_name != "exit") and (user_name != "delete account") and (user_name != "like") and (user_name != "profile") 
        and (user_name != "quit")and (user_name != "logout") and (user_name != "delete tweet")and (user_name != "edit tweet"))
        return false;


    return true;
}

//------------------------------------------------------------------------

void user::set_biography(std::string bio[160])                                  // setting the biography of a user
{
    std::getline(std::cin, bio[160]);
    Biography[160] = bio[160];
}

//------------------------------------------------------------------------
                                                                                
void user::set_link(std::string input_link)                                    // setting the link of a user
{
    std::string Https = "https://";
    Link = Https + input_link;
}

//------------------------------------------------------------------------

void user::set_birthday(std::string birth)                                    // setting the date of birth of a user
{
    Birthday = birth;
}

//------------------------------------------------------------------------

void user::set_phone(std::string input_phone)                                // setting the phone number of a user
{
    Phone_Number = input_phone;
}

//------------------------------------------------------------------------

void user::set_password(std::string input_pass)                             // setting the password of the user's account
{
    SHA256 sha256;
    Password = sha256(input_pass);
}

//------------------------------------------------------------------------

void user::set_header(std::string input_header)                             // setting the color of the header that user had chosen
{
    Header = input_header;
}

//================================================================  General_Functions ===============================================================

