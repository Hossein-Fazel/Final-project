#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

#include "Twitterak_Class.hpp"
#include "Display_Class.hpp"

void twitterak::tokenize(std::string command)
{
    commands.clear();

    std::string cm="";
    for(int i = 0; i < command.size(); i++)
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
            if(commands[0] == "login")
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

            else if(commands[0] == "signup")
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

            else if(commands[0] == "delete")
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

            else if(commands[0] == "profile" and commands.size() == 2)
            {

                if(commands[1][0] == '@')
                {
                    commands[1].erase(0, 1);
                }
                
                users[commands[1]].Show_Profile(*this);
            }

            else if(commands[0] == "profile" or commands[0] == "me" or commands[0] == "@me")
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

            else if(commands[0] == "logout")
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

            else if (commands[0] == "exit" or commands[0] == "quit" or commands[0] == "q")
            {
                std::cout << "Good Bye\n";
                exit(0);
            }

            else if (commands[0] == "help")
            {
                d1.help(*this);
            }
            
            else
            {
                std:: cout << "! undefined command.\n";
            }
        
        }

        if(is_logedin)
        {
            std::cout << "@" << users[logedin_user].get_username() << "> ";
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