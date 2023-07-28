#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctype.h>
#include <iterator>
#include <cctype>
#include "sha256.h"

#include "User_Class.hpp"
#include "Twitterak_Class.hpp"
#include "Mention_class.hpp"

//==================================================================  Get_Functions =================================================================

std::string user::get_name() const                       // returns the name of the user
{
    return Full_Name;
}

//------------------------------------------------------------------------

std::string user::get_username() const                  // returns the username of the user
{
    return Username;
}

//------------------------------------------------------------------------

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

int user::get_last_number()                   // returns the last tweet's number
{
    return last_num;
}

//==================================================================  Set_Functions =================================================================

void user::set_name(std::string name)                                               // sets the name of a user
{
    Full_Name = name;
}

//------------------------------------------------------------------------

void user::set_username(std::string user_name)                                     // sets the username of a user with a validation
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

int user::Validating_Username(std::string user_name)                              // the validation of a user's username
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

void user::set_password(std::string input_pass)                             // sets the password of the user's account
{
    SHA256 sha256;
    Password = sha256(input_pass);
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

std::string user::remove_atsing(std::string str)                                                             // removes @ from the first of the user name
{
    return str.erase(0, 1);
}

//------------------------------------------------------------------------

std::string user::to_lower(std::string str)                                                                 // makes a string lowercase
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    return str;
}

//------------------------------------------------------------------------

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

void user::Tweet(std::string tweet_text)                                                                                                  // make a normal tweet                                              
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

void user::like(std::string user_name, int number)
{
    if(tweets.count(number) == 1)
    {
        tweets[number].tweet_like(user_name);
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
    }
}

//------------------------------------------------------------------------

void user::dislike(std::string user_name, int number)
{
    if(tweets.count(number) == 1)
    {
        tweets[number].tweet_dislike(user_name);
    }
    else
    {
        std::cout << "! There is no tweet with this number.\n";
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

void user::edit_tweet(int tNum, twitterak &app)
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

void user::push_myMentions(int number, std::string uName)
{
    my_mentions[uName].insert(number);
}

//============================================== delete traces =========================================

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