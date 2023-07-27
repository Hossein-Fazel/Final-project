#ifndef MENTION_HPP
#define MENTION_HPP

#include <string>
#include <unordered_map>

class mention
{
    public:
//      ======================================== sets =============================================
        void set_userName(std::string);
        void set_name(std::string);
        void set_number(int);
        void mention_like(std::string user_name);
        void mention_dislike(std::string user_name);

//      ======================================== gets =============================================
        int get_number()const;
        int get_likes_number()const;
        std::string get_name()const;
        std::string get_username()const;
        std::unordered_map<std::string, bool> operator~() const;

    private:
        std::string mUsername;
        std::string mName;
        int mNumber;
        std::unordered_map<std::string, bool> mLikes;
};


#endif