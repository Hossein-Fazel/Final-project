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
//=================== Friends ===================

friend void user::Logout(twitterak &);
friend void user::Delete_Account(twitterak &);
friend void user::Show_Profile(twitterak &);
friend void user::Edit(twitterak &, std::string, std::string);

friend void display::login(twitterak  &,std::string, std::string);
friend void display::login(twitterak  &);
friend void display::login(twitterak  &, std::string);
friend void display::signup(twitterak &);
friend void display::help(twitterak &);
friend void display::signup(twitterak &, std::string);
friend void display::show_tweet(twitterak);
friend void display::show_tweet(twitterak, std::string, int);
 

friend void tweet::rq_tweet(twitterak&, std::string);
friend void tweet::delete_tweet(twitterak, int);                        // friend with Twitterak_Class to delete a tweet
friend void tweet::edit_tweet(twitterak, int);                          // friend with Twitterak_Class to edit a tweet

    public:
        std::string lower(std::string);
        void run();
        void tokenize(std::string);

    private:
        bool is_logedin = false;
        std:: string logedin_user;
        std::vector<std::string> commands; 
        std::unordered_map<std::string, user> users;
        std::unordered_map<std::string,tweet&> Hashtags;
};

#endif