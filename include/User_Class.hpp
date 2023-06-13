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
        std::string get_name()const;                    // returning the name of the user
        std::string get_username()const;                // returning the username of the user
        std::string get_biography()const;               // returning the biography of the user
        std::string get_link()const;                    // returning the link of the user
        std::string get_birthday()const;                // returning the date of birth of the user
        std::string get_phone()const;                   // returning the phone number of the user
        std::string get_password()const;                // returning the password of the user's account
        std::string get_header()const;                  // returning the color of the header that user had chosen 

//============ sets ==================
        void set_name(std::string);                     // setting the name of a user
        void set_username(std::string);                 // setting the username of a user with a validation
        void set_biography(std::string*);               // setting the biography of a user
        void set_link(std::string);                     // setting the link of a user
        void set_birthday(std::string);                 // setting the date of birth of a user
        void set_phone(std::string);                    // setting the phone number of a user
        void set_password(std::string);                 // setting the password of the user's account
        void set_header(std::string);                   // setting the color of the header that user had chosen

//============ General functions =============
        void Like();
        void Delete_Account();
        void Show_Profile();
        void Edit();
        void Tweet();
        void Logout();
        bool Validating_Username(std::string);          // the validation of a user's username

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