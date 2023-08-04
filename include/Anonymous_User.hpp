#ifndef ANONYMOUS_USER_HPP
#define ANONYMOUS_USER_HPP

#include <iostream>
#include <unordered_map>

#include "Base_User.hpp"
// #include "Twitterak_Class.hpp"          

class twitterak;

class Anonymous : public Base_User
{
    public: 
        Anonymous();
        void Edit(twitterak &, std::string, std::string);          // edits the user's information    
        bool like(std::string ,int);                                                                  // شرط اینکه دنبال کرده باشدش
        void like_mention(int, std::string, int);                                                     // شرط اینکه دنبال کرده باشدش
        void add_followers(std::string);                            // add a new follower to set (no one can follow this user)   // کسی نباید بتونه فالو کنه
        void follow(twitterak &, std::string);                      // follow a user that must be personal user
};

#endif