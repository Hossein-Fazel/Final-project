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


int tweet::get_user_age() const
{
    return user_age;
}

//==================================================================  Set_Functions =================================================================

void tweet::set_tweetType(std::string type)
{
    tweet_type = type;
}

void tweet::set_selfTweet(std::string tweet)
{
    self_tweet = tweet;
}

void tweet::set_ownerName(std::string name)
{
    owner_name = name;
}

void tweet::set_ownerUser_name(std::string user_name)
{
    owner_username = user_name;
}

void tweet::set_ownerTweet(std::string tweet)
{
    owner_tweet = tweet;
}


void tweet::set_name(std:: string name)
{
    this->name = name;
}

void tweet::set_user_name(std:: string user_name)
{
    this->user_name = user_name;
}

void tweet::set_number(int number)
{
    this->number = number;
}

void tweet::set_user_age(user usr)
{
    int user_birth;
    user_birth = std::stoi(usr.get_birthday().substr(0,3));
    user_age = 2023 - user_birth;
}

//================================================================  General_Functions ===============================================================