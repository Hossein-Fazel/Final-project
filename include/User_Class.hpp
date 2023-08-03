#ifndef USER_HPP
#define USER_HPP



#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "Base_User.hpp"

#include"Tweet_Class.hpp"
#include"Display_Class.hpp"
#include "Mention_class.hpp"

//================================================================================ User_Class ================================================================================ 

class user: public Base_User
{

//=================== Friends ===================

friend void tweet::set_user_age(user);                                  // friend with Tweet_Class to set user age
friend void tweet::rq_tweet(twitterak&, std::string);                   // friend with Tweet_Class to push_back tweets on vector
friend void display::show_tweet(twitterak);                             // friend with Twitterak_Class to show tweets
friend void display::show_tweet(twitterak, std::string, int);           // friend with Twitterak_Class to show tweets
friend void display::show_tweet(twitterak, std::string);                // friend with Twitterak_Class to show tweets
friend void display::show_mentions(twitterak, std::string user_name, int tweet_number);

friend void tweet::delete_tweet(twitterak, int);                         // friend with Twitterak_Class to delete a tweet
friend void tweet::edit_tweet(twitterak &, int);                         // friend with Twitterak_Class to edit a tweet


    public:
//===================== Gets ======================
        std::string get_biography() const;                         // returns the biography of the user
        std::string get_link() const;                              // returns the link of the user
        std::string get_birthday() const;                          // returns the date of birth of the user
        std::string get_phone() const;                             // returns the phone number of the user
        std::string get_password() const;                          // returns the password of the user's account
        std::string get_header() const;                            // returns the color of the header that user had chosen 
        std::string get_country() const;                           // returns the country of the user
        int get_last_number() const;                                    // returns the last tweet's number
        int get_following_num() const;

//====================== sets =====================

        void set_biography(std::string);                          // sets the biography of a user
        void set_link(std::string);                               // sets the link of a user
        void set_birthday(std::string);                           // sets the date of birth of a user
        void set_phone(std::string);                              // sets the phone number of a user
        void set_header(std::string);                             // sets the color of the header that user had chosen
        void set_country(std::string);                            // sets the country of the user

//=============== General functions =================

        void Delete_Account(twitterak &);                          // delets the account of the user
        void Show_Profile(twitterak &);                            // shows the information of a user itself
        void Edit(twitterak &, std::string, std::string);          // edits the user's information                                                                    
        void edit_tweet(int, twitterak &);
        void Tweet(std::string , twitterak &);                     // make a normal tweet
        void Logout(twitterak &);                                  // logs out of the user's account
        void Push_Tweet(tweet);                                    // push a tweet into a vector
        void last_number();                                        // plus plus last_num variable
        void print_likers(int);
        bool like(std::string ,int);
        bool dislike(std::string, int);
        bool validate_phone_number(std::string);                   // validate user's phone_number
        std::map <int, tweet> get_tweets();
        bool add_mention(int, std::string, std::string);
        void follow(twitterak &, std::string);
        void like_mention(int, std::string, int);

//================== Save_User_Traces ==================

        void push_myMentions(int , std::string);
        void push_tweetLikes(int, std::string);
        void pop_tweetLikes(int, std::string);

//================= Delete_User_Traces =================

        void del_myMentions(twitterak &);
        void cls_hashtags(twitterak &);
        void del_tweetLikes(twitterak &);

    private:
        std::string Full_Name;
        std::string Username;
        std::string Biography;
        std::string Link;
        std::string Birthday;
        std::string Phone_Number;
        std::string Password;
        std::string Header;
        std::string Country;

        int last_num = 0;

        std::map <int, tweet> tweets;

        std::unordered_set< std::string> following;

// ================================= User_Traces ============================

       std::unordered_map<std::string , std::unordered_set<int>> my_mentions;
       std::unordered_map<std::string , std::unordered_set<int>> tweetLikes;
       

};
#endif