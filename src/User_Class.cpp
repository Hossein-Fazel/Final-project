#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctype.h>
#include "sha256.h"

#include "User_Class.hpp"
#include "Twitterak_Class.hpp"


//==================================================================  Get_Functions =================================================================

std::string user::get_name() const                       // returning the name of the user
{
    return Full_Name;
}

//------------------------------------------------------------------------

std::string user::get_username() const                  // returning the username of the user
{
    return Username;
}

//------------------------------------------------------------------------

std::string user::get_biography() const                // returning the biography of the user
{
    return Biography;
}

//------------------------------------------------------------------------

std::string user::get_link() const                    // returning the link of the user
{
    return Link;
}

//------------------------------------------------------------------------

std::string user::get_birthday() const              // returning the date of birth of the user
{
    return Birthday;
}

//------------------------------------------------------------------------

std::string user::get_phone() const                // returning the phone number of the user
{
    return Phone_Number;
}

//------------------------------------------------------------------------

std::string user::get_password() const            // returning the password of the user's account
{
    return Password;
}

//------------------------------------------------------------------------

std::string user::get_header() const            // returning the color of the header that user had chosen 
{
    return Header;
}

//------------------------------------------------------------------------

std::string user::get_country() const         // returning the color of the header that user had chosen 
{
    return Country;
}

//==================================================================  Set_Functions =================================================================

void user::set_name(std::string name)                                               // setting the name of a user
{
    Full_Name = name;
}

//------------------------------------------------------------------------

void user::set_username(std::string user_name)                                     // setting the username of a user with a validation
{
    while (1)
    {
        if ((Validating_Username(user_name)) == 0)
        {
            std::cerr << "! Username must have at least 5 characters.";
            std::cin >> user_name;
        }

        else if ((Validating_Username(user_name)) == -1)
        {
            std::cerr << "! Username must not have characters.";
            std::cin >> user_name;
        }
            
        else if ((Validating_Username(user_name)) == -2)
        {
            std::cerr << "! Username must not be the commands of the program.";
            std::cin >> user_name;
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

//------------------------------------------------------------------------

int user::Validating_Username(std::string user_name)                              // the validation of a user's username
{
    if (user_name.length() < 5)
        return 0;

    for (int i = 0; i < user_name.length(); ++i)
    {
        if (!isalnum(user_name[i]))
            return -1;
    }
   
    Username = to_lower(user_name);

    if ((Username != "help") and (Username != "login") and (Username != "signup") and (Username != "edit") 
        and (Username != "exit") and (Username != "delete account") and (Username != "like") and (Username != "profile") 
        and (Username != "quit")and (Username != "logout") and (Username != "delete tweet")and (Username != "edit tweet"))
        return -2;

    return 1;
}

//------------------------------------------------------------------------

void user::set_biography(std::string bio)                                        // setting the biography of a user
{
    Biography = bio;
}

//------------------------------------------------------------------------
                                                                                
void user::set_link(std::string input_link)                                     // setting the link of a user
{
    const std::string Https = "https://";
    std::cout << Https;
    Link = Https + input_link;
}

//------------------------------------------------------------------------

void user::set_birthday(std::string birth)                                     // setting the date of birth of a user
{
    Birthday = birth;
}

//------------------------------------------------------------------------

void user::set_phone(std::string input_phone)                                 // setting the phone number of a user
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

//------------------------------------------------------------------------

void user::set_country(std::string input_country)                          // setting the country of the user
{
    Country = input_country;
}

//================================================================  General_Functions ===============================================================

// void user::Like()
// {
    
// }

//------------------------------------------------------------------------

std::string user::remove_atsing(std::string str)                                                             // removing @ from the first of the user name
{
    return str.erase(0, 1);
}

//------------------------------------------------------------------------

std::string user::to_lower(std::string str)                                                                 // make a string a lowercase
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    return str;
}

//------------------------------------------------------------------------

void user::Show_Profile(twitterak app, std::string in_username)                                            // showing the self-information of a user
{
    in_username = remove_atsing(in_username);

    if (in_username == app.logedin_user)
    {
        std::cout << "$ Header : " << app.users[in_username].get_header() << std::endl;
        std::cout << "$ Name : " << app.users[in_username].get_name() << std::endl;
        std::cout << "$ Username : " << app.users[in_username].get_username() << std::endl;
        std::cout << "$ Birthday : " << app.users[in_username].get_birthday() << std::endl;
        std::cout << "$ Biography : " << app.users[in_username].get_biography() << std::endl;
        std::cout << "$ Link : " << app.users[in_username].get_link() << std::endl;
        std::cout << "$ Phone_Number : " << app.users[in_username].get_phone() << std::endl;
        std::cout << "$ country : " << app.users[in_username].get_country()   << std::endl;
    }
    else
    {
        std::cout << "$ Header : " << app.users[in_username].get_header() << std::endl;
        std::cout << "$ Name : " << app.users[in_username].get_name() << std::endl;
        std::cout << "$ Username : " << app.users[in_username].get_username() << std::endl;
        std::cout << "$ Biography : " << app.users[in_username].get_biography() << std::endl;
        std::cout << "$ Link : " << app.users[in_username].get_link() << std::endl;
        std::cout << "$ country : " << app.users[in_username].get_country()   << std::endl;
    }
}

//------------------------------------------------------------------------

void user::Show_Profile(twitterak app)                                                                    // showing the information of a user itself
{
    std::cout << "$ Header : " << app.users[app.logedin_user].get_header() << std::endl;
    std::cout << "$ Name : " << app.users[app.logedin_user].get_name() << std::endl;
    std::cout << "$ Username : " << app.users[app.logedin_user].get_username() << std::endl;
    std::cout << "$ Birthday : " << app.users[app.logedin_user].get_birthday() << std::endl;
    std::cout << "$ Biography : " << app.users[app.logedin_user].get_biography() << std::endl;
    std::cout << "$ Link : " << app.users[app.logedin_user].get_link() << std::endl;
    std::cout << "$ Phone_Number : " << app.users[app.logedin_user].get_phone() << std::endl;
    std::cout << "$ country : " << app.users[app.logedin_user].get_country()   << std::endl;
}

//------------------------------------------------------------------------

void user::Edit(twitterak app, std::string Edit_part ,std::string value)                                                                                       // Edit the user's information 
{
    Edit_part = to_lower(Edit_part);

    if (Edit_part == "name")
    {
        app.users[app.logedin_user].set_name(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed."
    }

    if (Edit_part == "biography")
    {
        if (value.length() > 160)
            value.erase(160, value.length());

        app.users[app.logedin_user].set_biography(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed."
    }

    else if (Edit_part == "link")
    {
        app.users[app.logedin_user].set_link(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }


    else if (Edit_part == "birthday")
    {
        app.users[app.logedin_user].set_birthday(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }


    else if (Edit_part == "phone_number")
    {
        app.users[app.logedin_user].set_phone(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }

    else if (Edit_part == "password")
    {
        app.users[app.logedin_user].set_password(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }

    else if (Edit_part == "header")
    {
        app.users[app.logedin_user].set_header(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }
 
    else if (Edit_part == "country")
    {
        app.users[app.logedin_user].set_country(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.";
    }
}

//------------------------------------------------------------------------

void user::Delete_Account(twitterak app)                                                                         // Deleting the account of the use      
{
    std::cout << "? This operation cannot be reversed in any way. Are you sure? (y/n) : ";

    char ch;
    std::cin >> ch;

    if (ch == 'y')
    {
        app.users.erase(app.logedin_user);
        std::cout << "* You're account have successfully deleted.";
    }
}

//------------------------------------------------------------------------

void user::Logout(twitterak app)                                                                                // loging out of the user's account       
{
    app.is_logedin = false;
    std::cout << "* You have successfully logged out.";
}