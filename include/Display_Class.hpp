#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

#include "sha256.h"

class twitterak;

class display
{
    public:
        void help(twitterak &);
        void login(twitterak &,std::string , std::string);
        void login(twitterak &, std::string );
        void login(twitterak &);
        void signup(twitterak &);
        // void show_tweet();

        SHA256 encrypt;
};

#endif