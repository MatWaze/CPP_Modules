#ifndef INTERN
# define INTERN

#include "AForm.hpp"

class   Intern
{
    private:
        AForm   *createPardon(std::string formTarget);
        AForm   *createRobotomy(std::string formTarget);
        AForm   *createShrubbery(std::string formTarget);
    public:
        Intern();
        Intern(Intern &i);
        ~Intern();

        Intern  &operator=(const Intern &i);

        AForm   *makeForm(std::string formName, std::string formTarget);
};

#endif