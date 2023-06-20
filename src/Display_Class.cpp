#include <iostream>

#include "sha256.h"
#include "Display_Class.hpp"
#include "Twitterak_Class.hpp"

//============================================================= Login_Functions ============================================================= 

void display::login(twitterak &app, std::string user_name, std::string password)
{
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//------------------------------------------------------------------------------------------

void display::login(twitterak &app, std::string user_name)
{
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }
    std::string password;

    std::cout << "$ Password : ";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//------------------------------------------------------------------------------------------

void display::login(twitterak &app)
{
    std::string user_name, password;
    std::cout << "$ Username : ";
    std::cin >> user_name;
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }

    std::cout << "$ Password : ";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//============================================================= Sign-up_Function ============================================================= 

void display::signup(twitterak &app)
{
    std::string Full_Name;
    std::string Username;
    std::string Password;
    std::string birthday;

    user u1;

    std::cout << "$ Name : ";
    std::cin >> Full_Name;
    u1.set_name(Full_Name);

    std::cout << "$ Username : @";
    std::cin >> Username;
    u1.set_username(Username);

    while(1)
    {
        if(app.users.count(u1.get_username()) == 1)
        {
            std::cout << "! Your username is invalid.\n";
            std::cout << "$ Username : @";
            std::cin >> Username;
            u1.set_username(Username);
        }

        else
        {
            break;
        }
    }

    std::cout << "Enter your birthday wtih this fromat : 2022/11/15\n";
    std::cout << "$ Birthday : ";
    std::cin >> birthday;
    u1.set_birthday(birthday);

    std::cout << "$ Password : ";
    std::cin >> Password;
    u1.set_password(Password);

    app.users[u1.get_username()] = u1;

    app.is_logedin = true;
    app.logedin_user = u1.get_username();
    
    std::cout << "* Registration was successful.\n";
}

//------------------------------------------------------------------------------------------

void display::signup(twitterak &app, std::string user_name)
{
    std::string Full_Name;
    std::string Password;
    std::string birthday;

    user u1;

    std::cout << "$ Name : ";
    std::cin >> Full_Name;
    u1.set_name(Full_Name);

    u1.set_username(user_name);

    while(1)
    {
        if(app.users.count(u1.get_username()) == 1)
        {
            std::cout << "! Your username is invalid.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;
            u1.set_username(user_name);
        }

        else
        {
            break;
        }
    }

    std::cout << "Enter your birthday wtih this fromat : 2022/11/15\n";
    std::cout << "$ Birthday : ";
    std::cin >> birthday;
    u1.set_birthday(birthday);

    std::cout << "$ Password : ";
    std::cin >> Password;
    u1.set_password(Password);

    app.users[u1.get_username()] = u1;

    app.is_logedin = true;
    app.logedin_user = u1.get_username();
    
    std::cout << "* Registration was successful.\n";
}

//------------------------------------------------------------------------------------------

void display::show_tweet(twitterak app)
{
    if(app.users[app.logedin_user].tweets.size() != 0)
    {
        for(auto our_tweet:app.users[app.logedin_user].tweets)
        {
            
            if(our_tweet.second.get_tweetType() == "normal")
            {
                std::cout << our_tweet.first << " : " << our_tweet.second.get_sefTweet() << std:: endl;
                std::cout << "likes : " << our_tweet.second.get_like_number() << "\t";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }

            else if(our_tweet.second.get_tweetType() == "retweet")
            {
                std::cout << "tweet number : " << our_tweet.first << '\n';
                std::cout << our_tweet.second.get_name() << std::endl << our_tweet.second.get_user_name() <<std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerName() << "\n\t" << our_tweet.second.get_ownerUser_name() << std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerTweet() << '\n';
                std::cout << "likes : " << our_tweet.second.get_like_number() << " ";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }

            else
            {
                std::cout << "tweet number : " << our_tweet.first << '\n';
                std::cout << our_tweet.second.get_name() << std::endl << our_tweet.second.get_user_name() << std::endl << our_tweet.second.get_sefTweet() << '\n';
                std::cout << "\t" << our_tweet.second.get_ownerName() << "\n\t" << our_tweet.second.get_ownerUser_name() << std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerTweet() << '\n';
                std::cout << "likes : " << our_tweet.second.get_like_number() << " ";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }
        }
    }

    else
    {
        std::cout << "! You dont have tweet yet.\n";
    }
}

//------------------------------------------------------------------------------------------

void display::show_tweet(twitterak app, std::string user_name)
{
    if (app.users[user_name].tweets.size() != 0)
    {
        for(auto our_tweet:app.users[user_name].tweets)
        {
            if(our_tweet.second.get_tweetType() == "normal")
            {
                std::cout << our_tweet.first << " : " << our_tweet.second.get_sefTweet() << std:: endl;
                std::cout << "likes : " << our_tweet.second.get_like_number() << "\t";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }

            else if(our_tweet.second.get_tweetType() == "retweet")
            {
                std::cout << "tweet number : " << our_tweet.first << '\n';
                std::cout << our_tweet.second.get_name() << std::endl << our_tweet.second.get_user_name() <<std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerName() << "\n\t" << our_tweet.second.get_ownerUser_name() << std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerTweet() << '\n';
                std::cout << "likes : " << our_tweet.second.get_like_number() << " ";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }

            else
            {
                std::cout << "tweet number : " << our_tweet.first << '\n';
                std::cout << our_tweet.second.get_name() << std::endl << our_tweet.second.get_user_name() << std::endl << our_tweet.second.get_sefTweet() << '\n';
                std::cout << "\t" << our_tweet.second.get_ownerName() << "\n\t" << our_tweet.second.get_ownerUser_name() << std::endl;
                std::cout << "\t" << our_tweet.second.get_ownerTweet() << '\n';
                std::cout << "likes : " << our_tweet.second.get_like_number() << " ";
                our_tweet.second.timeDate.print_time();
                std::cout << " ";
                our_tweet.second.timeDate.print_date();
                std::cout << "\n\n";
            }
        }
    }
    else
    {
        std::cout << "! " << user_name << " does not have tweet yet.\n";
    }
}

//------------------------------------------------------------------------------------------

void display::show_tweet(twitterak app,std::string user_name, int number)
{
    if(app.users[user_name].tweets.count(number))
    {
        if(app.users[user_name].tweets[number].get_tweetType() == "normal")
        {
            std::cout << app.users[user_name].tweets[number].get_number() << ':' << app.users[user_name].tweets[number].get_sefTweet() << std::endl;
            std::cout << "Likes : " << app.users[user_name].tweets[number].get_like_number() << ' ';
            app.users[user_name].tweets[number].timeDate.print_time();
            std::cout << ' ';
            app.users[user_name].tweets[number].timeDate.print_date();
            std::cout << "\n\n";
        }

        else if(app.users[user_name].tweets[number].get_tweetType() == "retweet")
        {
            std::cout << "tweet number : " << app.users[user_name].tweets[number].get_number() << '\n';
            std::cout << app.users[user_name].tweets[number].get_name() << std::endl << app.users[user_name].tweets[number].get_user_name() <<std::endl;
            std::cout << "\t" << app.users[user_name].tweets[number].get_ownerName() << "\n\t" << app.users[user_name].tweets[number].get_ownerUser_name() << std::endl;
            std::cout << "\t" << app.users[user_name].tweets[number].get_ownerTweet() << '\n';
            std::cout << "likes : " << app.users[user_name].tweets[number].get_like_number() << " ";
            app.users[user_name].tweets[number].timeDate.print_time();
            std::cout << " ";
            app.users[user_name].tweets[number].timeDate.print_date();
            std::cout << "\n\n";
        }

        else
        {
            std::cout << "tweet number : " << app.users[user_name].tweets[number].get_number() << '\n';
            std::cout << app.users[user_name].tweets[number].get_name() << std::endl << app.users[user_name].tweets[number].get_user_name() << std::endl << app.users[user_name].tweets[number].get_sefTweet() << '\n';
            std::cout << "\t" << app.users[user_name].tweets[number].get_ownerName() << "\n\t" << app.users[user_name].tweets[number].get_ownerUser_name() << std::endl;
            std::cout << "\t" << app.users[user_name].tweets[number].get_ownerTweet() << '\n';
            std::cout << "likes : " << app.users[user_name].tweets[number].get_like_number() << " ";
            app.users[user_name].tweets[number].timeDate.print_time();
            std::cout << " ";
            app.users[user_name].tweets[number].timeDate.print_date();
            std::cout << "\n\n";
        }
    }
}

//============================================================= Help_Function ============================================================= 

void display::help(twitterak &app)
{
    if(app.is_logedin == false)
    {
        std:: cout << "login to your acount\n";
        std::cout << "~ login your_user_name your_password\n~ login your_user_name\n~ login \n\n";

        std::cout << "create a new account\n";
        std::cout << "~ signup your_user_name\n~ signup \n\n";

        std::cout << "close the app\n";
        std::cout << "~ exit\n~ quit\n~ q\n\n";

    }

    else
    {
        std::cout << "show your/another person account\n";
        std::cout << "show your profile :\n";
        std::cout << "~ profile\n";
        std::cout << "~ me\n";
        std::cout << "show another person profile :\n";
        std::cout << "~ profile @user_name\n\n";

        std::cout << "to edit your profile\n";
        std::cout << "~ edit profile edit_part value\n";
        std::cout << "~ if your value is an string, put it between "" \n\n";

        std::cout << "logout from your account\n";
        std::cout << "~ logout\n\n";

        std::cout << "to delete your account\n";
        std::cout << "~ delete account\n\n";

        std::cout << "create a new tweet\n";
        std::cout << "~ tweet \n";
        std::cout << "~ tweet your_tweet_text\n\n";

        std::cout << "retweet a tweet\n";
        std::cout << "~ retweet user_name number_of_tweet\n\n";

        std::cout << "quotetweet\n";
        std::cout << "~ qoutetweet user_name number_of_tweet\n\n";

        std::cout << "like a tweet\n";
        std::cout << "~ like user_name number_of_tweet\n\n";

        std::cout << "dislike a tweet\n";
        std::cout << "~ dislike user_name number_of_tweet\n\n";
    
        std::cout << "show your/another person tweets\n";
        std::cout << "@me (show your tweets)\n";
        std::cout << "@your_user_name (show your tweets)\n";
        std::cout << "@user_name (show another person tweets)\n\n";

        std::cout << "show specific tweet \n";
        std::cout << "~ @user_name:number_of_tweet\n\n";
        std::cout << "~ @me:number_of_tweet\n\n";

        std::cout << "edit your tweet\n";
        std::cout << "~ edit tweet number_of_tweet\n\n";

        std::cout << "edit your tweet\n";
        std::cout << "edit tweet number_of_tweet\n\n";

        std::cout << "delete your tweet\n";
        std::cout << "delete tweet number_of_tweet\n\n";

        std::cout << "like a tweet\n";
        std::cout << "~ Like user_name:number_of_tweet\n\n";

        std::cout << "dislike a tweet\n";
        std::cout << "~ disike user_name:number_of_tweet\n\n";

        std::cout << "show likes of a tweet\n";
        std::cout << "~ @user_name:number_of_tweet:like\n\n";
    }
}