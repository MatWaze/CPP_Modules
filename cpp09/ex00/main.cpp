#include <cctype>
#include <climits>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"
#include <cstdlib>

std::string trim(const std::string &str);
bool    validDate(const std::string &year, const std::string &month, const std::string &day);
Date    createDate(const std::string &dateStr);
float rate(Date &date);
BitcoinExchange createBitcoin(const std::string &line);

std::string trim(const std::string &str)
{
    std::string s(str);
    std::string whitespace = " \n\r\t";

    size_t first = s.find_first_not_of(whitespace);
    size_t last = s.find_last_not_of(whitespace);

    if (first == std::string::npos)
        s = "";
    else if (first == last)
        s = s.substr(first,1);
    else
        s = s.substr(first, (last - first + 1));
    return s;
}

std::list<std::string> getSplitted(const std::string &line, char delim)
{
    std::istringstream  is;
    std::list<std::string> splitted;

    is.str(line);

    for (std::string token; std::getline(is, token, delim) ;)
        splitted.push_back(token);

    return splitted;
}

// if year and month equal: 12 > 10 also 12 > 7, but 12-10=2 > 12-7=5 so choose 10th

float rate(Date &date)
{
    std::ifstream   file("data.csv");

    int i = INT_MIN;
    float ans = 0;

    for (std::string line; std::getline(file, line) ;)
    {
        // skip first row of a csv file correspoding to the names of columns
        if (i == INT_MIN)
        {
            i = INT_MAX;
            continue;
        }

        std::list<std::string> splitted = getSplitted(line, ',');
        std::list<std::string>::iterator beg = splitted.begin(); 
        
        std::string dt = *beg++;
        std::string vl = *beg;

        Date rateDate = createDate(dt);

        int diff = date - rateDate;
        if (diff < i && diff >= 0)
        {
            i = diff;
            ans = atof(vl.c_str());
        }
    }
    return ans;
}

bool    isInt(const std::string &str)
{
    unsigned int i = 0;

    for (; i < str.length() && std::isdigit(str[i]); i++) ;

    return str.length() < 11 && str.length() == i;
}

bool    validDate(const std::string &year, const std::string &month, const std::string &day)
{
    bool numeric = isInt(year) && isInt(month) && isInt(day);
    bool validYear = atol(year.c_str()) >= 0;
    bool validMonth = month.length() == 2 && atol(month.c_str()) > 0 && atol(month.c_str()) < 13;
    bool validDay = day.length() == 2 && atol(day.c_str()) > 0 && atol(day.c_str()) < 32;

    return numeric && validYear && validMonth && validDay;
}

Date   createDate(const std::string &dateStr)
{
    std::list<std::string> ymd = getSplitted(dateStr, '-');

    if (ymd.size() == 3)
    {
        std::list<std::string>::iterator it = ymd.begin();
        std::string year = *it++;
        std::string month = *it++;
        std::string day = *it;

        if (validDate(year, month, day))
            return Date(atol(year.c_str()), atol(month.c_str()), atol(day.c_str()));
    }

    throw BitcoinExchange::InvalidDateException(dateStr);
} 

BitcoinExchange    createBitcoin(const std::string &line)
{
    std::list<std::string> splitted = getSplitted(line, '|');

    if (splitted.size() != 2)
        throw BitcoinExchange::InvalidInputException(line);

    std::list<std::string>::iterator it = splitted.begin();

    std::string d = *it++;
    std::string v = *it;

    d = trim(d);
    v = trim(v);

    Date date = createDate(d);
    
    float val = atof(v.c_str());

    if (val < 0 || val > 1000)
        throw BitcoinExchange::InvalidValueException(line);

    float rt = rate(date);
    BitcoinExchange btc = BitcoinExchange(val, rt, date);
    return btc;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            std::ifstream   file(argv[1]);

            std::string line;
            int i = 0;
            while (std::getline(file, line))
            {
                if (i == 0)
                {
                    i = -1;
                    continue;
                }

                try
                {
                    BitcoinExchange b = createBitcoin(line);
                    std::cout << b << std::endl;
                }
                catch (std::exception &ex)
                {
                    std::cout << ex.what() << std::endl;
                }
            }

            file.close();
        }
        catch (std::exception &x)
        {
            std::cout << x.what() << std::endl;
        }
    }
    else
        std::cout << "Usage: ./btc file_name\nfile_name - name of a file containing date and value rows to evaluate" << std::endl;

    return 0;
}