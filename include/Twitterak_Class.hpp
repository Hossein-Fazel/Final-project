#include "User_Class.hpp"
#include "Tweet_Class.hpp"

#include <unordered_map>
#include <vector>
#include <string>


#ifndef TWITTERAK_HPP
#define TWITTERAK_HPP

class twitterak
{
    public:
        void run();

    private:
        std::unordered_map<std::string, user> users;
        std::unordered_map<std::string,tweet> Hashtags;

};

#endif