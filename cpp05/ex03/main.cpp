#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main()
{
    Intern  i;
    Bureaucrat  b(25, "Dayn");

    AForm   *form = i.makeForm("PresidentialPardon", "house");

    if (form)
        form->execute(b);
    return 0;
}
