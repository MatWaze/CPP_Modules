#include "BitcoinExchange.hpp"
#include <ostream>

// Date

Date::Date()
{
    this->year = -1;
    this->month = -1;
    this->day = -1;
}

Date::~Date() {}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date    &Date::operator=(const Date &date)
{
    if (this != &date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }
    return *this;
}

bool    Date::operator==(const Date &date)
{
    return this->year == date.year && this->month == date.month && this->day == date.day;
}

bool    Date::operator!=(const Date &date)
{
    return !(*this == date);
}

bool    Date::operator>=(const Date &date)
{
    return this->year >= date.year && this->month >= date.month && this->day >= date.day;
}

bool    Date::operator<=(const Date &date)
{
    return this->year <= date.year && this->month <= date.month && this->day <= date.day;
}

int Date::operator-(const Date &date)
{
    return (this->year - date.year) * 365 + (this->month - date.month) * 30 + (this->day - date.day);
}

//BitcoinExchange

BitcoinExchange::BitcoinExchange()
{
    this->_date = Date();
    this->_value = 0.0f;
}

BitcoinExchange::BitcoinExchange(float value, float rate, Date date)
{
    this->_value = value;
    this->_rate = rate;
    this->_date = date;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc)
{
    this->_value = btc._value;
    this->_rate = btc._rate;
    this->_date = btc._date;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
    if (this != &btc)
    {
        this->_value = btc._value;
        this->_rate = btc._rate;
        this->_date = btc._date;
    }
    return *this;
}

Date    BitcoinExchange::getDate() const
{
    return this->_date;
}

float   BitcoinExchange::getValue() const
{
    return this->_value;
}

float   BitcoinExchange::getRate() const
{
    return this->_rate;
}

float   BitcoinExchange::compute() const
{
    return this->_value * this->_rate;
}

std::ostream    &operator<<(std::ostream &os, const BitcoinExchange &btc)
{
    os << btc.getValue() << "₿ was worth $" << btc.compute() << " on " 
    << btc.getDate().year << "-" << btc.getDate().month << "-" << btc.getDate().day;

    return os;
}

// InvalidValueException

BitcoinExchange::InvalidValueException::InvalidValueException(const std::string val) throw()
{
    this->_msg = "[ " + val + " ] - " + "Value must be a number between 1 and 1000";
}

const char *BitcoinExchange::InvalidValueException::what() const throw()
{
    return this->_msg.c_str();
}

BitcoinExchange::InvalidValueException::~InvalidValueException() throw() {}

// InvalidDateException

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string date) throw()
{
    this->_msg = "[ " + date + " ] - " + "Date must be of format yy-mm-dd,\nwhere yy is a positive integer, mm is between 1 and 12, and dd is between 1 and 31";
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
    return this->_msg.c_str();
}

BitcoinExchange::InvalidDateException::~InvalidDateException() throw() {}

// InvalidInputException

BitcoinExchange::InvalidInputException::InvalidInputException(const std::string msg) throw()
{
    this->_msg = "[ " + msg + " ] - " + "Input string must be of format date | value";
}

const char *BitcoinExchange::InvalidInputException::what() const throw()
{
    return this->_msg.c_str();
}

BitcoinExchange::InvalidInputException::~InvalidInputException() throw() {}
