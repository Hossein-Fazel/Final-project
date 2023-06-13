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
        static bool is_logedin;
        static std:: string log_user;
        static std::vector<std::string> commands; 
        static std::unordered_map<std::string, user> users;
        static std::unordered_map<std::string,tweet> Hashtags;

};

#endif