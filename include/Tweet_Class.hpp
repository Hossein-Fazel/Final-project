#ifndef TWEET_HPP
#define TWEET_HPP


#include <unordered_map>
#include <vector>
#include <string>

#include "User_Class.hpp"


class tweet
{
    public:
//============ sets ==================
        void set_tweetType();
        void set_sefTweet();
        void set_ownerName();
        void set_ownerUser_name();
        void set_ownerTweet();
        void set_hashtags();
        void set_name();
        void set_user();
        void set_number();

//============ General functions =============
        void delete_tweet();
        void edit_tweet();

    private:
        std::vector<tweet> comments;
        
        std::unordered_map<std::string, bool> likes;
        std::string tweet_type;
        std::string self_tweet;
        std::string owner_name;
        std::string owner_username;
        std::string owner_tweet;
        std::vector<std::string> hashtags;
        std::string name;
        std::string user_name;
        int number;
};

#endif