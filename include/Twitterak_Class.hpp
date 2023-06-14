#ifndef TWITTERAK_HPP
#define TWITTERAK_HPP

#include "User_Class.hpp"
#include "Tweet_Class.hpp"
#include "Display_Class.hpp"

#include <unordered_map>
#include <vector>
#include <string>


class twitterak
{
    friend void user::Show_Profile();

    friend void display::login(twitterak app,std::string, std::string);
    friend void display::login(twitterak app);
    friend void display::login(twitterak app, std::string password);


    public:
        void run();
        void tokenize(std::string);

    private:
        bool is_logedin = false;
        std:: string logedin_user;
        std::vector<std::string> commands; 
        std::unordered_map<std::string, user> users;
        std::unordered_map<std::string,tweet> Hashtags;
};

#endif