#ifndef ANONYMOUS_USER_HPP
#define ANONYMOUS_USER_HPP

#include <iostream>
#include <unordered_map>

#include "Base_User.hpp"          

class twitterak;

class Anonymous : public Base_User
{
    public: 
        Anonymous();
        void Edit(twitterak &, std::string, std::string);          // edits the user's information    
        void Show_Profile(twitterak &);                            // shows the information of a user itself
        void follow(twitterak &, std::string);                     // follow a user that must be personal user
        void Delete_Account(twitterak &);                          // delets the account of the user
        bool isin_following(std::string);
        int get_following_num() const;

        void push_myMentions(int, std::string);                   // save my mention traces
        void push_tweetLikes(int, std::string);                   // save my tweet likes traces
        void pop_tweetLikes(int, std::string);                    // delete a like of a tweet

        void del_myMentions(twitterak &);
        void del_tweetLikes(twitterak &);
        void unfollow_followers(twitterak &app);                                // delete you from your followers list

    private:
        std::unordered_set<std::string> following;

        std::unordered_map<std::string , std::unordered_set<int>> my_mentions;
        std::unordered_map<std::string , std::unordered_set<int>> tweetLikes;
};

#endif