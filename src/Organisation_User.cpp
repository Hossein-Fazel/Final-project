#include <iostream>
#include <string>
#include <unordered_map>

#include "Twitterak_Class.hpp"
#include "Organisation_User.hpp"
#include "sha256.h"

//==================================================================  Get_Functions =================================================================

// shows the usernsmae of an organisation's manager
std::string Organisation::get_manager_username() const
{
    return manager->get_username();
}

//------------------------------------------------------------------------
// shows the last number of a tweet
int Organisation::get_last_number() const
{
    return last_number;
}

//------------------------------------------------------------------------
// shows organisation's tweets
std::unordered_map <int, tweet> Organisation::get_tweets()
{
    return tweets;
}

std::unordered_set<std::string> Organisation::get_following()
{
    return following;
}

//==================================================================  Set_Functions =================================================================
// sets the usernsmae of an organisation's manager 
void Organisation::set_manager_username(twitterak app,std::string username)
{
    if (username[0] == '@')
        username = remove_atsing(username);

    username = to_lower(username);
    app.del_atsign(username);

    while (1)
    {
        if (app.users.count(username) == 1)
        {
            manager = &app.users[username];
            break;
        }

        else 
        {
            std::cout << "! The username doesn't exist.\n";
            std::cout << "$ Manager username : ";
            std::cin >> username;
        }
    }
    
}

//------------------------------------------------------------------------
// sets the biography of an organisation
void Organisation::set_biography(std::string bio)
{
    if (bio.length() > 1100)
        Biography = bio.erase(1100, bio.length());

    else   
        Biography = bio;
}

//------------------------------------------------------------------------
// delets the account of an organisation
void Organisation::Delete_Account(twitterak & app) 
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
        unfollow_followers(app);
        app.org_user.erase(app.logedin_user);
        std::cout << "* You're account have successfully deleted.\n";
    }
}

//------------------------------------------------------------------------
// shows the information of an organisation itself
void Organisation::Show_Profile(twitterak & app)                                                       
{
    std::cout << "$ Header           : " << get_header() << std::endl;
    std::cout << "$ Name             : " << get_name() << std::endl;
    std::cout << "$ Username         : @" << get_username() << std::endl;
    std::cout << "$ Manager_Username : @" << get_manager_username() << std::endl;
    std::cout << "$ Biography        : " << get_biography() << std::endl;
    std::cout << "$ Link             : " << get_link() << std::endl;
    std::cout << "$ Phone_Number     : " << get_phone() << std::endl;
    std::cout << "$ country          : " << get_country()   << std::endl;
    std::cout << "$ Followers        : " << get_followers_num() << std::endl;
}

//------------------------------------------------------------------------
// edits an organisation's information
void Organisation::Edit(twitterak &app, std::string Edit_part ,std::string value)                                                                                                          
{
    Edit_part = to_lower(Edit_part);

    if (Edit_part == "name")
    {
        app.org_user[app.logedin_user].set_name(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    if (Edit_part == "username")
    {
        if (value[0] == '@')
            value = remove_atsing(value);

        set_username(value);
        std::unordered_map <std::string, Organisation>::const_iterator got = app.org_user.find(app.logedin_user);                     

        auto entry = app.org_user.find(app.logedin_user);

        if (entry != end(app.org_user))
        {
            auto const val = std::move(entry->second);
            app.org_user.erase(entry);
            app.org_user.insert({value, std::move(val)});
        }

        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
        app.logedin_user = value;
    }

    if (Edit_part == "biography")
    {
        if (value.length() > 160) 
            value.erase(160, value.length());

        app.org_user[app.logedin_user].set_biography(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "link")
    {
        app.org_user[app.logedin_user].set_link(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "phone_number")
    {
        app.org_user[app.logedin_user].set_phone(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "password")
    {
        app.org_user[app.logedin_user].set_password(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else if (Edit_part == "header")
    {
        app.org_user[app.logedin_user].set_header(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }
 
    else if (Edit_part == "country")
    {
        app.org_user[app.logedin_user].set_country(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else
    {
        std:: cout << "! undefined edit part.\n";
    }
}

//================================================================  General_Functions ===============================================================
void Organisation::unfollow(std::string user_name)
{
    followers.erase(user_name);
}

//------------------------------------------------------------------------
// edits an organisation's tweet
void Organisation::edit_tweet(int tNum, twitterak & app)
{
    if(this->tweets.count(tNum) == 1)
    {
        this->tweets[tNum].edit_tweet(app);
    }
}

//------------------------------------------------------------------------
// make a tweet
void Organisation::Tweet(std::string tweet_text, twitterak & app)                                                                                                                          
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
    }
    
    tw.set_selfTweet(tweet_text);
    tw.fetch_hashtags(app);

    increase_last_number();

    Push_Tweet(tw);
}

//------------------------------------------------------------------------
// push a tweet into a vector
void Organisation::Push_Tweet(tweet tw)
{
    tweets[tw.get_number()] = tw;
}

//------------------------------------------------------------------------

void Organisation::increase_last_number()
{
    last_number += 1;
}

//------------------------------------------------------------------------

void Organisation::print_likers(int num)
{
    if(tweets.count(num))
    {
        if(~tweets[num].get_like_number() ==0)
        {
            std::cout << "! This tweet has no like.\n";
        }
        else
        {
            for(auto liker:~tweets[num])
            {
                std::cout << liker.first << '\n';
            }
        }
    }
}

//------------------------------------------------------------------------

bool Organisation::like(std::string user_name,int num)
{
    if(tweets.count(num) == 1)
    {
        bool status;
        status = tweets[num].tweet_like(user_name);
        return status;
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
        return false;
    }
}

//------------------------------------------------------------------------

bool Organisation::dislike(std::string user_name, int num)
{
    if(tweets.count(num) == 1)
    {
        bool status;
        status = tweets[num].tweet_dislike(user_name);
        return status;
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
        return false;
    }
}

//------------------------------------------------------------------------

bool Organisation::add_mention(int tweet_number, std::string got_name, std::string got_user_name)
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

void Organisation::follow(twitterak &app, std::string uName)
{
    if(uName == app.logedin_user)
    {
        std::cout << "! You can not follow yourself.\n";
    }
    else
    {
        if(app.users.count(uName) == 1 )
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

void Organisation::like_mention(int tNumber, std::string uName, int mNumber)
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

//================================================================  Save_Organisation_Traces ===============================================================

// save my mention traces
void Organisation::push_myMentions(int num, std::string uName)
{
    my_mentions[uName].insert(num);
}

//------------------------------------------------------------------------
// save my tweet likes traces
void Organisation::push_tweetLikes(int num, std::string uName)
{
    tweetLikes[uName].insert(num);
}

//------------------------------------------------------------------------
// delete a like of a tweet
void Organisation::pop_tweetLikes(int num, std::string uName)
{   
    if(tweetLikes.count(uName) == 1)
    {
        tweetLikes[uName].erase(num);
        if(tweetLikes[uName].size() == 0)
        {
            tweetLikes.erase(uName);
        }
    }
}

//================================================================  Delete_Organisation_Traces ===============================================================

// delete mention traces
void Organisation::del_myMentions(twitterak &app)
{
    for(auto i : my_mentions)
    {
        if(i.first != this->get_username())
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j : i.second)
                {
                    if(app.users[i.first].get_tweets().count(j) == 1)
                    {
                        app.users[i.first].del_tweetlike(j ,this->get_username());
                    }
                }
            }

            else if(app.org_user.count(i.first) == 1)
            {
                for(auto j : i.second)
                {
                    if(app.org_user[i.first].tweets.count(j) == 1)
                    {
                        app.org_user[i.first].tweets[j].delete_mentions(this->get_username());
                    }
                }
            }
        }
    }
}

//------------------------------------------------------------------------
// delete hashtag traces
void Organisation::cls_hashtags(twitterak &app)
{
    for(auto i: tweets)
    {
        i.second.delete_hashtags(app);
    }
}

//------------------------------------------------------------------------
// delete tweet like traces
void Organisation::del_tweetLikes(twitterak &app)
{
    for(auto i: tweetLikes)
    {
        if(i.first != this->get_username())
        {
            if(app.users.count(i.first) == 1)
            {
                for(auto j:i.second)
                {
                    if(app.users[i.first].get_tweets().count(j))
                    {
                        app.users[i.first].del_men(j ,this->get_username());
                    }
                }
            }

            else if(app.org_user.count(i.first) == 1)
            {
                for(auto j:i.second)
                {
                    if(app.org_user[i.first].tweets.count(j))
                    {
                        app.org_user[i.first].tweets[j].dLike(this->get_username());
                    }
                }
            }
        }
    }
}

//------------------------------------------------------------------------
// delete a mention
void Organisation::del_men(int tNum, std::string user_name)                           
{
    tweets[tNum].delete_mentions(user_name);
}

//------------------------------------------------------------------------
// delete a tweet like
void Organisation::del_tweetlike(int tNum, std::string user_name)
{
    tweets[tNum].dLike(user_name);
}

//------------------------------------------------------------------------

void Organisation::unfollow_followers(twitterak &app)
{
    for(auto i : following)
    {
        if(app.users.count(i) == 1)
        {
            app.users[i].unfollow(this->get_username());
        }

        else if(app.org_user.count(i) == 1)
        {
            app.org_user[i].unfollow(this->get_username());
        }
    }
}