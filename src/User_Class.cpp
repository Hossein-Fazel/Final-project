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

std::string user::get_biography() const                // returns the biography of the user
{
    return Biography;
}

//------------------------------------------------------------------------

std::string user::get_link() const                    // returns the link of the user
{
    return Link;
}

//------------------------------------------------------------------------

std::string user::get_birthday() const              // returns the date of birth of the user
{
    return Birthday;
}

//------------------------------------------------------------------------

std::string user::get_phone() const                // returns the phone number of the user
{
    return Phone_Number;
}

//------------------------------------------------------------------------

std::string user::get_password() const            // returns the password of the user's account
{
    return Password;
}

//------------------------------------------------------------------------

std::string user::get_header() const            // returns the color of the header that user had chosen 
{
    return Header;
}

//------------------------------------------------------------------------

std::string user::get_country() const         // returns the color of the header that user had chosen 
{
    return Country;
}

//------------------------------------------------------------------------

int user::get_last_number() const                   // returns the last tweet's number
{
    return last_num;
}

//------------------------------------------------------------------------

int user::get_followers_num() const
{
    return followers.size();
}

//------------------------------------------------------------------------

int user::get_following_num() const
{
    return following.size();
}

//==================================================================  Set_Functions =================================================================

bool user::validate_phone_number(std::string phone)                              // validate user's phone_number
{
    for (int i = 0; i < phone.size(); i++)
    {
        if ((isdigit(phone[i])) == 0)
            return false;
    }

    return true;
}

//------------------------------------------------------------------------

void user::set_biography(std::string bio)                                        // sets the biography of a user
{
    if (bio.length() > 160)
        Biography = bio.erase(160, bio.length());

    else   
        Biography = bio;
}

//------------------------------------------------------------------------
                                                                                
void user::set_link(std::string input_link)                                     // sets the link of a user
{
    const std::string Https = "https://";
    Link = Https + input_link;
}

//------------------------------------------------------------------------

void user::set_birthday(std::string birth)                                     // sets the date of birth of a user
{
    Birthday = birth;
}

//------------------------------------------------------------------------

void user::set_phone(std::string input_phone)                                 // sets the phone number of a user
{
    while (1)
    {
        if (!(validate_phone_number(input_phone)))
        {
            std::cout << "! You're phone number is invalid.\n";
            std::cout << "$ Phone_Number : ";
            std::cin >> input_phone;
        }
    }
}

//------------------------------------------------------------------------

void user::set_header(std::string input_header)                             // sets the color of the header that user had chosen
{
    Header = input_header;
}

//------------------------------------------------------------------------

void user::set_country(std::string input_country)                          // sets the country of the user
{
    Country = input_country;
}

//================================================================  General_Functions ===============================================================

void user::Show_Profile(twitterak &app)                                                                    // shows the information of a user itself
{
    std::cout << "$ Header : " << get_header() << std::endl;
    std::cout << "$ Name : " << get_name() << std::endl;
    std::cout << "$ Username : @" << get_username() << std::endl;
    std::cout << "$ Birthday : " << get_birthday() << std::endl;
    std::cout << "$ Biography : " << get_biography() << std::endl;
    std::cout << "$ Link : " << get_link() << std::endl;
    std::cout << "$ Phone_Number : " << get_phone() << std::endl;
    std::cout << "$ country : " << get_country()   << std::endl;
}

//------------------------------------------------------------------------

void user::Edit(twitterak &app, std::string Edit_part ,std::string value)                                 // edits the user's information                                                                                    
{
    Edit_part = to_lower(Edit_part);

    if (Edit_part == "name")
    {
        app.users[app.logedin_user].set_name(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    if (Edit_part == "username")
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

    if (Edit_part == "biography")
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
}

//------------------------------------------------------------------------

void user::Tweet(std::string tweet_text, twitterak & app)                                                                                                  // make a normal tweet                                              
{
    // std::string twt;
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
        app.users.erase(app.logedin_user);
        std::cout << "* You're account have successfully deleted.\n";
    }
}

//------------------------------------------------------------------------

void user::Logout(twitterak &app)                                                                                // logs out of the user's account       
{
    app.is_logedin = false;
    std::cout << "* You have successfully logged out.\n";
}

//------------------------------------------------------------------------

void user::Push_Tweet(tweet tw)                                                                                  // push a tweet into a vector
{
    tweets[tw.get_number()] = tw;
}

//------------------------------------------------------------------------

void user::last_number()                                                                                         // plus plus last_num variable
{
    last_num++;
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

std::map <int, tweet> user::get_tweets()
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
        tweets[tNum].edit_tweet(app, tNum);
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
            if(this->following.count(uName) == 1)
            {
                std::cout << "! You have already followed this user.\n";
            }
            else
            {
                this->following.insert(uName);
                app.users[uName].add_followers(uName);
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

void user::add_followers(std::string uName)
{
    this->followers.insert(uName);
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

//============================================== Delete_User_Traces =========================================

void user::push_myMentions(int number, std::string uName)
{
    my_mentions[uName].insert(number);
}

//------------------------------------------------------------------------

void user::del_myMentions(twitterak &app)
{
    for(auto i : my_mentions)
    {
        if(i.first != this->Username)
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j : i.second)
                {
                    if(app.users[i.first].tweets.count(j) == 1)
                    {
                        app.users[i.first].tweets[j].delete_mentions(this->Username);
                    }
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
        if(i.first != this->Username)
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j:i.second)
                {
                    if(app.users[i.first].tweets.count(j))
                    {
                        app.users[i.first].tweets[j].dLike(this->Username);
                    }
                }
            }
        }
    }
}