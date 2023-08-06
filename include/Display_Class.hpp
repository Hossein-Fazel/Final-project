#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

#include "sha256.h"

class twitterak;
class tweet;

class display
{
    public:
        void help(twitterak &);
        void login(twitterak &,std::string , std::string);
        void login(twitterak &, std::string );
        void login(twitterak &);
        void signup(twitterak &);
        void signup(twitterak &, std::string);
        void show_tweet(twitterak,std::string, int);
        void show_tweet(twitterak,std::string);
        void show_mentions(twitterak, std::string user_name, int tweet_number);

        void show_normal(tweet);
        void show_re(tweet);
        void show_qoute(tweet);

        SHA256 encrypt;
};

#endif