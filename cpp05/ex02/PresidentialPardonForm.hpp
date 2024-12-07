#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"
#include <string>

class   PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &pardon);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &pardon);

        std::string getTarget() const;
        // void    execute(Bureaucrat const &executor);
};

#endif