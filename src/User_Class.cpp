#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctype.h>
#include <sha256.h>

#include "User_Class.hpp"
#include "Twitterak_Class.hpp"


//==================================================================  Get_Functions =================================================================

std::string user::get_name() const                      // returning the name of the user
{
    return Full_Name;
}

//------------------------------------------------------------------------

std::string user::get_username() const                 // returning the username of the user
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

std::string user::get_header() const            // returning the color of the header that user had chosen 
{
    return Header;
}

//------------------------------------------------------------------------

std::string user::get_country() const            // returning the color of the header that user had chosen 
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

void user::set_biography(std::string bio)                                       // setting the biography of a user
{
    Biography = bio;
}

//------------------------------------------------------------------------
                                                                                
void user::set_link(std::string input_link)                                    // setting the link of a user
{
    std::string Https = "https://";
    std::cout << Https;
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

//------------------------------------------------------------------------

void user::set_country(std::string input_country)                          // setting the country of the user
{
    Country = input_country;
}

//================================================================  General_Functions ===============================================================

// void user::Like()
// {
    
// }


std::string user::remove_atsing(std::string str)                                                             // removing @ from the first of the user name
{
    return str.erase(0, 1);
}


std::string user::to_lower(std::string str)                                            // make a string a lowercase
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    return str;
}


void user::Show_Profile(twitterak app, std::string in_username)
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


void user::Show_Profile(twitterak app)
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


void user::Edit()
{
    std::string Edit_part, Edit;
    std::getline(std::cin, Edit_part);
  

    if (Edit_part == "Name")
    {
        std::cout << "$Name : ";
        std::cin.ignore();
        std::cin >> Edit;
        set_name(Edit);
    }

    if (Edit_part == "Biography")
    {
        std::cout << "$Biography : ";           // problem 

        set_biography(Edit);
    }

    else if (Edit_part == "Link")
    {
        std::cout << "$Link : ";
        std::cin >> Edit;
        set_link(Edit);
    }


    else if (Edit_part == "Birthday")
    {
        std::cout <<"Please Enter The Birth Date In This Form : 2003.12.19\n";
        std::cout << "$Birthday : ";
        std::cin >> Edit;
        set_birthday(Edit);
    }


    else if (Edit_part == "Phone_Number")
    {
        std::cout << "$Phone_Number : ";
        std::getline(std::cin, Edit);
        set_phone(Edit);
    }

    else if (Edit_part == "Password")
    {
        std::cout << "$Password : ";
        std::cin.ignore();
        std::cin >> Edit;
        set_password(Edit);
    }

    else if (Edit_part == "Header")
    {
        std::cout << "$Header : ";
        std::cin >> Edit;
        set_header(Edit);
    }

    else if (Edit_part == "Country")
    {
        std::cout << "$Country : ";
        std::cin >> Edit;
        set_country(Edit);
    }
}


void user::Delete_Account(twitterak app)      // bug
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


void user::Logout(twitterak app)            // bug
{
    app.is_logedin = false;
    std::cout << "* You have successfully logged out.";
}


