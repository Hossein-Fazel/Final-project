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
        void set_name();
        void set_userName();
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
        std::string name;
        std::string username;
        std::string biography[160];
        std::string link;
        std::string birthday;
        std::string phone_number;
        std::string password;
        std::string header;

        std::vector<tweet> tweets;
};


#endif