#ifndef FORM
# define FORM

#include <string>

class Bureaucrat;

class Form
{
    private:
        const int _gradeExec;
        const int _gradeSign;
        const std::string _name;
        bool _isSigned;
    
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

        std::string getFormName() const;
        bool    getIsSigned() const;
        int   getGradeSign() const;
        int   getGradeExec() const;

        void    beSigned(Bureaucrat &b);
};

std::ostream    &operator<<(std::ostream &os, const Form &f);

#endif