#ifndef ORGANISATION_USER_HPP
#define ORGANISATION_USER_HPP

#include <iostream>

#include "Base_User.hpp"

class Organisation : public Base_User
{
    public:
//========================================= Get_Functions =====================================

        std::string get_manager_username() const;                                // shows the usernsmae of an organisation's manager 
        std::string get_biography() const;                                       // shows the biography of an organisation account
        std::string get_link() const;                                            // shows the link of an organisation account
        std::string get_phone() const;                                           // shows the phone number of an organisation 
        std::string get_header() const;                                          // shows the color of the header that an organisation had chosen
        std::string get_country() const;                                         // shows the country of an organisation 
        int get_last_number() const;                                             // shows the last number of a tweet
        std::map <int, tweet> get_tweets() const;                                // shows organisation's tweets

//========================================= Set_Functions =====================================

        void set_manager_username(twitterak, std::string);                       // sets the usernsmae of an organisation's manager
        void set_biography(std::string);                                         // sets the biography of an organisation account
        void set_link(std::string);                                              // sets the link of an organisation account
        void set_phone(std::string);                                             // sets the phone number of an organisation
        void set_header(std::string);                                            // sets the color of the header that an organisation had chosen
        void set_country(std::string);                                           // sets the country of an organisation

//================== General_Functions ====================

        void Delete_Account(twitterak &);                                        // delets the account of an organisation
        void Show_Profile(twitterak &);                                          // shows the information of an organisation itself
        void Edit(twitterak &, std::string, std::string);                        // edits an organisation's information                                                                    
        void edit_tweet(int, twitterak &);                                       // edits an organisation's tweet
        void Tweet(std::string , twitterak &);                                   // make a normal tweet
        void Push_Tweet(tweet);                                                  // push a tweet into a vector                          
        void last_number();                              
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
        std::string organisation_bio;
        std::string organisation_link;
        std::string organisation_phone;
        std::string organisation_header;
        std::string organisation_country;
        int last_number = 0;
};

#endif