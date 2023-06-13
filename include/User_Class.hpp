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
        void set_biography(std::string*);
        void set_link(std::string);
        void set_birthday(std::string);
        void set_phone(std::string);
        void set_password(std::string);
        void set_header(std::string);

//============ General functions =============
        void Like();
        void Delete_Account();
        void Show_Profile();
        void Edit();
        void Tweet();
        void Logout();
        bool Validating_Username(std::string);

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