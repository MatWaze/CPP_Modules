#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

#include "AForm.hpp"

class   ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &pardon);
        ~ShrubberyCreationForm();
        
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &pardon);

        void    execute(Bureaucrat const &executor) const;
        std::string getTarget() const;
};

#endif
