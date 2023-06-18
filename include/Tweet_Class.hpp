#ifndef TWEET_HPP
#define TWEET_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

#include "User_Class.hpp"

class twitterak;


//================================================================================ Tweet_Class ================================================================================ 

class tweet
{
    public:
        tweet();
//================ gets =====================

        std::string get_tweetType() const;                                      // returns the type of a tweet(quote/retweet)
        std::string get_sefTweet() const;                                       // returns the user's tweet
        std::string get_ownerName() const;                                      // returns the name of the owner of another user
        std::string get_ownerUser_name() const;                                 // returns the username of the owner of another user
        std::string get_ownerTweet() const;                                     // returns the tweet of the owner of another user
        std::string get_name() const;                                           // returns the name of the user
        std::string get_user_name() const;                                      // returns the username of the user
        int get_number() const;                                                 // returns the tweet's number
        int get_user_age() const;                                               // returns the age of the user 

//================ sets =====================

        void set_tweetType(std::string);
        void set_type(std:: string);                                            // sets the type of a tweet(quote/retweet)
        void set_selfTweet(std:: string);                                       // sets the user's tweet
        void set_ownerName(std:: string);                                       // sets the name of the owner of another user
        void set_ownerUser_name(std:: string);                                  // sets the username of the owner of another user
        void set_ownerTweet(std:: string);                                      // sets the tweet of the owner of another user
        void set_name(std:: string);                                            // sets the name of the user
        void set_user_name(std:: string);                                       // sets the username of the user
        void set_number(int);                                                   // sets the tweet's number
        void set_user_age(user);                                                // sets the age of the user 
        
//============ General functions =============

        void delete_tweet(user, std::string, int);                               // deletes a tweet of a user 
        void edit_tweet();                                                       // edits a tweet of a user
        void rq_tweet(twitterak, std::string);                                   // quote tweet or retweet
        void fetch_hashtags(twitterak &,std::string);                            // finds and saves hashtags of user's tweet


    private:
        std::unordered_set<tweet> comments;
        
        std::unordered_set<std::string> likes;
        std::string tweet_type;
        std::string self_tweet;
        std::string &owner_name;
        std::string &owner_username;
        std::string &owner_tweet;
        std::vector<std::string> hashtags;
        std::string &name;
        std::string &user_name;
        int number;
        int user_age;
};

#endif