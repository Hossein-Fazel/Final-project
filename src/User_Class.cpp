#include <iostream>
#include <ctype.h>
#include "User_Class.hpp"

//===================================================  Get_Functions =================================================== 

std::string user::get_name() const                      // returning the name of the user
{
    return name;
}


std::string user::get_biography() const                // returning the biography of the user
{
    return biography[160];
}


std::string user::get_link() const                    // returning the link of the user
{
    return link;
}


std::string user::get_birthday() const              // returning the date of birth of the user
{
    return birthday;
}


std::string user::get_phone() const                // returning the phone number of the user
{
    return phone_number;
}


std::string user::get_password() const            // returning the password of the user's account
{
    return password;
}


std::string user::get_header() const            // returning the color of the header that user had chosen 
{
    return header;
}

//===================================================  Get_Functions =================================================== 

void user::set_name(std::string name)
{
    Full_Name = name;
}


