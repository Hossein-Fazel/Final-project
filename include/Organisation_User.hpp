#ifndef ORGANISATION_USER_HPP
#define ORGANISATION_USER_HPP

#include <iostream>
#include <map>

#include "Base_User.hpp"
#include "Display_Class.hpp"


class Organisation : public Base_User
{    
    friend void display::show_tweet(twitterak app, std::string user_name);
    friend void display::show_tweet(twitterak app,std::string user_name, int number);
    friend void display::show_mentions(twitterak app, std::string user_name, int tweet_number);
    
    public:
//========================================= Get_Functions =====================================

        std::string get_manager_username() const;                                // shows the usernsmae of an organisation's manager 
        int get_last_number() const;                                             // shows the last number of a tweet
        std::unordered_map <int, tweet> get_tweets();                                // shows organisation's tweets

//========================================= Set_Functions =====================================

        void set_manager_username(twitterak, std::string);                       // sets the usernsmae of an organisation's manager
        void set_biography(std::string);                                         // sets the biography of an organisation

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
        bool add_mention(int, std::string, std::string);         
        void follow(twitterak &, std::string);                   
        void like_mention(int, std::string, int); 
        void unfollow(std::string);                               // unfollow the user name
        std::unordered_set<std::string> get_following();

//==================== Save_Organisation_Traces ====================

        void push_myMentions(int, std::string);                                 // save my mention traces
        void push_tweetLikes(int, std::string);                                 // save my tweet likes traces
        void pop_tweetLikes(int, std::string);                                  // delete a like of a tweet

//=================== Delete_Organisation_Traces ===================
        void del_men(int, std::string);                           // delete a mention
        void del_tweetlike(int , std::string);                    // delete a tweet like
        void del_myMentions(twitterak &);                         // delete mention traces
        void cls_hashtags(twitterak &);                           // delete hashtag traces
        void del_tweetLikes(twitterak &);                         // delete tweet like traces
        void unfollow_followers(twitterak &app);                  // delete you from your followers list

    private:
        user * manager;
        std::unordered_map<int , tweet> tweets;
        int last_number = 0;

        std::unordered_set<std::string> following;

        std::unordered_map<std::string , std::unordered_set<int>> my_mentions;
        std::unordered_map<std::string , std::unordered_set<int>> tweetLikes;
};

#endif