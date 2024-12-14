#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <exception>

bool    tryCastARef(Base &p)
{
    bool    ans = false;

    try
    {
        A   a = dynamic_cast<A&>(p);
        ans = true;               
    }
    catch (std::exception &ex)
    {
        (void) ex;
    }
    return ans;
}

bool    tryCastBRef(Base &p)
{
    bool    ans = false;

    try
    {
        B   b = dynamic_cast<B&>(p);
        ans = true;               
    }
    catch (std::exception &ex)
    {
        (void) ex;
    }
    return ans;
}

bool    tryCastCRef(Base &p)
{
    bool    ans = false;

    try
    {
        C   c = dynamic_cast<C&>(p);
        ans = true;               
    }
    catch (std::exception &ex)
    {
        (void) ex;
    }
    return ans;
}

bool    tryCastAPtr(Base *p)
{
    if (dynamic_cast<A*>(p))
        return true;
    return false;
}

bool    tryCastBPtr(Base *p)
{
    if (dynamic_cast<B*>(p))
        return true;
    return false;
}

bool    tryCastCPtr(Base *p)
{
    if (dynamic_cast<C*>(p))
        return true;
    return false;
}
