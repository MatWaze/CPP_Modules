#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

#include <ostream>
struct Date
{
    unsigned int year; 
    unsigned int month; 
    unsigned int day;

    Date();
    Date(const Date &date);
    Date(unsigned int year, unsigned int month, unsigned int day);

    Date    &operator=(const Date &date);
    bool    operator>=(const Date &date);
    bool    operator<=(const Date &date);
    bool    operator==(const Date &date);
    bool    operator!=(const Date &date);
    int     operator-(const Date &date);
};

class BitcoinExchange
{
    private:
        float   _value;
        float   _rate;
        Date    _date;

    public:
        BitcoinExchange();
        BitcoinExchange(float value, float rate, Date date);
        BitcoinExchange(const BitcoinExchange &btc);
        ~BitcoinExchange();

        BitcoinExchange &operator=(const BitcoinExchange &btc);

        float   getValue() const;
        float   getRate() const;
        float   compute() const;
        Date    getDate() const;

};

std::ostream    &operator<<(std::ostream &os, const BitcoinExchange &btc);

#endif