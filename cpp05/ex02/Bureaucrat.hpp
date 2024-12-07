#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <exception>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
        Bureaucrat(Bureaucrat& b);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& b);

        class GradeTooHighException: public std::exception
        {
            public:
                const char * what() const throw();
        };
        
        class GradeTooLowException: public std::exception
        {
            public:
                const char * what() const throw();
        };

        std::string getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(AForm &f);
        void    executeForm(AForm &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& b);

#endif