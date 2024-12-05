#ifndef FORM
# define FORM

#include "Bureaucrat.hpp"
#include <string>

class Form
{
    private:
        const std::string _name;
        bool _isSigned = false;
        const int _gradeSign;
        const int _gradeExec;
    
    public:
        Form();
        Form(Form &f);
        Form(std::string name, int gradeSign, int gradeExec);
        ~Form();

        Form    &operator=(const Form &f);

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

        const std::string getName() const;
        bool    getIsSigned() const;
        const int   getGradeSign() const;
        const int   getGradeExec() const;

        void    beSigned(Bureaucrat &b);
        void    signForm();
};

std::ostream    &operator<<(std::ostream &os, Form &f);

#endif