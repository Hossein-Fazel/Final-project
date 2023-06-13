#include "User_Class.hpp"
#include "Tweet_Class.hpp"
#include "Display_Class.hpp"

#include <unordered_map>
#include <vector>
#include <string>

#ifndef TWITTERAK_HPP
#define TWITTERAK_HPP

class twitterak
{
    friend void display::login(std::string, std::string);
    friend void display::login();

    public:
        void run();
        void tokenize(std::string);

    private:
        bool is_logedin = false;
        std:: string log_user;
        std::vector<std::string> commands; 
        std::unordered_map<std::string, user> users;
        std::unordered_map<std::string,tweet> Hashtags;

};

#endif