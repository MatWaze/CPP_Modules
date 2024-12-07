#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &pardon);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm  &operator=(const RobotomyRequestForm &pardon);

        void    execute(Bureaucrat const &executor);
        std::string getTarget() const;
};

#endif
