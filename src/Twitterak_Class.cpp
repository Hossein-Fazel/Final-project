#include <iostream>
#include <string>
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

    if(is_logedin == true)
    {
        std::cout << "@" << users[logedin_user].get_username() << ">";
    }
    else
    {
        std:: cout << ">";
    }

    display d1;

    std:: string command;
    getline(std::cin , command);
    tokenize(command);

    while (commands[0] != "exit")
    {
        int cSize = commands.size();
        if(commands[0] == "login")
        {
            if(is_logedin == true)
            {
                std::cout << "! You are already loged in\n";
            }
            else
            {
                if(cSize == 1)
                {
                    d1.login(*this);
                }
                else if(cSize == 2)
                {
                    d1.login(*this, commands[1]);
                }
                else if (cSize == 3)
                {
                    d1.login(*this);
                }
            }
        }

        else if(commands[0] == "signup")


        if(is_logedin == true)
        {
            std::cout << "@" << users[logedin_user].get_username() << ">";
        }
        else
        {
            std:: cout << ">";
        }
        
        getline(std::cin , command);
        tokenize(command);
    }
    
}
