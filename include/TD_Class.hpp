#include <string>

class TD
{
    public:
        TD();
        void print_time();
        void print_date();

    private:
        std::string time;
        std::string month;
        int day, year;

};