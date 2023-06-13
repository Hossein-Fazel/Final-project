#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

#include"Tweet_Class.hpp"
class tweet;

class user
{
    public:
//============ gets ==================
        std::string get_name()const;
        std::string get_userName()const;
        std::string get_biography()const;
        std::string get_link()const;
        std::string get_birthday()const;
        std::string get_phone()const;
        std::string get_password()const;
        std::string get_header()const;

//============ sets ==================
        void set_name(std::string);
        void set_username(std::string);
        void set_biography();
        void set_link();
        void set_birthday();
        void set_phone();
        void set_password();
        void set_header();

//============ General functions =============
        void like();
        void delete_account();
        void Show_profile();
        void edit();
        void Tweet();
        void logout();

    private:
        std::string Full_Name;
        std::string Username;
        std::string Biography[160];
        std::string Link;
        std::string Birthday;
        std::string Phone_Number;
        std::string Password;
        std::string Header;

        std::vector<tweet> tweets;
};


#endif