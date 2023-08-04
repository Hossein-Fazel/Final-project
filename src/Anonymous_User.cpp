#include <iostream>
#include <unordered_map>

#include "Anonymous_User.hpp"
#include "Twitterak_Class.hpp"
#include "Mention_class.hpp"                // منشن بزاره اگر که دنبالش کرده

//------------------------------------------------------------------------
// constructor
Anonymous::Anonymous()
{
    set_name("Anonymous User");
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
}

//------------------------------------------------------------------------
//
void Anonymous::like_mention(int, std::string, int)
{
    // Hossein
}

//------------------------------------------------------------------------
// add a new follower to set (no one can follow this user)
void Anonymous::add_followers(std::string)
{
    // Hossein
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
                app.users[uName].add_followers(uName);
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
