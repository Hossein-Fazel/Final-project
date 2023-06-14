#include <iostream>
#include <string>
#include <vector>

#include "Twitterak_Class.hpp"

bool twitterak::is_logedin = false;

bool twitterak::is_logedin;
std:: string twitterak::log_user;
std::vector<std::string> twitterak::commands; 
std::unordered_map<std::string, user> twitterak::users;
std::unordered_map<std::string,tweet> twitterak::Hashtags;

void twitterak::tokenize(std::string command)
{
    std::string cm="";
    for(int i = 0; i < command.size(); i++)
    {
        if(int(command[i]) != 32)
        {
            cm += command[i];
        }
        else
        {
            commands.push_back(cm);
            cm = "";
        }
    }
    commands.push_back(cm);
}


void twitterak::run()
{
    system("cls");
    std::cout << "\t\t\t--- Wellcome to Twitterak ---\n";
    std::cout << "If you need help, enter help command\n";
    std::cout << ">";

    std:: string command;

    getline(std::cin , command);
    while (command != "exit")
    {
        if(commands[0] == "login")
        {
            if(commands.size() > 1)
            {
                
            }
        }
    }
    
}

