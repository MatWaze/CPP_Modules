#ifndef AFORM
# define AFORM

#include <string>

class Bureaucrat;

class AForm
{
    private:
        const int _gradeExec;
        const int _gradeSign;
        const std::string _name;
        bool _isSigned;

    public:
        AForm();
        AForm(AForm &f);
        AForm(std::string name, int gradeSign, int gradeExec);

        // virtual destructor for proper deletion of base class
        virtual ~AForm();

        AForm    &operator=(const AForm &f);

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

        virtual void    beSigned(Bureaucrat &b);
        virtual void    execute(Bureaucrat const &executor) const = 0;
};

std::ostream    &operator<<(std::ostream &os, const AForm &f);

#endif
