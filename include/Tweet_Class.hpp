#ifndef TWEET_HPP
#define TWEET_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

#include "User_Class.hpp"


class tweet
{
    public:
//================ gets =====================

        std::string get_tweetType() const;                                      // returns the type of tweet(quote/retweet)
        std::string get_sefTweet() const;                                       // returns the user's tweet
        std::string get_ownerName() const;                                      // returns the name of the owner of another user
        std::string get_ownerUser_name() const;                                 // returns the username of the owner of another user
        std::string get_ownerTweet() const;                                     // returns the tweet of the owner of another user
        std::string get_name() const;                                           // returns the name of the user
        std::string get_user_name() const;                                      // returns the username of the user
        int get_number() const;                                                 // returns the tweet's number

//================ sets =====================

        void set_tweetType();
        void set_sefTweet();
        void set_ownerName();
        void set_ownerUser_name();
        void set_ownerTweet();
        void set_hashtags();
        void set_name();
        void set_user_name();
        void set_number();
        void set_user_age();
        
//============ General functions =============

        void delete_tweet();
        void edit_tweet();
        void rq_tweet();
        void hastags();


    private:
        std::unordered_set<tweet> comments;
        
        std::unordered_set<std::string> likes;
        std::string tweet_type;
        std::string self_tweet;
        std::string owner_name;
        std::string owner_username;
        std::string owner_tweet;
        std::vector<std::string> hashtags;
        std::string name;
        std::string user_name;
        int number;
        int user_age;

};

#endif