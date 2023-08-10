#include <iostream>
#include <unistd.h>
#include <stdio.h>

#include "sha256.h"
#include "Display_Class.hpp"
#include "Twitterak_Class.hpp"

void display::show_normal(tweet tw)
{
    std::cout << tw.get_number() << " : " << tw.get_sefTweet() << std:: endl;
    std::cout << "likes : " << tw.get_like_number() << "\t";
    std::cout << "mentions : " << tw.get_mentions_number() << "  ";
    std::cout << tw.get_time();
    std::cout << " ";
    std::cout << tw.get_date();
    std::cout << "\n\n";
}

void display::show_qoute(tweet tw)
{
    std::cout << "tweet number : " << tw.get_number() << '\n';
    std::cout << "name         : " << tw.get_name() << std::endl ;
    std::cout << "username     : " << tw.get_user_name() << std::endl ;
    std::cout << "tweet text   :" << tw.get_sefTweet() << "\n\n";

    std::cout << "\towner name     : " << tw.get_ownerName() << "\n" ;
    std::cout << "\towner username : " << tw.get_ownerUser_name() << std::endl;
    std::cout << "\towner tweet    : " << tw.get_ownerTweet() << "\n\n";

    std::cout << "likes : " << tw.get_like_number() << " ";
    std::cout << "mentions : " << tw.get_mentions_number() << "  ";
    std::cout << tw.get_time();
    std::cout << " ";
    std::cout << tw.get_date();
    std::cout << "\n\n";
}

void display::show_re(tweet tw)
{
    std::cout << "tweet number : " << tw.get_number() << '\n';
    std::cout << "name         : " << tw.get_name() << std::endl ;
    std::cout << "username     : " << tw.get_user_name() <<"\n\n";

    std::cout << "\towner name     : " << tw.get_ownerName() << "\n" ;
    std::cout << "\towner username : " << tw.get_ownerUser_name() << std::endl;
    std::cout << "\towner tweet    : " << tw.get_ownerTweet() << "\n\n";

    std::cout << "likes : " << tw.get_like_number() << " ";
    std::cout << "mentions : " << tw.get_mentions_number() << "  ";
    std::cout << tw.get_time();
    std::cout << " ";
    std::cout << tw.get_date();
    std::cout << "\n\n";
}

//============================================================= Login_Functions ============================================================= 

void display::login(twitterak &app, std::string user_name, std::string password)
{
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }

    if (app.users.count(user_name) == 1)                                           // login to personal user
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.users[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.org_user.count(user_name) == 1)                                      // login to organisation user
    {
        if (app.org_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.org_user[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.ans_user.count(user_name) == 1)                                          // login to anonymous user
    {
        if (app.ans_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.ans_user[app.logedin_user]);
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

    password = getpass("$ Password : ");

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.users[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.org_user.count(user_name) == 1)                                      // login to organisation user
    {
        if (app.org_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.org_user[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.ans_user.count(user_name) == 1)                                          // login to anonymous user
    {
        if (app.ans_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.ans_user[app.logedin_user]);
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

    password = getpass("$ Password : ");

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.users[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.org_user.count(user_name) == 1)                                      // login to organisation user
    {
        if (app.org_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.org_user[app.logedin_user]);
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }

    else if (app.ans_user.count(user_name) == 1)                                          // login to anonymous user
    {
        if (app.ans_user[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            app.li_user = &(app.ans_user[app.logedin_user]);
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
    std::string st;
    std::cout << " 1_ Personal\n";
    std::cout << " 2_ Organisation\n";
    std::cout << " 3_ Anonymous\n";
    std::cout << "? Select the type of user : ";

    std::cin >> st;
    st = app.lower(st);

    if(st == "1" or st == "personal")
    {
        std::string Full_Name;
        std::string Username;
        std::string Pass;
        std::string birthday;
        std::string phone_number;

        user u1;

        std::cout << "$ Name : ";
        std::cin >> Full_Name;
        u1.set_name(Full_Name);

        std::cout << "$ Username : @";
        std::cin >> Username;
        u1.set_username(Username);

        while(1)
        {
            if(app.users.count(u1.get_username()) == 1 or app.org_user.count(u1.get_username()) == 1 or app.ans_user.count(u1.get_username()) == 1)
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

        std::cout << "$ Phone number : ";
        std::cin >> phone_number;
        u1.set_phone(phone_number);

        std::cout << "Enter your birthday wtih this fromat : 2022/11/15\n";
        std::cout << "$ Birthday : ";
        std::cin >> birthday;
        u1.set_birthday(birthday);

        Pass = getpass("$ Password : ");
        while (Pass.empty())
        {
            std::cout << "! please enter a password\n";
            Pass = getpass("$ Password : ");
        }

        u1.set_password(Pass);

        app.users[u1.get_username()] = u1;
        app.is_logedin = true;
        app.logedin_user = u1.get_username();
        app.li_user = &(app.users[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else if(st == "2" or st == "organisation")
    {
        std::string Full_Name;
        std::string Username;
        std::string Pass;
        std::string phone_number;
        std::string managerUser;

        Organisation org1;

        std::cout << "$ Name : ";
        std::cin >> Full_Name;
        org1.set_name(Full_Name);

        std::cout << "$ Username : @";
        std::cin >> Username;
        org1.set_username(Username);

        while(1)
        {
            if(app.users.count(org1.get_username()) == 1 or app.org_user.count(org1.get_username()) == 1 or app.ans_user.count(org1.get_username()) == 1)
            {
                std::cout << "! Your username is invalid.\n";
                std::cout << "$ Username : @";
                std::cin >> Username;
                org1.set_username(Username);
            }

            else
            {
                break;
            }
        }

        std::cout << "$ Phone number : ";
        std::cin >> phone_number;
        org1.set_phone(phone_number);

        std::cout << "$ Manager username : ";
        std::cin >> managerUser;
        org1.set_manager_username(app, managerUser);



        Pass = getpass("$ Password : ");
        while (Pass.empty())
        {
            std::cout << "! please enter a password\n";
            Pass = getpass("$ Password : ");
        }
        org1.set_password(Pass);

        app.org_user[org1.get_username()] = org1;
        app.is_logedin = true;
        app.logedin_user = org1.get_username();
        app.li_user = &(app.org_user[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else if(st == "3" or st == "anonymous")
    {
        std::string Username;
        std::string Pass;

        Anonymous ans1;

        std::cout << "$ Username : @";
        std::cin >> Username;
        ans1.set_username(Username);

        while(1)
        {
            if(app.users.count(ans1.get_username()) == 1 or app.org_user.count(ans1.get_username()) == 1 or app.ans_user.count(ans1.get_username()) == 1)
            {
                std::cout << "! Your username is invalid.\n";
                std::cout << "$ Username : @";
                std::cin >> Username;
                ans1.set_username(Username);
            }

            else
            {
                break;
            }
        }

        Pass = getpass("$ Password : ");
        ans1.set_password(Pass);

        app.ans_user[ans1.get_username()] = ans1;
        app.is_logedin = true;
        app.logedin_user = ans1.get_username();
        app.li_user = &(app.ans_user[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else
    {
        std::cout << "! Your selected type is undefined.\n";
    }

}

//------------------------------------------------------------------------------------------

void display::signup(twitterak &app, std::string user_name)
{
    std::string st;
    std::cout << " 1_ Personal User\n";
    std::cout << " 2_ Organisation User\n";
    std::cout << " 3_ Anonymous User\n";
    std::cout << "? Select the type of user : ";

    std::cin >> st;
    st = app.lower(st);

    if(st == "1" or st == "personal")
    {
        std::string Full_Name;
        std::string Pass;
        std::string birthday;
        std::string phone_number;

        user u1;

        std::cout << "$ Name : ";
        std::cin >> Full_Name;
        u1.set_name(Full_Name);

        u1.set_username(user_name);

        while(1)
        {
            if(app.users.count(u1.get_username()) == 1 or app.org_user.count(u1.get_username()) == 1 or app.ans_user.count(u1.get_username()) == 1)
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

        std::cout << "$ Phone number : ";
        std::cin >> phone_number;
        u1.set_phone(phone_number);

        std::cout << "Enter your birthday wtih this fromat : 2022/11/15\n";
        std::cout << "$ Birthday : ";
        std::cin >> birthday;
        u1.set_birthday(birthday);

        Pass = getpass("$ Password : ");
        while (Pass.empty())
        {
            std::cout << "! please enter a password\n";
            Pass = getpass("$ Password : ");
        }

        u1.set_password(Pass);

        app.users[u1.get_username()] = u1;
        app.is_logedin = true;
        app.logedin_user = u1.get_username();
        app.li_user = &(app.users[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else if(st == "2" or st == "organisation")
    {
        std::string Full_Name;
        std::string Pass;
        std::string phone_number;
        std::string managerUser;

        Organisation org1;

        std::cout << "$ Name : ";
        std::cin >> Full_Name;
        org1.set_name(Full_Name);

        org1.set_username(user_name);

        while(1)
        {
            if(app.users.count(org1.get_username()) == 1 or app.org_user.count(org1.get_username()) == 1 or app.ans_user.count(org1.get_username()) == 1)
            {
                std::cout << "! Your username is invalid.\n";
                std::cout << "$ Username : @";
                std::cin >> user_name;
                org1.set_username(user_name);
            }

            else
            {
                break;
            }
        }

        std::cout << "$ Phone number : ";
        std::cin >> phone_number;
        org1.set_phone(phone_number);

        std::cout << "$ Manager username : ";
        std::cin >> managerUser;
        org1.set_manager_username(app, managerUser);

        Pass = getpass("$ Password : ");
        while (Pass.empty())
        {
            std::cout << "! please enter a password\n";
            Pass = getpass("$ Password : ");
        }
        org1.set_password(Pass);

        app.org_user[org1.get_username()] = org1;
        app.is_logedin = true;
        app.logedin_user = org1.get_username();
        app.li_user = &(app.org_user[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else if(st == "3" or st == "anonymous")
    {
        std::string Pass;

        Anonymous ans1;
        ans1.set_username(user_name);

        while(1)
        {
            if(app.users.count(ans1.get_username()) == 1 or app.org_user.count(ans1.get_username()) == 1 or app.ans_user.count(ans1.get_username()) == 1)
            {
                std::cout << "! Your username is invalid.\n";
                std::cout << "$ Username : @";
                std::cin >> user_name;
                ans1.set_username(user_name);
            }

            else
            {
                break;
            }
        }

        Pass = getpass("$ Password : ");
        ans1.set_password(Pass);

        app.ans_user[ans1.get_username()] = ans1;
        app.is_logedin = true;
        app.logedin_user = ans1.get_username();
        app.li_user = &(app.ans_user[app.logedin_user]);

        std::cout << "* Registration was successful.\n";
    }

    else
    {
        std::cout << "! Your selected type is undefined.\n";
    }

}

//------------------------------------------------------------------------------------------

void display::show_tweet(twitterak app, std::string user_name)
{
    if(app.users.count(user_name) == 1)
    {
        if (app.users[user_name].tweets.size() != 0)
        {
            for(auto our_tweet:app.users[user_name].tweets)
            {
                if(our_tweet.second.get_tweetType() == "normal")
                {
                    show_normal(our_tweet.second);
                }

                else if(our_tweet.second.get_tweetType() == "retweet")
                {
                    show_re(our_tweet.second);
                }

                else
                {
                    show_qoute(our_tweet.second);
                }
            }
        }
        else
        {
            std::cout << "! " << user_name << " does not have tweet yet.\n";
        }
    }

    else if(app.org_user.count(user_name) == 1)
    {
        if (app.org_user[user_name].tweets.size() != 0)
        {
            for(auto our_tweet:app.org_user[user_name].tweets)
            {
                if(our_tweet.second.get_tweetType() == "normal")
                {
                    show_normal(our_tweet.second);
                }

                else if(our_tweet.second.get_tweetType() == "retweet")
                {
                    show_re(our_tweet.second);
                }

                else
                {
                    show_qoute(our_tweet.second);
                }
            }
        }
        else
        {
            std::cout << "! " << user_name << " does not have tweet yet.\n";
        }
    }

    else
    {
        std::cout << "! There is no user with this username.\n";
    }
}

//------------------------------------------------------------------------------------------

void display::show_tweet(twitterak app,std::string user_name, int tNum)
{
    if(app.users.count(user_name) == 1)
    {
        if(app.users[user_name].tweets.count(tNum) == 1)
        {
            if(app.users[user_name].tweets[tNum].get_tweetType() == "normal")
            {
                show_normal(app.users[user_name].tweets[tNum]);
            }

            else if(app.users[user_name].tweets[tNum].get_tweetType() == "retweet")
            {
                show_re(app.users[user_name].tweets[tNum]);
            }

            else
            {
                show_qoute(app.users[user_name].tweets[tNum]);
            }
        }

        else
        {
            std::cout << "! There is no tweet with this number.\n";
        }
    }

    else if(app.org_user.count(user_name) == 1)
    {
        if(app.org_user[user_name].tweets.count(tNum))
        {
            if(app.org_user[user_name].tweets[tNum].get_tweetType() == "normal")
            {
                show_normal(app.org_user[user_name].tweets[tNum]);
            }

            else if(app.users[user_name].tweets[tNum].get_tweetType() == "retweet")
            {
               show_re(app.org_user[user_name].tweets[tNum]);
            }

            else
            {
                show_qoute(app.org_user[user_name].tweets[tNum]);
            }
        }

        else
        {
            std::cout << "! There is no tweet with this number.\n";
        }
    }

    else
    {
        std::cout << "! There is no user with this username.\n";
    }
}

//============================================================= Help_Function ============================================================= 

void display::help(twitterak &app)
{
    if(app.is_logedin == false)
    {
        std::cout << "\n";
        std::cout << "--------------------------------------- Help -----------------------------------------\n\n";
        std::cout << "login to your acount\n";
        std::cout << "~ login your_user_name your_password\n~ login your_user_name\n~ login \n\n";

        std::cout << "create a new account\n";
        std::cout << "~ signup your_user_name\n~ signup \n\n";

        std::cout << "close the app\n";
        std::cout << "~ exit (-y exit without confirm)\n~ quit (-y exit without confirm)\n~ q    (-y exit without confirm)\n\n";

        std::cout << "clear the screen\n";
        std::cout << "~ cls\n~ clear\n\n";

        std::cout << "-------------------------------------------------------------------------------------\n";
    }

    else
    {
        std::cout << "\n";
        std::cout << "--------------------------------------- Help -----------------------------------------\n\n";

        std::cout << "show your/another person account\n";
        std::cout << "~ profile\n";
        std::cout << "~ me\n";

        std::cout << "show another person profile :\n";
        std::cout << "~ profile @user_name\n\n";

        std::cout << "to edit your profile\n";
        std::cout << "~ edit profile edit_part value\n";
        std::cout << "! if your value is an string, put it between \"\" \n\n";

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
        std::cout << "~ @me (show your tweets)\n";
        std::cout << "~ @your_user_name (show your tweets)\n";
        std::cout << "~ @user_name (show another person tweets)\n\n";

        std::cout << "show specific tweet \n";
        std::cout << "~ @user_name:number_of_tweet\n";
        std::cout << "~ @me:number_of_tweet\n\n";

        std::cout << "edit your tweet\n";
        std::cout << "~ edit tweet number_of_tweet\n\n";

        std::cout << "delete your tweet\n";
        std::cout << "~ delete tweet number_of_tweet\n\n";

        std::cout << "like a tweet\n";
        std::cout << "~ Like user_name:number_of_tweet\n\n";

        std::cout << "dislike a tweet\n";
        std::cout << "~ disike user_name:number_of_tweet\n\n";

        std::cout << "show likes of a tweet\n";
        std::cout << "~ @user_name:number_of_tweet:like\n\n";

        std::cout << "add mention to a tweet\n";
        std::cout << "~ mention username tweetNumber\n";
        std::cout << "~ mention @username tweetNumber\n\n";

        std::cout << "like a mention\n";
        std::cout << "~ like mention @username:tweet_number mention_number\n";
        std::cout << "~ like mention username:tweet_number mention_number\n\n";

        std::cout << "show mentions of a tweet\n";
        std::cout << "~ show mention username tweetNumber\n";
        std::cout << "~ show mention @username tweetNumber\n\n";

        std::cout << "follow a user\n";
        std::cout << "~ follow @username.\n";
        std::cout << "~ follow username.\n";

        std::cout << "clear the screen\n";
        std::cout << "~ cls\n~ clear\n\n";

        std::cout << "close the app\n";
        std::cout << "~ exit (-y exit without confirm)\n~ quit (-y exit without confirm)\n~ q    (-y exit without confirm)\n\n";

        std::cout << "------------------------------------------------------------------------------------\n";
    }
}

//============================================================= Show_Mention Function ============================================================= 

void display::show_mentions(twitterak app, std::string user_name, int tweet_number)
{
    if(app.users.count(user_name) == 1)
    {
        if(app.users[user_name].tweets.count(tweet_number) == 1)
        {
            std::cout << "username     : " << app.users[user_name].tweets[tweet_number].get_user_name() << std::endl;
            std::cout << "tweet number : " << app.users[user_name].tweets[tweet_number].get_number() << std::endl;
            std::cout << "tweet text   : " << app.users[user_name].tweets[tweet_number].get_sefTweet() << std::endl << std::endl;

            for (auto user :app.users[user_name].tweets[tweet_number].tweet_mentions)
            {
                for(auto ment:user.second)
                {
                    std::cout << "  mention no : " << ment.get_number() << std::endl;
                    std::cout << "  name       : " << ment.get_name() << std::endl;
                    std::cout << "  username   : " << ment.get_username() << std::endl;
                    std::cout << "  text       : " << ment.get_mention() << std::endl;
                    std::cout << "  likes      : " << ment.get_likes_number() << std::endl << std::endl;
                }
            }
        }
        else
        {
            std::cout << "! There is no tweet with this number.\n";
        }
    }
    
    else if(app.org_user.count(user_name) == 1)
    {
        if(app.org_user[user_name].tweets.count(tweet_number) == 1)
        {
            std::cout << "username     : " << app.org_user[user_name].tweets[tweet_number].get_user_name() << std::endl;
            std::cout << "tweet number : " << app.org_user[user_name].tweets[tweet_number].get_number() << std::endl;
            std::cout << "tweet text   : " << app.org_user[user_name].tweets[tweet_number].get_sefTweet() << std::endl << std::endl;

            for (auto user :app.org_user[user_name].tweets[tweet_number].tweet_mentions)
            {
                for(auto ment:user.second)
                {
                    std::cout << "  mention no : " << ment.get_number() << std::endl;
                    std::cout << "  name       : " << ment.get_name() << std::endl;
                    std::cout << "  username   : " << ment.get_username() << std::endl;
                    std::cout << "  text       : " << ment.get_mention() << std::endl;
                    std::cout << "  likes      : " << ment.get_likes_number() << std::endl << std::endl;
                }
            }
        }
        else
        {
            std::cout << "! There is no tweet with this number.\n";
        }
    }

    else
    {
        std::cout << "! There is no user with this username.\n";
    }
}