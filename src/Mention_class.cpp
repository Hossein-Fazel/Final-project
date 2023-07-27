#include "Mention_class.hpp"
#include <unordered_map>
#include <string>
#include <iostream>

std::string mention::get_name() const
{
    return mName;
}

std::string mention::get_username() const
{
    return mUsername;
}

std::string mention::get_mention() const
{
    return mention;
}

int mention::get_number() const
{
    return mNumber;
}

int mention::get_likes_number() const
{
    return mLikes.size();
}

std:: unordered_map<std::string, bool> mention::operator~() const
{
    return mLikes;
}

void mention::set_name(std::string name)
{
    mName = name;
}

void mention::set_mention(std::string text)
{
    mention = text;
}

void mention::set_number(int num)
{
    mNumber = num;
}

void mention::set_userName(std:: string userName)
{
    mUsername = userName;
}

void mention::mention_like(std::string userName)
{
    if(mLikes.count(userName) == 0)
    {
        mLikes[userName] = true;
    }
    else
    {
        std::cout << "! You have already liked the mention.\n";
    }
}

void mention::mention_dislike(std::string userName)
{
    if(mLikes.count(userName))
    {
        mLikes.erase(userName);
    }
    else
    {
        std::cout << "! You have never like this mention.\n";
    }
}