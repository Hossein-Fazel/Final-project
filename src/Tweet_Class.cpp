#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

#include "Tweet_Class.hpp"

//==================================================================  Get_Functions =================================================================

std::string tweet::get_tweetType() const                                                // returns the type of tweet(quote/retweet)
{
    return tweet_type;
}


std::string tweet::get_sefTweet() const                                                // returns the user's tweet
{
    return self_tweet;
}


std::string tweet::get_ownerName() const                                              // returns the name of the owner of another user
{
    return owner_name;
}


std::string tweet::get_ownerUser_name() const                                        // returns the username of the owner of another user
{
    return owner_username;
}


std::string tweet::get_ownerTweet() const                                           // returns the tweet of the owner of another user
{
    return owner_tweet;
}


std::string tweet::get_name() const                                                // returns the name of the user
{
    return name;
}


std::string tweet::get_user_name() const                                          // returns the username of the user
{
    return user_name;
}


int tweet::get_number() const                                                    // returns the tweet's number
{
    return number;
}

//==================================================================  Set_Functions =================================================================



//================================================================  General_Functions ===============================================================