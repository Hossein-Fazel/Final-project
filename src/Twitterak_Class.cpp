#include <iostream>
#include <string>
#include <vector>

#include "Twitterak_Class.hpp"
#include "Display_Class.hpp"

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

    display d1;

    std:: string command;

    getline(std::cin , command);
    while (command != "exit")
    {
        if(commands[0] == "login")
        {
            if(is_logedin == true)
            {
                std::cout << "! you are loged in\n";
                std::cout << "if ";
            }
        }
    }
    
}