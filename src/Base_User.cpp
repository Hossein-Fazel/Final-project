#include <iostream>

#include "Base_User.hpp"
#include "Twitterak_Class.hpp"
#include "sha256.h"


//============================================== get functions ================================================

std::string Base_User::get_name() const                                                       // returns the name of the user
{
    return Full_Name;
}

//------------------------------------------------------------------------

std::string Base_User::get_username() const                                                    // returns the username of the user
{
    return Username;
}

//------------------------------------------------------------------------

int Base_User::get_followers_num() const                                                     // returns the number of followers
{
    return this->followers.size();
}

//=============================================== set functions ===============================================
void Base_User::set_name(std::string name)                                               // sets the name of a user
{
    Full_Name = name;
}

//------------------------------------------------------------------------

void Base_User::set_username(std::string user_name)                                     // sets the username of a user with a validation
{
    while (1)
    {
        if ((Validating_Username(user_name)) == 0)
        {
            std::cerr << "! Username must have at least 5 characters.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }

        else if ((Validating_Username(user_name)) == -1)
        {
            std::cerr << "! Username must not have characters.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }
            
        else if ((Validating_Username(user_name)) == -2)
        {
            std::cerr << "! Username must not be the commands of the program.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;

            std::cin.ignore();
        }

        else
        {
            if (Username[0] == '@') 
                Username = remove_atsing(user_name);

            Username = to_lower(user_name);

            break;
        }
    }
}

//------------------------------------------------------------------------

void Base_User::set_password(std::string input_pass)                                   // sets the password of the user's account
{
    SHA256 sha256;
    Password = sha256(input_pass);
}

//------------------------------------------------------------------------

void Base_User::follow(twitterak & app, std::string uName)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

// ============================================= general functions ===============================================

void Base_User::add_followers(std::string uName)
{
    this->followers.insert(uName);
}

//------------------------------------------------------------------------

int Base_User::Validating_Username(std::string user_name)                              // the validation of a user's username
{
    if (user_name.length() < 5)
        return 0;

    for (int i = 0; i < user_name.length(); ++i)
    {
        if (!isalnum(user_name[i]))
            return -1;
    }
   
    user_name = to_lower(user_name);

    if ((user_name == "help") or (user_name == "login") or (user_name == "signup") or (user_name == "edit") 
        or (user_name == "exit") or (user_name == "delete account") or (user_name == "like") or (user_name == "profile") 
        or (user_name == "quit")or (user_name == "logout") or (user_name == "delete tweet") or (user_name == "edit tweet"))
    {
        return -2;
    }
        

    return 1;
}

//------------------------------------------------------------------------

std::string Base_User::to_lower(std::string str)                                        // makes a string lowercase
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    return str;
}

//------------------------------------------------------------------------

std::string Base_User::remove_atsing(std::string str)                                   // removes @ from the first of the user name
{
    return str.erase(0, 1);
}

//============================================== Virtuals ===============================================

std::string Base_User::get_biography() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_link() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_birthday() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_phone() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_password() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_header() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::string Base_User::get_country() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

int Base_User::get_last_number() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

int Base_User::get_followers_num() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

int Base_User::get_following_num() const
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_biography(std::string bio)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_link(std::string link)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_birthday(std::string birth)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_phone(std::string phone)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_header(std::string header)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::set_country(std::string country)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::Delete_Account(twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::Show_Profile(twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::Edit(twitterak & app, std::string edit_part, std::string value)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::edit_tweet(int tNum, twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::Tweet(std::string tweet_text, twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::Logout(twitterak & app)
{
    app.is_logedin = false;
    std::cout << "* You have successfully logged out.\n";
}

//------------------------------------------------------------------------

void Base_User::Push_Tweet(tweet tw)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::last_number()
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::print_likers(int number)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

bool Base_User::like(std::string username, int number)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

bool Base_User::dislike(std::string username, int number)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

bool Base_User::validate_phone_number(std::string phone)
{
    std::cout << "! This feature can't be reached for your account.\n";
}       

//------------------------------------------------------------------------

bool Base_User::add_mention(int tweet_number, std::string got_name, std::string got_username)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::push_myMentions(int number, std::string uName)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::push_tweetLikes(int number, std::string uName)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::pop_tweetLikes(int number, std::string uName)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::del_myMentions(twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::cls_hashtags(twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::del_tweetLikes(twitterak & app)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

void Base_User::like_mention(int tNumber, std::string uName, int mNumber)
{
    std::cout << "! This feature can't be reached for your account.\n";
}

//------------------------------------------------------------------------

std::map <int, tweet> Base_User::get_tweets()
{
    std::cout << "! This feature can't be reached for your account.\n";
}
