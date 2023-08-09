#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <fstream>

#include "Twitterak_Class.hpp"
#include "Display_Class.hpp"
#include "User_Class.hpp"

twitterak::twitterak()
{
    read_users();
}

void twitterak::put_users()
{
    std::ofstream wuser;
    wuser.open("users.txt");

    for(auto i : users)
    {
        wuser << "type:user" << std::endl;
        wuser << "name:" << i.second.get_name() << std::endl;
        wuser << "username:" << i.second.get_username() << std::endl;
        wuser << "bio:" << i.second.get_biography() << std::endl;
        wuser << "link:" << i.second.get_link() << std::endl;
        wuser << "phone:" << i.second.get_phone() << std::endl;
        wuser << "header:" << i.second.get_header() << std::endl;
        wuser << "country:" << i.second.get_country() << std::endl;
        wuser << "birthday:" << i.second.get_birthday() << std::endl;
        wuser << "password:" << i.second.get_password() << std::endl;
        wuser << "last_num:" << i.second.get_last_number() << std::endl;

        wuser << "followers:";
        for(auto j : i.second.get_followers())
        {
            wuser << j << ',';
        }
        wuser << std::endl;

        wuser << "followings:";
        for(auto j : i.second.get_following())
        {
            wuser << j << ',';
        }
        wuser << std::endl;

        wuser << "passwords:";
        for(auto j : i.second.get_passwords())
        {
            wuser << j << ',';
        }
        wuser << std::endl;


        wuser << "my_mentions:" << std::endl;
        if(i.second.get_mention_trs().size() != 0)
        {
            for(auto j : i.second.get_mention_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }

        wuser << "tweet_likes:" << std::endl;
        
        if(i.second.get_tweetlike_trs().size() != 0)
        {
            for(auto j : i.second.get_tweetlike_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }

        wuser << "***" << std::endl;
    }

    for (auto i : org_user)
    {
        wuser << "type:org" << std::endl;
        wuser << "name:" << i.second.get_name() << std::endl;
        wuser << "username:" << i.second.get_username() << std::endl;
        wuser << "bio:" << i.second.get_biography() << std::endl;
        wuser << "link:" << i.second.get_link() << std::endl;
        wuser << "phone:" << i.second.get_phone() << std::endl;
        wuser << "header:" << i.second.get_header() << std::endl;
        wuser << "country:" << i.second.get_country() << std::endl;
        wuser << "password:" << i.second.get_password() << std::endl;
        wuser << "last_num:" << i.second.get_last_number() << std::endl;
        wuser << "manager:" << i.second.get_manager_username() << std::endl;

        wuser << "followers:";
        for(auto j : i.second.get_followers())
        {
            wuser << j << ',';
        }
        wuser << std::endl;

        wuser << "followings:";
        for(auto j : i.second.get_following())
        {
            wuser << j << ',';
        }
        wuser << std::endl;

        wuser << "passwords:";
        for(auto j : i.second.get_passwords())
        {
            wuser << j << " ";
        }
        wuser << std::endl;


        wuser << "my_mentions:" << std::endl;
        if(i.second.get_mention_trs().size() != 0)
        {
            for(auto j : i.second.get_mention_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }

        wuser << "tweet_likes:" << std::endl;
        if(i.second.get_tweetlike_trs().size() != 0)
        {
            for(auto j : i.second.get_tweetlike_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }

        wuser << "***" << std::endl;
    }

    for (auto i : ans_user)
    {
        wuser << "type:ans" << std::endl;
        wuser << "username:" << i.second.get_username() << std::endl;
        wuser << "password:" << i.second.get_password() << std::endl;

        wuser << "followings:";
        for(auto j : i.second.get_following())
        {
            wuser << j << " ";
        }
        wuser << std::endl;

        wuser << "passwords:";
        for(auto j : i.second.get_passwords())
        {
            wuser << j << " ";
        }
        wuser << std::endl;     

        wuser << "my_mentions:" << std::endl;
        if(i.second.get_mention_trs().size() != 0)
        {
            for(auto j : i.second.get_mention_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }

        wuser << "tweet_likes:" << std::endl;
        if(i.second.get_tweetlike_trs().size() != 0)
        {
            for(auto j : i.second.get_tweetlike_trs())
            {
                wuser << j.first << ':';
                for(auto num : j.second)
                {
                    wuser << num << ',';
                }
                wuser << std::endl;
            }
        }
        else
        {
            wuser << std::endl;
        }
        
        wuser << "***" << std::endl;
    }

    wuser.close();
}


void twitterak::read_users()
{
    std::cout << "reading ...\n";
    std::ifstream ruser;
    ruser.open("users.txt");

    if(ruser)
    {
        std::cout << "opened\n";
        std::string value;

        while (!ruser.eof())
        {
            ruser.ignore(1000,':');
            getline(ruser, value);

            if(value == "user")
            {
                user u1;

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_name(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_username(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_biography(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_link(value);
                }


                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_phone(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_header(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_country(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_birthday(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_pass_wHash(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    u1.set_lastNum(std::stoi(value));
                }

                users[u1.get_username()] = u1;
            }

            else if(value == "org")
            {
                Organisation org1;

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_name(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_username(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_biography(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_link(value);
                }


                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_phone(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_header(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_country(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_pass_wHash(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_lastNum(std::stoi(value));
                }

                ruser.ignore(1000, ':');
                getline(ruser, value, '\n');
                if(!value.empty())
                {
                    org1.set_manager_username(*this,value);
                }

                org_user[org1.get_username()] = org1;
            }

            else if(value == "ans")
            {
                Anonymous ans1;

                ruser.ignore(1000, ':');
                getline(ruser, value);
                if(!value.empty())
                {
                    ans1.set_username(value);
                }

                ruser.ignore(1000, ':');
                getline(ruser, value);
                if(!value.empty())
                {
                    ans1.set_pass_wHash(value);
                }

                ans_user[ans1.get_username()] = ans1;
            }
        }
    }
    ruser.close();
}

//------------------------------------------------------------------------------------------

bool twitterak::get_userName_number(std:: string txt, std::string &username, int &number)
{
    bool flag = false;
    std::string num;

    for(auto i: txt)
    {
        if(!flag)
        {
            if(i != ':')
            {
                username += i;
            }
            else
            {
                flag = true;
            }
        }
        else
        {
            num += i;
        }
    }

    if(!num.empty())
    {
        number = std::stoi(num);
        return true;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------------------

void twitterak::del_atsign(std::string &str)
{
    if(str[0] == '@')
    {
        str.erase(0, 1);
    }
}

//------------------------------------------------------------------------------------------

void twitterak::serch_hashtag(std::string hash)
{

    if(hash[0] == '#')
    {
        hash.erase(0,1);
    }
    std::string hashtag = lower(hash);

    if(Hashtags.count(hashtag) == 1)
    {
        if(Hashtags[hashtag].size() != 0)
        {
            for(auto i : Hashtags[hashtag])
            {
                std::cout << "tweet number  : " << i.get_number() << std::endl;
                std::cout << "name          : " << i.get_name() << std::endl;
                std::cout << "username      : " << i.get_user_name() << std::endl;
                std::cout << "tweet text    : " << i.get_sefTweet() << "\n\n";
            }
        }
        else
        {
            std::cout << "! There is no tweet with this hashtag.\n";
            Hashtags.erase(hashtag);
        }
    }
    else
    {
        std::cout << "! this hashtag is not exist.\n";
    }
}

//------------------------------------------------------------------------------------------

bool twitterak::is_in(std::string str, char ch)
{
    int strSize = str.size();
    for(int i = 0; i < strSize; i++)
    {
        if(str[i] == ch)
        {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------------------

bool twitterak::is_in(std::string str, std::string ch)
{
    int strSize = str.size();
    for(int i = 0; i < strSize; i++)
    {
        if(str.substr(i,i + (ch.size())) == ch)
        {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------------------

void twitterak::tokenize(std::string command)
{
    commands.clear();
    int counter = 0;
    int cSize = command.size();

    std::string cm="";
    for(int i = 0; i < cSize; i++)
    {
        if(int(command[i]) != 32)
        {
            cm += command[i];
        }
        else
        {
            if(cm.empty())
            {
                continue;
            }
            else
            {
                commands.push_back(cm);
                cm = "";
                counter++;
            }
        }
        
        if(commands.size() != 0)
        {
            if(commands[0] == "edit" and counter == 3)
            {
                cm = "";
                for(int j = i+1; j < cSize ; j++)
                {
                    cm += command[j];
                }
                break;
            }

            else if(commands[0] == "tweet")
            {
                cm = "";
                for(int j = i+1; j < cSize ; j++)
                {
                    cm += command[j];
                }
                break;
            }
        }
    }
    if(!cm.empty())
    {
        commands.push_back(cm);
    }
}

//------------------------------------------------------------------------------------------

std::string twitterak::lower(std::string command)
{
    for(int i = 0; i < command.size(); i++)
    {
        command[i] = std::tolower(command[i]);
    }

    return command;
}

//------------------------------------------------------------------------------------------

void twitterak::run()
{
    #if OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "\t\t\t--- Welcome to Twitterak ---\n\n";
    std::cout << "If you need help, enter help command :)\n";
    std::cout << "~ help\n";
    std::cout << "~ twitterak --help\n";


    std:: cout << "> ";

    display d1;

    std:: string command;
    
    getline(std::cin , command);
    command = lower(command);
    tokenize(command);

    while (1)
    {
        if(!command.empty())
        {
            int cSize = commands.size();
            if(commands[0] == "login" and (cSize == 1 or cSize == 2 or cSize == 3))
            {
                if(is_logedin == true)
                {
                    std::cout << "! You are already loged in.\n";
                }
                else
                {
                    if(cSize == 1)
                    {
                        d1.login(*this);
                        std::cin.ignore();
                    }
                    else if(cSize == 2)
                    {
                        del_atsign(commands[1]);
                        d1.login(*this, commands[1]);
                    }
                    else if (cSize == 3)
                    {
                        del_atsign(commands[1]);
                        d1.login(*this, commands[1], commands[2]);
                    }
                }
            }

            else if(commands[0] == "signup" and (cSize == 1 or cSize == 2))
            {
                if(is_logedin)
                {
                    std::cout << "! You must logout first from your account.\n";
                }
                else
                {
                    if(commands.size() == 2)
                    {
                        d1.signup(*this, commands[1]);
                    }
                    else
                    {
                        d1.signup(*this);
                    }
                    std::cin.ignore();
                }
            }

            else if(commands[0] == "delete" and (cSize == 2 or cSize == 3))
            {
                if(is_logedin)
                {
                    if(commands[1] == "account")
                    {
                        li_user->Delete_Account(*this);
                    }

                    else if(commands[1] == "tweet")
                    {
                        li_user->delete_tweet(std::stoi(commands[2]), *this);
                        // std::cin.ignore();
                    }
                }
                else
                {
                    std:: cout << "! You must login first to your account.\n";
                }
                std::cin.ignore();
            }

            else if(commands[0] == "profile" and cSize == 2)
            {
                del_atsign(commands[1]);

                if(users.count(commands[1]) == 1)
                {
                    users[commands[1]].Show_Profile(*this);
                }

                else if(org_user.count(commands[1]) == 1)
                {
                    org_user[commands[1]].Show_Profile(*this);
                }
                
                else if(ans_user.count(commands[1]) == 1)
                {
                    ans_user[commands[1]].Show_Profile(*this);
                }
                
                else
                {
                    std::cout << "! The username is not recognized.\n";
                }
                
            }

            else if(commands[0] == "profile" or commands[0] == "me")
            {
                if(is_logedin)
                {
                    li_user->Show_Profile(*this);
                }

                else
                {
                    std:: cout << "! You must login first to your account.\n";
                }
            }

            else if(commands[0] == "edit" and (cSize == 4 or cSize == 3))
            {
                if(is_logedin)
                {
                    if(commands[1] == "profile" and !commands[3].empty())
                    {
                        if(commands[2] != "phone_number" and commands[2] != "birthday")
                        {
                            commands[3] = commands[3].erase(0,1);
                            commands[3] = commands[3].erase(commands[3].size()-1,1);
                        }
                        li_user->Edit(*this, commands[2], commands[3]);
                    }
                    else if( commands[1] == "tweet")
                    {
                        if(is_logedin)
                        {
                            li_user->edit_tweet(stoi(commands[2]), *this);
                        }
                        else
                        {
                            std:: cout << "! You must login first to your account\n";
                        }
                    }
                    else
                    {
                        std::cout << "! undefined command.\n";
                    }
                }
                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "logout" and cSize == 1)
            {
                if(is_logedin)
                {
                    li_user->Logout(*this);
                }
                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if ((commands[0] == "exit" or commands[0] == "quit" or commands[0] == "q") and cSize == 1)
            {
                char ch;
                std::cout << "? Are you sure ? (y/n) : ";
                std::cin >> ch;
                if(ch == 'y' or ch == 'Y')
                {
                    put_users();
                    std::cout << "Good Bye\n";
                    exit(0);
                }
            }

            else if ((commands[0] == "twitterak" and commands[1] == "--help") or commands[0] == "help")
            {
                d1.help(*this);
            }

            else if(commands[0] == "tweet" and (cSize == 1 or cSize == 2))
            {
                if(is_logedin)
                {
                    if(commands.size() == 2)
                    {
                        li_user->Tweet(commands[1], *this);
                    }
                    else if(commands.size() == 1)
                    {
                        li_user->Tweet("", *this);
                    }
                }

                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "retweet" and cSize == 3)
            {
                if(is_logedin)
                {
                    if(ans_user.count(logedin_user) == 1)
                    {
                        std::cout << "! You can not retweet.\n";
                    }
                    else
                    {
                        del_atsign(commands[1]);

                        if( users[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                        {
                            users[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "retweet");
                            std::cout << "* Retweeted.\n";
                        }
                        
                        else if( org_user[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                        {
                            org_user[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "retweet");
                            std::cout << "* Retweeted.\n";
                        }

                        else
                        {
                            std::cout << "! There is no tweet with this number.\n";
                        }
                    }
                }

                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "qoutetweet" and cSize == 3)
            {
                if(ans_user.count(logedin_user) == 1)
                {
                    std::cout << "! You can not retweet.\n";
                }
                else
                {
                    del_atsign(commands[1]);
                    if( users[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                    {
                        users[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "qoute");
                        std::cout << "* Qouted.\n";
                    }

                    else if( org_user[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                    {
                        org_user[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "qoute");
                        std::cout << "* Qouted.\n";
                    }

                    else
                    {
                        std::cout << "! There is no tweet with this number.\n";
                    }
                }
            }

            else if(commands[0][0] == '@' and cSize == 1)
            {
                if(is_in(commands[0], "like"))
                {
                    std::string num;
                    std::string user_name;
                    int cSize = commands[0].size();

                    for(int i = 0; i < cSize; i++)
                    {
                        if(commands[0][i] == ':')
                        {
                            for( int j = i+1; j < cSize; j++)
                            {
                                if(commands[0][j] != ':')
                                {
                                    num += commands[0][j];
                                }

                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }

                        else
                        {
                            user_name += commands[0][i];
                        }
                    }

                    int number = std::stoi(num);

                    user_name.erase(0, 1);
                    if(users.count(user_name))
                    {
                        users[user_name].print_likers(number);
                    }

                    else if(org_user.count(user_name))
                    {
                        org_user[user_name].print_likers(number);
                    }

                    else
                    {
                        std::cout << "! There is no user with this username.\n";
                    }
                }

                else if(is_in(commands[0], ':'))
                {
                    std::string num;
                    std::string user_name;
                    int cSize = commands[0].size();
                    for(int i = 0; i < cSize; i++)
                    {
                        if(commands[0][i] == ':')
                        {
                            for( int j = i+1; j < cSize; j++)
                            {
                                num += commands[0][j];
                            }
                            break;
                        }

                        else
                        {
                            user_name += commands[0][i];
                        }
                    }
                    int number = std::stoi(num);
                    user_name.erase(0, 1);
                    
                    if(user_name == "me")
                    {
                        user_name = logedin_user;
                    }

                    d1.show_tweet(*this, user_name, number);
                }


                else if(!is_in(commands[0], ':'))
                {
                    if(commands[0] == "@me")
                    {
                        if(is_logedin)
                        {
                            d1.show_tweet(*this, logedin_user);
                        }
                    }

                    else
                    {
                        commands[0].erase(0, 1);
                        d1.show_tweet(*this, commands[0]);
                    }
                }
            }

            else if(commands[0] == "dislike" and cSize == 2)
            {
                if(is_logedin)
                {
                    std::string user_name;
                    int number = 0;
                    bool tc;

                    tc = get_userName_number(commands[1], user_name, number);
                    del_atsign(user_name);

                    if(tc)
                    {
                        if(ans_user.count(logedin_user) == 1)
                        {
                            if(users.count(user_name))
                            {
                                if(li_user->isin_following(user_name))
                                {
                                    bool b;
                                    b = users[user_name].dislike(logedin_user, number);

                                    if(b)
                                    {
                                        li_user->pop_tweetLikes(number, user_name);
                                    }
                                }

                                else
                                {
                                    std::cout << "! You can not like this tweet.\n";
                                }
                            }

                            else if(org_user.count(user_name))
                            {
                                if(li_user->isin_following(user_name))
                                {
                                    bool b;
                                    b = org_user[user_name].dislike(logedin_user, number);

                                    if(b)
                                    {
                                        li_user->pop_tweetLikes(number, user_name);
                                    }
                                }

                                else
                                {
                                    std::cout << "! You can not like this tweet.\n";
                                }
                            }

                            else
                            {
                                std::cout << "! There is no user with this username.\n";
                            }
                        }

                        else
                        {
                            if(users.count(user_name))
                            {
                                bool b;
                                b = users[user_name].dislike(logedin_user, number);

                                if(b)
                                {
                                    li_user->pop_tweetLikes(number, user_name);
                                }

                            }

                            else if(org_user.count(user_name))
                            {
                                bool b;
                                b = org_user[user_name].dislike(logedin_user, number);

                                if(b)
                                {
                                    li_user->pop_tweetLikes(number, user_name);
                                }
                            }

                            else
                            {
                                std::cout << "! There is no user with this username.\n";
                            }
                        }
                    }
                    else
                    {
                        std::cout << "! undefined command.\n";
                    }
                }

                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "like" and cSize == 2)
            {
                if(is_logedin)
                {
                    std::string user_name;
                    int number = 0;
                    bool tc;

                    tc = get_userName_number(commands[1], user_name, number);
                    del_atsign(user_name);

                    if(tc)
                    {
                        if(ans_user.count(logedin_user) == 1)
                        {
                            if(users.count(user_name))
                            {
                                if(li_user->isin_following(user_name))
                                {
                                    bool b;
                                    b = users[user_name].like(logedin_user, number);

                                    if(b)
                                    {
                                        li_user->push_tweetLikes(number, user_name);
                                    }
                                }

                                else
                                {
                                    std::cout << "! You can not like this tweet.\n";
                                }
                            }

                            else if(org_user.count(user_name))
                            {
                                if(li_user->isin_following(user_name))
                                {
                                    bool b;
                                    b = org_user[user_name].like(logedin_user, number);

                                    if(b)
                                    {
                                        li_user->push_tweetLikes(number, user_name);
                                    }
                                }

                                else
                                {
                                    std::cout << "! You can not like this tweet.\n";
                                }
                            }

                            else
                            {
                                std::cout << "! There is no user with this username.\n";
                            }
                        }

                        else
                        {
                            if(users.count(user_name))
                            {
                                bool b;
                                b = users[user_name].like(logedin_user, number);

                                if(b)
                                {
                                    li_user->push_tweetLikes(number, user_name);
                                }
                            }

                            else if(org_user.count(user_name))
                            {
                                bool b;
                                b = org_user[user_name].like(logedin_user, number);

                                if(b)
                                {
                                    li_user->push_tweetLikes(number, user_name);
                                }
                            }

                            else
                            {
                                std::cout << "! There is no user with this username.\n";
                            }
                        
                        }
                    }
                    else
                    {
                        std::cout << "! undefined command.\n";
                    }
                }

                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "clear" or commands[0] == "cls")
            {
                #if OS_Windows
                    system("cls");
                #else
                    system("clear");
                #endif
            }

            else if(commands[0] == "mention" and cSize == 3)
            {
                del_atsign(commands[1]);

                if(is_logedin)
                {
                    if(ans_user.count(logedin_user) == 1)
                    {
                        if(users.count(commands[1]) == 1)
                        {
                            if(li_user->isin_following(commands[1]))
                            {
                                bool status;
                                status = users[commands[1]].add_mention(stoi(commands[2]), users[logedin_user].get_name(), logedin_user);

                                if(status)
                                {
                                    li_user->push_myMentions(stoi(commands[2]), commands[1]); // save mentions traces
                                }
                            }
                            else
                            {
                                std::cout << "! You can not mention this tweet.\n";
                            }
                        }

                        else if(org_user.count(commands[1]) == 1)
                        {
                            if(li_user->isin_following(commands[1]))
                            {
                                bool status;
                                status = org_user[commands[1]].add_mention(stoi(commands[2]), li_user->get_name(), logedin_user);

                                if(status)
                                {
                                    li_user->push_myMentions(stoi(commands[2]), commands[1]); // save mentions traces
                                }
                            }
                            else
                            {
                                std::cout << "! You can not mention this tweet.\n";
                            }
                        }

                        else
                        {
                            std::cout << "! There is no user with this username.\n";
                        }
                    }
                    else
                    {
                        if(users.count(commands[1]) == 1)
                        {
                            bool status;
                            status = users[commands[1]].add_mention(stoi(commands[2]), users[logedin_user].get_name(), logedin_user);

                            if(status)
                            {
                                li_user->push_myMentions(stoi(commands[2]), commands[1]); // save mentions traces
                            }
                        }

                        else if(org_user.count(commands[1]) == 1)
                        {
                            bool status;
                            status = org_user[commands[1]].add_mention(stoi(commands[2]), li_user->get_name(), logedin_user);

                            if(status)
                            {
                                li_user->push_myMentions(stoi(commands[2]), commands[1]); // save mentions traces
                            }
                        }

                        else
                        {
                            std::cout << "! There is no user with this username.\n";
                        }
                    }
                }
                else
                {
                    std::cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "show" and cSize == 4)
            {
                del_atsign(commands[2]);

                if(users.count(commands[2]) == 1)
                {
                    d1.show_mentions(*this, commands[2], stoi(commands[3]));
                }
                else if (org_user.count(commands[2]) == 1)
                {
                    d1.show_mentions(*this, commands[2], stoi(commands[3]));
                }
                else
                {
                    std::cout << "! There is no user with this username.\n";
                }
            }

            else if(commands[0] == "follow" and cSize == 2)
            {
                if(is_logedin)
                {
                    del_atsign(commands[1]);
                    li_user->follow(*this, commands[1]);
                }
                else
                {
                    std::cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0][0] == '#')
            {
                serch_hashtag(commands[0]);
            }

            else if(commands[0] == "like" and commands[1] == "mention" and cSize == 4)
            {
                if(is_logedin)
                {
                    std::string user_name;
                    int tweet_number = 0;
                    int ment_number = std::stoi(commands[3]);

                    bool b = get_userName_number(commands[2], user_name, tweet_number);
                    del_atsign(user_name);
                    
                    if(ans_user.count(logedin_user) == 1)
                    {
                        li_user->like_mention(tweet_number, logedin_user, ment_number);
                    }

                    else
                    {
                        if(users.count(user_name) == 1)
                        {
                            users[user_name].like_mention(tweet_number, logedin_user, ment_number);
                        }

                        else if(org_user.count(user_name) == 1)
                        {
                            org_user[user_name].like_mention(tweet_number, logedin_user, ment_number);
                        }

                        else
                        {
                            std::cout << "! There is no user with this username.\n";
                        }
                    }
                }
            }

            else
            {
                std:: cout << "! undefined command.\n";
            }
        }

        if(is_logedin)
        {
            std::cout << "> @" << li_user->get_username() << "> ";
        }
        else
        {
            std:: cout << "> ";
        }

        getline(std::cin , command);
        command = lower(command);
        tokenize(command);
    }
}