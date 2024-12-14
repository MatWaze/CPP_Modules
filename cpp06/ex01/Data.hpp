#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class   Data
{
    private:
        std::string _val;
        int _id;
    public:
        Data();
        Data(Data &d);
        Data(std::string val, int id);
        Data    &operator=(const Data &d);
        ~Data();

        std::string getVal() const;
        int getId() const;

};

#endif