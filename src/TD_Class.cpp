#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "TD_Class.hpp"

TD::TD()
{
    std::vector<std::string> time_part;
    time_t now = std::time(0);
    std::string dt = std::ctime(&now);

    std::string cm="";
    int size = dt.size();
    for(int i = 0; i < size; i++)
    {
        if(int(dt[i]) != 32)
        {
            cm += dt[i];
        }
        else
        {
            if(cm.empty())
            {
                continue;
            }
            else
            {
                time_part.push_back(cm);
                cm = "";
            }
        }
    }
    if(!cm.empty())
    {
        time_part.push_back(cm);
    }

    time = time_part[3];
    month = time_part[1];
    day = std::stoi(time_part[2]);
    year = std::stoi(time_part[4]);
}

void TD::print_date()
{
    std::cout << year << " " << month << " " << day;
}

void TD::print_time()
{
    std::cout << time;
}