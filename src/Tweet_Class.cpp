#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_set>

#include "Tweet_Class.hpp"
#include "Twitterak_Class.hpp"
#include "Mention_class.hpp"

//==================================================================  Get_Functions =================================================================

std::string tweet::get_tweetType() const                                                              // returns the type of tweet(quote/retweet)
{
    return tweet_type;
}

//------------------------------------------------------------------------

std::string tweet::get_sefTweet() const                                                                // returns the user's tweet
{
    return self_tweet;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerName() const                                                                // returns the name of the owner of another user
{
    return owner_name;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerUser_name() const                                                            // returns the username of the owner of another user
{
    return owner_username;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerTweet() const                                                                 // returns the tweet of the owner of another user
{
    return owner_tweet;
}

//------------------------------------------------------------------------

std::string tweet::get_name() const                                                                        // returns the name of the user
{
    return name;
}

//------------------------------------------------------------------------

std::string tweet::get_user_name() const                                                                    // returns the username of the user
{
    return user_name;
}

//------------------------------------------------------------------------

int tweet::get_number() const                                                                                // returns the tweet's number
{
    return number;
}

//------------------------------------------------------------------------

int tweet::get_user_age() const                                                                               // returns the age of the user 
{
    return user_age;
}

//==================================================================  Set_Functions =================================================================

void tweet::set_tweetType(std::string type)                                                                    // sets the type of a tweet(quote/retweet)
{
    tweet_type = type;
}

//------------------------------------------------------------------------

void tweet::set_selfTweet(std::string tweet)                                                                    // sets the user's tweet
{
    self_tweet = tweet;
}

//------------------------------------------------------------------------

void tweet::set_ownerName(std::string name)                                                                      // sets the name of the owner of another user
{
    owner_name = name;
}

//------------------------------------------------------------------------

void tweet::set_ownerUser_name(std::string user_name)                                                            // sets the username of the owner of another user
{ 
    owner_username = user_name;
}

//------------------------------------------------------------------------

void tweet::set_ownerTweet(std::string tweet)                                                                      // sets the tweet of the owner of another user
{
    owner_tweet = tweet;
}

//------------------------------------------------------------------------

void tweet::set_name(std:: string got_name)                                                                             // sets the name of the user
{
    name = got_name;
}

//------------------------------------------------------------------------

void tweet::set_user_name(std:: string Guser_name)                                                                    // sets the username of the user
{
    user_name = Guser_name;
}

//------------------------------------------------------------------------

void tweet::set_number(int number)                                                                                   // sets the tweet's number
{
    this->number = number;
}

//------------------------------------------------------------------------

void tweet::set_user_age(user usr)                                                                                    // sets the age of the user 
{
    int user_birth;
    user_birth = std::stoi(usr.get_birthday().substr(0,3));
    user_age = 2023 - user_birth;
}

//================================================================  General_Functions ===============================================================

void tweet::delete_tweet(twitterak app, int number)                                                                  // deletes a tweet of a user 
{
    if(app.users[app.logedin_user].tweets.count(number))
    {
        app.users[app.logedin_user].tweets.erase(number);
    }
    else
    {
        std::cout << "! There is no tweet wtih this number.\n";
    }
}

//------------------------------------------------------------------------

void tweet::edit_tweet(twitterak &app, int number)                                                                                              // edits a tweet of a user
{
    if(get_user_age() >= 18)
    {
        if(hashtags.size() != 0)
        {
            this->delete_hashtags(app);
            this->hashtags.clear();
        }
        std::string E_tweet;

        std::cout << number << " : " << this->get_sefTweet() << std::endl;
        std::cout << "* Enter new text for tweet " << number << " : ";
        std::getline(std::cin, E_tweet);

        this->set_selfTweet(E_tweet);
        this->fetch_hashtags(app,E_tweet);
        std::cout << "* You're tweet has been successfully changed.\n";
        // std::cin.ignore();
    }
    else
    {
        std::cout << "! Your age is less than 18.\n";
    }
}

//------------------------------------------------------------------------

void tweet::rq_tweet(twitterak &app, std:: string type)                                                                // quote tweet or retweet
{
    tweet rq_tweet;
    rq_tweet.set_tweetType(type);
    rq_tweet.set_ownerTweet(this->self_tweet);
    rq_tweet.set_ownerUser_name(this->user_name);
    rq_tweet.set_ownerName(this->name);

    rq_tweet.set_name(app.users[app.logedin_user].get_name());
    rq_tweet.set_user_name(app.users[app.logedin_user].get_username());
    rq_tweet.set_number(app.users[app.logedin_user].get_last_number() + 1);

    if(type == "qoute")
    {
        std::string tweet;
        std::cout << "$ your tweet : ";
        std::getline(std::cin, tweet);
        // std::cin.ignore();

        while (tweet.empty())
        {
            std::cout << "! Please enter your tweet\n";
            std::cout << "$ your tweet : ";
            std::getline(std::cin, tweet);
            // std::cin.ignore();
        }

        rq_tweet.set_selfTweet(tweet);
    }

    app.users[app.logedin_user].Push_Tweet(rq_tweet);
}

//------------------------------------------------------------------------

int tweet::get_like_number() const
{
    return likes.size();
}
//------------------------------------------------------------------------

void tweet::fetch_hashtags(twitterak &app, std::string tweet)                                                    // finds and saves hashtags of user's tweet
{
    std::string hashtag;
    int tsize = tweet.size();

    for(int i = 0; i < tsize; i++)
    {
        if(tweet[i] == '#')
        {
            for(int j = i+1; j < tsize; j++)
            {
                if(tweet[j] != ' ')
                {
                    hashtag += tweet[j];
                }
                else
                {
                    if(!hashtag.empty())
                    {
                        hashtags.push_back(hashtag);
                        app.Hashtags[hashtag].push_back(*this);
                    }
                    hashtag = "";
                    i = j;
                    break;
                }
            }
        }
    }
    hashtags.push_back(hashtag);
}

//-----------------------------------------------------------------------

std::unordered_map<std::string, bool> tweet::operator~() const
{
    return likes;
}

//-----------------------------------------------------------------------

void tweet::tweet_like(std::string user_name)
{
    if(likes.count(user_name) == 0)
    {
        likes[user_name] = true;
    }
    else
    {
        std::cout << "! You have already liked the tweet.\n";
    }
}

//-----------------------------------------------------------------------

void tweet::tweet_dislike(std::string user_name)
{
    if(likes.count(user_name))
    {
        likes.erase(user_name);
    }
    else
    {
        std::cout << "! You have never lke this tweet\n";
    }
}

//-----------------------------------------------------------------------

void tweet::creat_mention(std::string guserName, std::string gname)
{
    mention ment;

    std::string txt;
    std::cout << "$ your mention : ";
    std::getline(std::cin, txt);

    ment.set_mention(txt);
    ment.set_name(gname);
    ment.set_userName(guserName);
    ment.set_number(mentionNumber);

    mentionNumber += 1;

    tweet_mentions[guserName].push_back(ment);

    std::cout << "* Your mention was create successfully.\n";
}

//-----------------------------------------------------------------------

int tweet::get_mentions_number() const
{
    int size = 0;

    for(auto i:tweet_mentions)
    {
        size += i.second.size();
    }

    return size;
}

//-----------------------------------------------------------------------

void tweet::delete_hashtags(twitterak &app)
{
    for(auto hashtag :hashtags)
    {
        int vSize = app.Hashtags[hashtag].size();
        for(int i = 0; i < vSize; i++)
        {
            if(app.Hashtags[hashtag][i].get_number() == this->get_number() and app.Hashtags[hashtag][i].get_user_name() == this->get_user_name())
            {
                app.Hashtags[hashtag].erase(app.Hashtags[hashtag].begin() + i);
                break;
            }
        }
    }
}

//-----------------------------------------------------------------------

void tweet::delete_mentions(std::string got_userName)
{
    tweet_mentions.erase(got_userName);
}