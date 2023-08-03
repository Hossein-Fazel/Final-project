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
    return manager_username;
}

//------------------------------------------------------------------------
// shows the biography of an organisation account 
std::string Organisation::get_biography() const
{
    return organisation_bio;
}

//------------------------------------------------------------------------
// shows the link of an organisation account
std::string Organisation::get_link() const
{
    return organisation_link;
}

//------------------------------------------------------------------------
// shows the phone number of an organisation
std::string Organisation::get_phone() const
{
    return organisation_phone;
}

//------------------------------------------------------------------------
// shows the color of the header that an organisation had chosen
std::string Organisation::get_header() const
{
    return organisation_header;
}

//------------------------------------------------------------------------
// shows the country of an organisation
std::string Organisation::get_country() const
{
    return organisation_country;
}

//------------------------------------------------------------------------
// shows the last number of a tweet
int Organisation::get_last_number() const
{
    return last_number;
}

//------------------------------------------------------------------------
// shows organisation's tweets
std::map <int, tweet> Organisation::get_tweets() const
{
    // Hossein
}

//==================================================================  Set_Functions =================================================================

// sets the usernsmae of an organisation's manager 
void Organisation::set_manager_username(twitterak app,std::string username)
{
    if (app.org_user.count(username) == 1)
        manager_username = username;
    
    else 
        std::cout << "! The username doesn't exist.\n";
}

//------------------------------------------------------------------------
// sets the biography of an organisation account
void Organisation::set_biography(std::string bio)
{
    if (bio.length() > 1100)
        organisation_bio = bio.erase(160, bio.length());

    else   
        organisation_bio = bio;
}

//------------------------------------------------------------------------
// sets the link of an organisation account
void Organisation::set_link(std::string link)
{
    const std::string Https = "https://";
    organisation_link = Https + link;
}

//------------------------------------------------------------------------
// sets the phone number of an organisation
void Organisation::set_phone(std::string phone)
{
    while (1)
    {
        if (!(validate_phone_number(phone)))
        {
            std::cout << "! You're phone number is invalid.\n";
            std::cout << "$ Phone_Number : ";
            std::cin >> phone;
        }
    }
}

//------------------------------------------------------------------------
// sets the color of the header that an organisation had chosen
void Organisation::set_header(std::string header)
{
    organisation_header = header;
}

//------------------------------------------------------------------------
// sets the country of an organisation
void Organisation::set_country(std::string country)
{
    organisation_country = country;
}

//------------------------------------------------------------------------
// delets the account of an organisation
void Organisation::Delete_Account(twitterak & app) 
{
    // Hossein
}

//------------------------------------------------------------------------
// shows the information of an organisation itself
void Organisation::Show_Profile(twitterak & app) //check
{
    std::cout << "$ Header : " << get_header() << std::endl;
    std::cout << "$ Name : " << get_name() << std::endl;
    std::cout << "$ Username : @" << get_username() << std::endl;
    std::cout << "$ Manager_Username : @" << get_manager_username() << std::endl;
    std::cout << "$ Biography : " << get_biography() << std::endl;
    std::cout << "$ Link : " << get_link() << std::endl;
    std::cout << "$ Phone_Number : " << get_phone() << std::endl;
    std::cout << "$ country : " << get_country()   << std::endl;
}

//------------------------------------------------------------------------
// edits an organisation's information
void Organisation::Edit(twitterak &app, std::string Edit_part ,std::string value)                                 // edits the user's information                                                                                    
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
        std::unordered_map <std::string, Organisation>::const_iterator got = app.org_user.find(app.logedin_user);                       // bug

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
}

//================================================================  General_Functions ===============================================================

// edits an organisation's tweet
void Organisation::edit_tweet(int tNum, twitterak & app)
{
    // Hossein
}

//------------------------------------------------------------------------
// make a tweet
void Organisation::Tweet(std::string tweet_text, twitterak & app)                                                                                                                          
{
    // Hossein
}

//------------------------------------------------------------------------
// push a tweet into a vector
void Organisation::Push_Tweet(tweet tw)
{
    // Hossein
}

//------------------------------------------------------------------------

void Organisation::last_number()
{
    // Hossein
}

//------------------------------------------------------------------------

void Organisation::print_likers(int)
{
    // Hossein
}

//------------------------------------------------------------------------

bool Organisation::like(std::string ,int)
{
    // Hossein
}

//------------------------------------------------------------------------

bool Organisation::dislike(std::string, int)
{
    // Hossein
}

//------------------------------------------------------------------------

bool Organisation::validate_phone_number(std::string)
{
    // Hossein
}

//------------------------------------------------------------------------

bool Organisation::add_mention(int, std::string, std::string)
{
    // Hossein
}

//------------------------------------------------------------------------

void Organisation::follow(twitterak &, std::string)
{
    // Hossein
}

//------------------------------------------------------------------------

void Organisation::like_mention(int, std::string, int)
{
    // Hossein
}

//================================================================  Save_Organisation_Traces ===============================================================

// save my mention traces
void Organisation::push_myMentions(int, std::string)
{
    // Hossein
}

//------------------------------------------------------------------------
// save my tweet likes traces
void Organisation::push_tweetLikes(int, std::string)
{
    // Hossein
}

//------------------------------------------------------------------------
// delete a like of a tweet
void Organisation::pop_tweetLikes(int, std::string)
{   
    // Hossein
}

//================================================================  Delete_Organisation_Traces ===============================================================

// delete mention traces
void Organisation::del_myMentions(twitterak &)
{
    // Hossein
}

//------------------------------------------------------------------------
// delete hashtag traces
void Organisation::cls_hashtags(twitterak &)
{
    // Hossein
}

//------------------------------------------------------------------------
// delete tweet like traces
void Organisation::del_tweetLikes(twitterak &)
{
    // Hossein
}