#ifndef TWITTERAK_HPP
#define TWITTERAK_HPP

#include "User_Class.hpp"
#include "Tweet_Class.hpp"
#include "Display_Class.hpp"
#include "Mention_class.hpp"
#include "Base_User.hpp"
#include "Organisation_User.hpp"
#include "Anonymous_User.hpp"

#include <unordered_map>
#include <vector>
#include <string>

class twitterak
{
//=================== Friends ===================

friend void Base_User::Logout(twitterak &);
friend void user::Delete_Account(twitterak &);
friend void user::Show_Profile(twitterak &);
friend void user::Edit(twitterak &, std::string, std::string);
friend void user::del_myMentions(twitterak &);
friend void user::del_tweetLikes(twitterak &);
friend void user::follow(twitterak &, std::string);
friend void user::unfollow_followers(twitterak &app);

friend void display::login(twitterak  &,std::string, std::string);
friend void display::login(twitterak  &);
friend void display::login(twitterak  &, std::string);
friend void display::signup(twitterak &);
friend void display::help(twitterak &);
friend void display::signup(twitterak &, std::string);
friend void display::show_tweet(twitterak, std::string, int);
friend void display::show_tweet(twitterak, std::string);
friend void display::show_mentions(twitterak, std::string user_name, int tweet_number);

friend void tweet::rq_tweet(twitterak&, std::string);
friend void tweet::edit_tweet(twitterak &);                               // friend with Twitterak_Class to edit a tweet
friend void tweet::fetch_hashtags(twitterak &);                           // friend with Twitterak_Class to fecth hashtags from tweets
friend void tweet::delete_hashtags(twitterak &); 

friend void Organisation::set_manager_username(twitterak ,std::string);
friend void Organisation::Edit(twitterak &, std::string, std::string);
friend void Organisation::follow(twitterak &app, std::string uName);
friend void Organisation::del_myMentions(twitterak &);
friend void Organisation::del_tweetLikes(twitterak &app);
friend void Organisation::Delete_Account(twitterak & app);
friend void Organisation::unfollow_followers(twitterak &app);


friend void Anonymous::follow(twitterak &app, std::string uName);
friend void Anonymous::Edit(twitterak &, std::string, std::string);
friend void Anonymous::Delete_Account(twitterak &);                         // delets the account of the user
friend void Anonymous::del_myMentions(twitterak &app);
friend void Anonymous::del_tweetLikes(twitterak &app);
friend void Anonymous::unfollow_followers(twitterak &app);


    public:
        twitterak();
        void put_users();
        void read_users();
        std::string lower(std::string);
        void run();
        void tokenize(std::string);
        bool is_in(std::string,char);
        bool is_in(std::string,std::string);
        void serch_hashtag(std::string);
        bool get_userName_number(std:: string, std::string &, int &);
        void del_atsign(std::string &);

    private:
        Base_User* li_user;
        bool is_logedin = false;
        std:: string logedin_user;
        
        std::vector<std::string> commands; 
        std::unordered_map<std::string, user> users;
        std::unordered_map<std::string, Organisation> org_user;
        std::unordered_map<std::string, Anonymous> ans_user;
        std::unordered_map<std::string,std::vector<tweet>> Hashtags;
};

#endif