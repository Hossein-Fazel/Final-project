#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

#include "sha256.h"

class display
{
    public:
        void help();
        void login(std::string , std::string);
        void login();
        void signup();
        void show_tweet();

        SHA256 encrypt;
};

#endif