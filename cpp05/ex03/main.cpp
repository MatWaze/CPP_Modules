#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern  i;
    Bureaucrat  b(25, "Dayn");

    AForm   *form = i.makeForm("PresidentialPardon", "house");

    if (form)
        form->execute(b);
    delete form;
    return 0;
}
