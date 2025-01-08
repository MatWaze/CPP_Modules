#include <climits>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"
#include <cstdlib>

std::string trim(const std::string &str);
bool    validDate(std::list<std::string> ymd);
Date    createDate(const std::string &dateStr);
float rate(const Date &date);
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

float rate(const Date &date)
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

        int diff = abs(rateDate - date);
        if (diff < i && rateDate <= date)
        {
            i = diff;
            ans = atof(vl.c_str());
        }
    }
    return ans;
}

bool    isNumeric(const std::string &str)
{
    unsigned int i = 0;

    for (; i < str.length(); i++) ;

    return str.length() == i;
}

bool    validDate(std::list<std::string> ymd)
{
    std::list<std::string>::iterator it = ymd.begin();
    std::string year = *it++;
    std::string month = *it++;
    std::string day = *it;

    bool numeric = isNumeric(year) && isNumeric(month) && isNumeric(day);
    bool validYear = atoi(year.c_str()) >= 0;
    bool validMonth = atoi(month.c_str()) > 0 && atoi(month.c_str()) < 13;
    bool validDay = atoi(day.c_str()) > 0 && atoi(day.c_str()) < 32;

    return numeric && validYear && validMonth && validDay;
}

Date   createDate(const std::string &dateStr)
{
    std::list<std::string> ymd = getSplitted(dateStr, '-');

    std::list<std::string>::iterator it = ymd.begin();
    std::string year = *it++;
    std::string month = *it++;
    std::string day = *it;

    if (validDate(ymd))
        return Date(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()));
    return Date();
} 

BitcoinExchange    createBitcoin(const std::string &line)
{
    std::istringstream  is;
    std::string splitted[2];

    is.str(line);

    int i = 0;
    for (std::string token; std::getline(is, token, '|') ;)
        splitted[i++] = token;

    splitted[0] = trim(splitted[0]);
    splitted[1] = trim(splitted[1]);

    float val = atof(splitted[1].c_str());

    if (val < 0 || val > 1000)
        return BitcoinExchange(val, 0, Date());

    Date date = createDate(splitted[0]);

    BitcoinExchange btc = BitcoinExchange();
    if (date != Date())
    {
        float rt = rate(date);

        btc = BitcoinExchange(val, rt, date);
    }
    return btc;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            std::list<BitcoinExchange>  btcList;
            
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

                BitcoinExchange b = createBitcoin(line);
                if (b.getValue() < 0 || b.getValue() > 1000)
                    std::cout << "Error: invalid value\n";
                else if (b.getDate() == Date())
                    std::cout << "Error: invalid date\n";
                else
                    std::cout << b << std::endl;
                btcList.push_back(b);
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