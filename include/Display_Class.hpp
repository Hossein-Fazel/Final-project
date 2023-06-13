#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

class display
{
    public:
        void help();
        // void menu();
        void login(std::string , std::string);
        void login();
        void signup();
        void show_tweet();
};


#endif