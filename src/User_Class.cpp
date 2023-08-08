#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctype.h>
#include <iterator>
#include <cctype>
#include "sha256.h"


#include "Twitterak_Class.hpp"
#include "Mention_class.hpp"

#include "User_Class.hpp"

//==================================================================  Get_Functions =================================================================

std::string user::get_birthday() const              // returns the date of birth of the user
{
    return Birthday;
}

//------------------------------------------------------------------------

int user::get_last_number() const                   // returns the last tweet's number
{
    return last_num;
}

//------------------------------------------------------------------------

int user::get_following_num() const                // returns the following numbers
{
    return following.size();
}

//==================================================================  Set_Functions =================================================================

void user::set_birthday(std::string birth)                                     // sets the date of birth of a user
{
    Birthday = birth;
}

//================================================================  General_Functions ===============================================================

// shows the information of a user itself
void user::Show_Profile(twitterak & app)                                                                    
{
    std::cout << "$ Header       : " << get_header() << std::endl;
    std::cout << "$ Name         : " << get_name() << std::endl;
    std::cout << "$ Username     : @" << get_username() << std::endl;
    std::cout << "$ Birthday     : " << get_birthday() << std::endl;
    std::cout << "$ Biography    : " << get_biography() << std::endl;
    std::cout << "$ Link         : " << get_link() << std::endl;
    std::cout << "$ Phone_Number : " << get_phone() << std::endl;
    std::cout << "$ country      : " << get_country()   << std::endl;
    std::cout << "$ Followers    : " << get_followers_num() << std::endl;
    std::cout << "$ Followings   : " << get_following_num() << std::endl;
}

//------------------------------------------------------------------------
// edits the user's information 
void user::Edit(twitterak &app, std::string Edit_part ,std::string value)                                                                                                                    
{
    Edit_part = to_lower(Edit_part);

    if (Edit_part == "name")
    {
        app.users[app.logedin_user].set_name(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "username")
    {
        if (value[0] == '@')
            value = remove_atsing(value);

        set_username(value);
        std::unordered_map <std::string,user>::const_iterator got = app.users.find(app.logedin_user);

        auto entry = app.users.find(app.logedin_user);

        if (entry != end(app.users))
        {
            auto const val = std::move(entry->second);
            app.users.erase(entry);
            app.users.insert({value, std::move(val)});
        }

        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
        app.logedin_user = value;
    }

    else if (Edit_part == "biography")
    {
        if (value.length() > 160) 
            value.erase(160, value.length());

        app.users[app.logedin_user].set_biography(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "link")
    {
        app.users[app.logedin_user].set_link(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }


    else if (Edit_part == "birthday")
    {
        app.users[app.logedin_user].set_birthday(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }


    else if (Edit_part == "phone_number")
    {
        app.users[app.logedin_user].set_phone(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "password")
    {
        app.users[app.logedin_user].set_password(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "header")
    {
        app.users[app.logedin_user].set_header(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }
 
    else if (Edit_part == "country")
    {
        app.users[app.logedin_user].set_country(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else
    {
        std:: cout << "! undefined edit part.\n";
    }
}

//------------------------------------------------------------------------

void user::Tweet(std::string tweet_text, twitterak & app)                                                                                                  // make a normal tweet                                              
{
    tweet tw;
    tw.set_tweetType("normal");

    tw.set_name(get_name());
    tw.set_user_name(get_username());
    tw.set_number(get_last_number()+1);

    while (tweet_text.empty())
    {
        std::cout << "$ your tweet : ";
        getline(std::cin, tweet_text);
        // std::cin.ignore();
    }
    
    tw.set_selfTweet(tweet_text);
    tw.fetch_hashtags(app);

    last_number();

    Push_Tweet(tw);
}

//------------------------------------------------------------------------

void user::Delete_Account(twitterak &app)                                                                         // deletes the account of the use      
{
    std::cout << "? This operation cannot be reversed in any way. Are you sure? (y/n) : ";

    char ch;
    std::cin >> ch;

    if (ch == 'y')
    {
        app.is_logedin = false;
        del_myMentions(app);
        del_tweetLikes(app);
        cls_hashtags(app);
        std::cout << "deleting followers\n"; 
        unfollow_followers(app);
        std::cout << "followers deleted.\n"; 
        app.users.erase(app.logedin_user);
        std::cout << "* You're account have successfully deleted.\n";
    }
}

//------------------------------------------------------------------------

void user::Push_Tweet(tweet tw)                                                                                  // push a tweet into a vector
{
    tweets[tw.get_number()] = tw;
}

//------------------------------------------------------------------------

void user::last_number()                                                                                         // plus plus last_num variable
{
    last_num += 1;
}

//------------------------------------------------------------------------

void user::print_likers(int number)
{
    if(tweets.count(number))
    {
        if(~tweets[number].get_like_number() ==0)
        {
            std::cout << "! This tweet has no like.\n";
        }
        else
        {
            for(auto liker:~tweets[number])
            {
                std::cout << liker.first << '\n';
            }
        }
    }
}

//------------------------------------------------------------------------

bool user::like(std::string user_name, int number)
{
    if(tweets.count(number) == 1)
    {
        bool status;
        status = tweets[number].tweet_like(user_name);
        return status;
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
        return false;
    }
}

//------------------------------------------------------------------------

bool user::dislike(std::string user_name, int number)
{
    if(tweets.count(number) == 1)
    {
        bool status;
        status = tweets[number].tweet_dislike(user_name);
        return status;
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
        return false;
    }
}

//------------------------------------------------------------------------

std::unordered_map <int, tweet> user::get_tweets()
{
    return tweets;
}

//------------------------------------------------------------------------

bool user::add_mention(int tweet_number, std::string got_name, std::string got_user_name)
{
    if(tweets.count(tweet_number) == 1)
    {
        tweets[tweet_number].creat_mention(got_user_name, got_name);
        return true;
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
        return false;
    }
}

//------------------------------------------------------------------------

void user::edit_tweet(int tNum, twitterak & app)
{
    if(tweets.count(tNum) == 1)
    {
        tweets[tNum].edit_tweet(app);
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
    }
}

//------------------------------------------------------------------------

void user::follow(twitterak &app, std::string uName)
{
    if(uName == app.logedin_user)
    {
        std::cout << "! You can not follow yourself.\n";
    }
    else
    {
        if(app.users.count(uName) == 1)
        {
            if(following.count(uName) == 1)
            {
                std::cout << "! You have already followed this user.\n";
            }
            else
            {
                this->following.insert(uName);
                app.users[uName].add_followers(this->get_username());
                std::cout << "* Followed.\n";
            }
        }

        else if(app.ans_user.count(uName) == 1)
        {
            std::cout << "! You can not follow this user.\n";
        }
        
        else if (app.org_user.count(uName) == 1)
        {
            if(following.count(uName) == 1)
            {
                std::cout << "! You have already followed this user.\n";
            }
            else
            {
                this->following.insert(uName);
                app.org_user[uName].add_followers(this->get_username());
                std::cout << "* Followed.\n";
            }
        }
        
        else
        {
            std::cout << "! There is no user with this username.\n";
        }
    }
}

//------------------------------------------------------------------------

void user::like_mention(int tNumber, std::string uName, int mNumber)
{
    if(tweets.count(tNumber) == 1)
    {
        tweets[tNumber].mention_like(uName , mNumber);
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
    }
}

//------------------------------------------------------------------------

void user::unfollow(std::string user_name)
{
    this->followers.erase(user_name);
}

//============================================== Delete_User_Traces =========================================

void user::del_men(int tNum, std::string user_name)                           // delete a mention
{
    tweets[tNum].delete_mentions(user_name);
}

//------------------------------------------------------------------------

void user::del_tweetlike(int tNum, std::string user_name)                    // delete a tweet like
{
    tweets[tNum].dLike(user_name);
}

//------------------------------------------------------------------------

void user::push_myMentions(int number, std::string uName)
{
    my_mentions[uName].insert(number);
}

//------------------------------------------------------------------------

void user::del_myMentions(twitterak &app)
{
    for(auto i : my_mentions)
    {
        if(i.first != this->get_username())
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j : i.second)
                {
                    if(app.users[i.first].tweets.count(j) == 1)
                    {
                        app.users[i.first].tweets[j].delete_mentions(this->get_username());
                    }
                }
            }
        }

        else if(app.org_user.count(i.first) == 1)
            {
                for(auto j : i.second)
                {
                    if(app.org_user[i.first].get_tweets().count(j) == 1)
                    {
                        app.org_user[i.first].del_men(j ,this->get_username());
                    }
                }
            }
    }
}

//------------------------------------------------------------------------

void user::cls_hashtags(twitterak &app)
{
    for(auto i: tweets)
    {
        i.second.delete_hashtags(app);
    }
}

//------------------------------------------------------------------------

void user::push_tweetLikes(int number, std::string uName)
{
    tweetLikes[uName].insert(number);
}

//------------------------------------------------------------------------

void user::pop_tweetLikes(int number, std::string uName)
{
    if(tweetLikes.count(uName) == 1)
    {
        tweetLikes[uName].erase(number);
        if(tweetLikes[uName].size() == 0)
        {
            tweetLikes.erase(uName);
        }
    }
}

//------------------------------------------------------------------------

void user::del_tweetLikes(twitterak &app)
{
    for(auto i: tweetLikes)
    {
        if(i.first != this->get_username())
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j:i.second)
                {
                    if(app.users[i.first].tweets.count(j))
                    {
                        app.users[i.first].tweets[j].dLike(this->get_username());
                    }
                }
            }

            else if(app.org_user.count(i.first) == 1)
            {
                for(auto j:i.second)
                {
                    if(app.org_user[i.first].get_tweets().count(j))
                    {
                        app.org_user[i.first].del_tweetlike(j ,this->get_username());
                    }
                }
            }
        }
    }
}

//------------------------------------------------------------------------

void user::unfollow_followers(twitterak &app)
{
    for(auto i : following)
    {
        if(app.users.count(i) == 1)
        {
            app.users[i].unfollow(app.logedin_user);
        }

        else if(app.org_user.count(i) == 1)
        {
            app.org_user[i].unfollow(this->get_username());
        }
    }
}