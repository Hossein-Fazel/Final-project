#include <iostream>
#include <unordered_map>

#include "Anonymous_User.hpp"
#include "Twitterak_Class.hpp"
#include "Mention_class.hpp"              

//------------------------------------------------------------------------
// constructor
Anonymous::Anonymous()
{
    set_name("Anonymous User");
}

//------------------------------------------------------------------------

void Anonymous::add_following(std::string user_name)
{
    following.insert(user_name);
}

//------------------------------------------------------------------------

int Anonymous::get_following_num() const
{
    return following.size();
}


std::unordered_set< std::string> Anonymous::get_following()
{
    return following;
}

std::unordered_map<std::string , std::unordered_set<int>> Anonymous::get_mention_trs()         // returns my_mention map
{
    return my_mentions;
}


std::unordered_map<std::string , std::unordered_set<int>> Anonymous::get_tweetlike_trs()       // returns tweet_likes map
{
    return tweetLikes;
}

//------------------------------------------------------------------------
// edits the user's information
void Anonymous::Edit(twitterak & app, std::string Edit_part ,std::string value)                                                                                                                
{
    Edit_part = to_lower(Edit_part);

    if (Edit_part == "username")
    {
        if (value[0] == '@')
            value = remove_atsing(value);

        set_username(value);
        std::unordered_map <std::string,Anonymous>::const_iterator got = app.ans_user.find(app.logedin_user);

        auto entry = app.ans_user.find(app.logedin_user);

        if (entry != end(app.ans_user))
        {
            auto const val = std::move(entry->second);
            app.ans_user.erase(entry);
            app.ans_user.insert({value, std::move(val)});
        }

        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
        app.logedin_user = value;
    }

    else if (Edit_part == "password")
    {
        app.ans_user[app.logedin_user].set_password(value);
        std::cout << "* Your " << Edit_part << " has been successfully changed.\n";
    }

    else
    {
        std:: cout << "! undefined edit part.\n";
    }
}

//------------------------------------------------------------------------
// shows the information of a user itself
void Anonymous::Show_Profile(twitterak & app)
{
    std::cout << "$ Name       : " << get_name() << std::endl;
    std::cout << "$ Username   : @" << get_username() << std::endl;
    std::cout << "$ Followings : " << get_following_num() << std::endl;
}

//------------------------------------------------------------------------
// follow a user that must be personal user
void Anonymous::follow(twitterak &app, std::string uName)
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
            std::cout << "! You can not follow this user.\n";
        }
        
        else
        {
            std::cout << "! There is no user with this username.\n";
        }
    }
}

//------------------------------------------------------------------------

void Anonymous::Delete_Account(twitterak &app)
{
    std::cout << "? This operation cannot be reversed in any way. Are you sure? (y/n) : ";

    char ch;
    std::cin >> ch;

    if (ch == 'y')
    {
        app.is_logedin = false;
        del_myMentions(app);
        del_tweetLikes(app);
        unfollow_followers(app);
        app.ans_user.erase(app.logedin_user);
        std::cout << "* You're account have successfully deleted.\n";
    }
}

//------------------------------------------------------------------------
//check the user name exist in following
bool Anonymous::isin_following(std::string user_name)
{
    if(following.count(user_name) == 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

//------------------------------------------------------------------------

void Anonymous::pop_tweetLikes(int number, std::string uName)
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

void Anonymous::push_tweetLikes(int number, std::string uName)
{
    tweetLikes[uName].insert(number);
}

//------------------------------------------------------------------------

void Anonymous::push_myMentions(int number, std::string uName)
{
    my_mentions[uName].insert(number);
}

//------------------------------------------------------------------------

void Anonymous::del_myMentions(twitterak &app)
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
                        app.users[i.first].del_men(j ,this->get_username());
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

void Anonymous::del_tweetLikes(twitterak &app)
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
                        app.users[i.first].del_tweetlike(j ,this->get_username());
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
// delete you from your followers list
void Anonymous::unfollow_followers(twitterak &app)
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