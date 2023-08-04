#ifndef ORGANISATION_USER_HPP
#define ORGANISATION_USER_HPP

#include <iostream>
#include <map>

#include "Base_User.hpp"
// #include "User_Class.hpp"


class Organisation : public Base_User
{
    friend void user::del_tweetLikes(twitterak &);
    
    public:
//========================================= Get_Functions =====================================

        std::string get_manager_username() const;                                // shows the usernsmae of an organisation's manager 
        int get_last_number() const;                                             // shows the last number of a tweet
        std::unordered_map <int, tweet> get_tweets();                                // shows organisation's tweets

//========================================= Set_Functions =====================================

        void set_manager_username(twitterak, std::string);                       // sets the usernsmae of an organisation's manager
        void set_biography(std::string);
//================== General_Functions ====================

        void Delete_Account(twitterak &);                                        // delets the account of an organisation
        void Show_Profile(twitterak &);                                          // shows the information of an organisation itself
        void Edit(twitterak &, std::string, std::string);                        // edits an organisation's information                                                                    
        void edit_tweet(int, twitterak &);                                       // edits an organisation's tweet
        void Tweet(std::string , twitterak &);                                   // make a normal tweet
        void Push_Tweet(tweet);                                                  // push a tweet into a vector                          
        void increase_last_number();                              
        void print_likers(int);                                 
        bool like(std::string ,int);                             
        bool dislike(std::string, int);                           
        bool validate_phone_number(std::string);                 
        bool add_mention(int, std::string, std::string);         
        void follow(twitterak &, std::string);                   
        void like_mention(int, std::string, int); 

//==================== Save_Organisation_Traces ====================

        void push_myMentions(int, std::string);                                 // save my mention traces
        void push_tweetLikes(int, std::string);                                 // save my tweet likes traces
        void pop_tweetLikes(int, std::string);                                  // delete a like of a tweet

//=================== Delete_Organisation_Traces ===================

        void del_myMentions(twitterak &);                                       // delete mention traces
        void cls_hashtags(twitterak &);                                         // delete hashtag traces
        void del_tweetLikes(twitterak &);                                       // delete tweet like traces

    private:
        std::string manager_username;
        std::unordered_map<int , tweet> tweets;
        int last_number = 0;

        std::unordered_set<std::string> following;

       std::unordered_map<std::string , std::unordered_set<int>> my_mentions;
       std::unordered_map<std::string , std::unordered_set<int>> tweetLikes;
};

#endif