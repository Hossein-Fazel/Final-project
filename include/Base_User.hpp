#ifndef BASE_USER_HPP
#define BASE_USER_HPP

#include <string>
#include <map>
#include <iostream>
#include "Tweet_Class.hpp"
#include "sha256.h"

class Base_User
{

    public:
//  ======================================= set functions =====================================
        void set_name(std::string);                               // sets the name of a user
        void set_username(std::string);                           // sets the username of a user with a validation
        void set_password(std::string);                           // sets the password of the user's account
    
//  ======================================= get functions =====================================
        std::string get_name();                              // returns the name of the user
        std::string get_username();                          // returns the username of the user


//  ======================================= general functions =====================================
        int Validating_Username(std::string);                      // the validation of a user's username
        std::string to_lower(std::string);                         // makes a string a lowercase
        std::string remove_atsing(std::string);                    // removes @ from the first of the user name


//  ======================================= virtual functions =====================================
        virtual std::string get_biography(){};                         // returns the biography of the user
        virtual std::string get_link(){};                              // returns the link of the user
        virtual std::string get_birthday(){};                          // returns the date of birth of the user
        virtual std::string get_phone(){};                             // returns the phone number of the user
        virtual std::string get_password(){};                          // returns the password of the user's account
        virtual std::string get_header(){};                            // returns the color of the header that user had chosen 
        virtual std::string get_country(){};                           // returns the country of the user
        virtual int get_last_number() {};
        virtual void set_biography(std::string) {};                          // sets the biography of a user
        virtual void set_link(std::string) {};                               // sets the link of a user
        virtual void set_birthday(std::string) {};                           // sets the date of birth of a user
        virtual void set_phone(std::string) {};                              // sets the phone number of a user
        virtual void set_header(std::string) {};                             // sets the color of the header that user had chosen
        virtual void set_country(std::string) {};                            // sets the country of the user
        virtual void Delete_Account(twitterak &) {};                         // delets the account of the user
        virtual void Show_Profile(twitterak &) {};                           // shows the information of a user itself
        virtual void Edit(twitterak &, std::string, std::string) {};         // edits the user's information                                                                    
        virtual void edit_tweet(int, twitterak &) {};
        virtual void Tweet(std::string , twitterak &) {};                    // make a normal tweet
        virtual void Logout(twitterak &) {};                                 // logs out of the user's account
        virtual void Push_Tweet(tweet) {};                                   // push a tweet into a vector
        virtual void last_number() {};                                       // plus plus last_num variable
        virtual void print_likers(int) {};
        virtual bool like(std::string ,int) {};
        virtual bool dislike(std::string, int) {};
        virtual bool validate_phone_number(std::string) {};                   // validate user's phone_number
        virtual std::map <int, tweet> get_tweets() {};
        virtual bool add_mention(int, std::string, std::string) {};
        virtual void push_myMentions(int , std::string) {};
        virtual void push_tweetLikes(int, std::string) {};
        virtual void pop_tweetLikes(int, std::string) {};
        virtual void del_myMentions(twitterak &) {};
        virtual void cls_hashtags(twitterak &) {};
        virtual void del_tweetLikes(twitterak &) {};
        virtual int get_followers_num() {};
        virtual int get_following_num() {};
        virtual void like_mention(int, std::string, int) {};


    private:
        std::string Full_Name;
        std::string Username;
        std::string Password;
};

#endif