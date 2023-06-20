#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

#include "Twitterak_Class.hpp"
#include "Display_Class.hpp"
#include "User_Class.hpp"


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

std::string twitterak::lower(std::string command)
{
    for(int i = 0; i < command.size(); i++)
    {
        command[i] = std::tolower(command[i]);
    }

    return command;
}


void twitterak::run()
{
    system("cls | clear");
    std::cout << "\t\t\t--- Welcome to Twitterak ---\n";
    std::cout << "If you need help, enter help command :)\n";

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
            if(commands[0] == "login" and (cSize == 1 or cSize == 2 or cSize == 4))
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
                        d1.login(*this, commands[1]);
                        std::cin.ignore();
                    }
                    else if (cSize == 3)
                    {
                        d1.login(*this, commands[1], commands[2]);
                    }
                }
            }

            else if(commands[0] == "signup" and (cSize == 1 or cSize == 2))
            {
                if(is_logedin)
                {
                    std::cout << "! You must login first to your account.\n";
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

            else if(commands[0] == "delete" and cSize == 2)
            {
                if(is_logedin)
                {
                    if(commands[1] == "account")
                    {
                        users[logedin_user].Delete_Account(*this);
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
                if(commands[1][0] == '@')
                {
                    commands[1].erase(0, 1);
                }

                if(users.count(commands[1]) == 1)
                {
                    users[commands[1]].Show_Profile(*this);
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
                    users[logedin_user].Show_Profile(*this);
                }

                else
                {
                    std:: cout << "! You must login first to your account.\n";
                }
            }

            else if(commands[0] == "edit")
            {
                if(is_logedin)
                {
                    if(cSize == 4 and !commands[3].empty())
                    {
                        if(commands[2] != "phone_number" and commands[2] != "birthday")
                        {
                            commands[3] = commands[3].erase(0,1);
                            commands[3] = commands[3].erase(commands[3].size()-1,1);
                        }
                        users[logedin_user].Edit(*this, commands[2], commands[3]);
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
                    users[logedin_user].Logout(*this);
                }
                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if ((commands[0] == "exit" or commands[0] == "quit" or commands[0] == "q") and cSize == 1)
            {
                std::cout << "Good Bye\n";
                exit(0);
            }

            else if (commands[0] == "help")
            {
                d1.help(*this);
            }

            else if(commands[0] == "tweet" and (cSize == 1 or cSize == 2))
            {
                if(is_logedin)
                {
                    if(commands.size() == 2)
                    {
                        users[logedin_user].Tweet(commands[1]);
                    }
                    else if(commands.size() == 1)
                    {
                        users[logedin_user].Tweet("");
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
                    if(commands[1][0] == '@')
                    {
                        commands[1].erase(0,1);
                    }

                    if( users[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                    {
                        users[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "retweet");
                        std::cout << "* Retweeted.\n";
                    }
                    else
                    {
                        std::cout << "! There is no tweet with this number.\n";
                    }
                }

                else
                {
                    std:: cout << "! You must login first to your account\n";
                }
            }

            else if(commands[0] == "qoutetweet" and cSize == 3)
            {
                if(commands.size() !=  3)
                {
                    std::cout << "! undefined command.\n";
                }

                else
                {
                    if(commands[1][0] == '@')
                    {
                        commands[1].erase(0,1);
                    }
                    if( users[commands[1]].get_tweets().count(std::stoi(commands[2])) )
                    {
                        users[commands[1]].get_tweets()[std::stoi(commands[2])].rq_tweet(*this, "qoute");
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
                    
                    d1.show_tweet(*this, user_name, number);
                }


                else if(!is_in(commands[0], ':'))
                {
                    if(commands[0] == "@me")
                    {
                        d1.show_tweet(*this);
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
                std::string num;
                std::string user_name;
                for(int i = 1; i < commands[1].size(); i++)
                {
                    if(commands[1][i] == ':')
                    {
                        for( int j = i+1; j < commands[1].size(); j++)
                        {
                            num += commands[1][j];
                        }
                        break;
                    }
                    else
                    {
                        user_name += commands[1][i];
                    }
                }
                int number = std::stoi(num);

                users[user_name].dislike(logedin_user, number);
            }

            else if(commands[0] == "like" and cSize == 2)
            {
                std::string num = "";
                std::string user_name;
                for(int i = 1; i < commands[1].size(); i++)
                {
                    if(commands[1][i] == ':')
                    {
                        for( int j = i+1; j < commands[1].size(); j++)
                        {
                            num += commands[1][j];
                        }
                        break;
                    }
                    else
                    {
                        user_name += commands[1][i];
                    }
                }
                int number = std::stoi(num);

                users[user_name].like(logedin_user, number);
            }

            else if(commands[0] == "clear" or commands[0] == "cls")
            {
                system("cls | clear");
            }

            else
            {
                std:: cout << "! undefined command.\n";
            }
        }

        if(is_logedin)
        {
            std::cout << "> @" << users[logedin_user].get_username() << "> ";
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