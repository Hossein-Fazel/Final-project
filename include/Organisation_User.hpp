#ifndef ORGANISATION_USER_HPP
#define ORGANISATION_USER_HPP

#include <iostream>

#include "Base_User.hpp"

class Organisation : public Base_User
{
    public:
        std::string get_manger_username() const;
        std::string get_biography() const;


        void get_manger_username(std::string);
        void set_biography(std::string);




    private:
        std::string manager_username;
        std::string organisation_bio;
};

#endif