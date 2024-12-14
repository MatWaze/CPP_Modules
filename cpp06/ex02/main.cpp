#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

bool    tryCastARef(Base &p);
bool    tryCastBRef(Base &p);
bool    tryCastCRef(Base &p);

bool    tryCastAPtr(Base *p);
bool    tryCastBPtr(Base *p);
bool    tryCastCPtr(Base *p);

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

Base    *generate(void)
{
    switch (rand() % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void    identify(Base *p)
{
    if (tryCastAPtr(p))
        std::cout << "A" << std::endl;
    else if (tryCastBPtr(p))
        std::cout << "B" << std::endl;
    else if (tryCastCPtr(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Some other type" << std::endl;
}

void    identify(Base &p)
{
    if (tryCastARef(p))
        std::cout << "A" << std::endl;
    else if (tryCastBRef(p))
        std::cout << "B" << std::endl;
    else if (tryCastCRef(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Some other type" << std::endl;
}

int main()
{
    std::srand(time(NULL));

    try
    {
        Base    *b = generate();

        identify(b);
        identify(*b);

        delete b;
    }
    catch (std::bad_alloc &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}