#ifndef BASE_USER_HPP
#define BASE_USER_HPP

#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unistd.h>

#include "Tweet_Class.hpp"
#include "sha256.h"

class Base_User
{
    public:
//========================================= Set_Functions =====================================

        void set_name(std::string);                                       // sets the name of a user
        void set_username(std::string);                                   // sets the username of a user with a validation
        void set_password(std::string);                                   // sets the password of the user's account
        void set_link(std::string);                                       // sets the link of a user
        void set_phone(std::string);                                      // sets the phone number of a user
        void set_header(std::string);                                     // sets the color of the header that user had chosen
        void set_country(std::string);                                    // sets the country of the user

//======================================== Get_Functions ======================================

        std::string get_name() const;                                     // shows the name of the user
        std::string get_username() const;                                 // shows the username of the user
        std::string get_password() const;                                 // shows the password of the user's account
        std::string get_link() const;                                     // shows the link of the user
        std::string get_phone() const;                                    // shows the phone number of the user
        std::string get_header() const;                                   // shows the color of the header that user had chosen 
        std::string get_country() const;                                  // shows the country of the user
        int get_followers_num() const;                                    // shows the number of followers
        std::unordered_set <std::string> get_followers();                 // return followers set
        std::unordered_set <std::string> get_passwords();                 // return passwords set
//======================================= general functions ====================================

        std::string to_lower(std::string);                                // makes a string a lowercase
        std::string remove_atsing(std::string);                           // removes @ from the first of the user name
        int Validating_Username(std::string);                             // the validation of a user's username
        int validate_password(std::string);                               // validating the acoount's password
        void Logout(twitterak &);                                         // logs out of the user's account
        void add_followers(std::string);                                  // add a new follower to set
        bool validate_phone_number(std::string);                          // validate user's phone_number

//======================================= virtual functions =====================================

        virtual std::string get_biography() const;                        // returns the biography of the user
        virtual std::string get_birthday() const;                         // returns the date of birth of the user
        virtual int get_last_number() const;                              // returns the last number of tweet
        virtual int get_following_num() const;                            // returns the number of following 
        virtual std::unordered_map <int, tweet> get_tweets();                       // returns the tweets
        virtual std::unordered_set< std::string> get_following();

//========================= sets ==========================

        virtual void set_biography(std::string);                          // sets the biography of a user
        virtual void set_birthday(std::string);                           // sets the date of birth of a user

//================== General_Functions ====================

        virtual void Delete_Account(twitterak &);                         // delets the account of the user
        virtual void Show_Profile(twitterak &);                           // shows the information of a user itself
        virtual void Edit(twitterak &, std::string, std::string);         // edits the user's information                                                                    
        virtual void edit_tweet(int, twitterak &);                        // edits user's tweet
        virtual void Tweet(std::string , twitterak &);                    // make a normal tweet
        virtual void Push_Tweet(tweet);                                   // push a tweet into a vector
        virtual void last_number();                                       // plus plus last_num variable
        virtual void print_likers(int);                                   // print tweet likers
        virtual bool like(std::string ,int);                              // like a tweet
        virtual bool dislike(std::string, int);                           // dislike a tweet
        virtual bool add_mention(int, std::string, std::string);          // add a mention to a tweet
        virtual void follow(twitterak &, std::string);                    // follow a user
        virtual void like_mention(int, std::string, int);                 // like a mention
        virtual bool isin_following(std::string);                         // check the user name exist in following
        virtual void unfollow(std::string);                               // unfollow the user name

//==================== Save_User_Traces ====================

        virtual void push_myMentions(int, std::string);                   // save my mention traces
        virtual void push_tweetLikes(int, std::string);                   // save my tweet likes traces
        virtual void pop_tweetLikes(int, std::string);                    // delete a like of a tweet

//=================== Delete_User_Traces ===================

        virtual void del_men(int, std::string);                           // delete a mention
        virtual void del_tweetlike(int , std::string);                    // delete a tweet like
        virtual void del_myMentions(twitterak &);                         // delete mention traces
        virtual void cls_hashtags(twitterak &);                           // delete hashtag traces
        virtual void del_tweetLikes(twitterak &);                         // delete tweet like traces
        virtual void unfollow_followers(twitterak &app);                                // delete you from your followers list

    private:
        std::string Full_Name;
        std::string Username;
        std::string Password;
        std::string Link;
        std::string Phone_Number;
        std::string Header;
        std::string Country;

    protected:
        std::string Biography;
        std::unordered_set <std::string> followers;                      // a set for followers of a specific user
        std::unordered_set <std::string> passwords;                      // a set for saving all passwords of a user
};

#endif