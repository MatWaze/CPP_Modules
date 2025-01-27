#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <algorithm>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <list>

void    print(int i)
{
    std::cout << i << "\n";
}

TEST_CASE("Checking std::list and MutantStack's outputs (taken from subject)")
{
    {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::string out = oss.str();
    std::cout.rdbuf(oldBuf);

    std::list<int> lis;
    lis.push_back(5);
    lis.push_back(17);

    std::streambuf* oldBuf2 = std::cout.rdbuf();
    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    std::cout << lis.back() << std::endl;
    lis.pop_back();
    std::cout << lis.size() << std::endl;
    lis.push_back(3);
    lis.push_back(5);
    lis.push_back(737);
    lis.push_back(0);

    std::list<int>::iterator it1 = lis.begin();
    std::list<int>::iterator ite1 = lis.end();

    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    
    std::string out2 = oss2.str();
    std::cout.rdbuf(oldBuf2);

    CHECK_EQ(out, out2);
    }
}

TEST_CASE("Testing iterator class")
{
    MutantStack<int>    mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int>::iterator  beg = mstack.begin();
    MutantStack<int>::iterator  en = mstack.end();

    MutantStack<int>::iterator  last = --en;

    // postfix - return value unchanged
    MutantStack<int>::iterator  last2 = en++;

    // first and before the end iterators
    CHECK_EQ(*beg, 1);
    CHECK_EQ(*last, 3);

    CHECK(last == last2);
    CHECK(beg < last);
    CHECK(last > beg);
    CHECK(beg == mstack.begin());
    CHECK(en == mstack.end());
    CHECK(last >= --mstack.end());
    CHECK(beg >= mstack.begin());

    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    for (MutantStack<int>::iterator i = beg; i != en; i++)
        std::cout << *i << std::endl;
    
    std::for_each(beg, en, print);

    std::string out = oss.str();
    std::cout.rdbuf(oldBuf);

    CHECK_EQ(out, "1\n2\n3\n1\n2\n3\n");

    beg++;
    en--;

    CHECK(beg-- != mstack.begin());
    CHECK(beg == mstack.begin());

    CHECK(en++ != mstack.end());
    CHECK(en == mstack.end());

    mstack.pop();
    mstack.push(4);

    MutantStack<int>::iterator  newLast = --mstack.end();
    
    CHECK_EQ(*newLast, 4);

    CHECK(beg == mstack.begin());
    CHECK(en == mstack.end());
    CHECK_EQ(*beg, 1);
    CHECK_EQ(*--en, 4);
}

TEST_CASE("Testing MutantStack")
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(-4435);
    mstack.push(737);
    mstack.push(-1);
    mstack.push(1);
    mstack.push(10000);

    MutantStack<int>    mstack2 = mstack;

    MutantStack<int>    mstack3;

    mstack3.push(1);
    mstack3.push(2);
    mstack3.push(3);

    CHECK_NE(mstack, mstack3);

    mstack3 = mstack2;

    CHECK_EQ(mstack, mstack3);

    CHECK_EQ(mstack, mstack2);

    CHECK_EQ(mstack.size(), 6);
    CHECK_EQ(mstack.top(), 10000);

    mstack.pop();

    CHECK_EQ(mstack.size(), 5);
    CHECK_EQ(mstack.top(), 1);

    CHECK_EQ(*mstack.begin(), 5);
    CHECK_EQ(*--mstack.end(), 1);
}

TEST_CASE("String MutantStack")
{
    MutantStack<std::string>    st;

    st.push("abc");
    st.push("def");
    st.push("gh");
    st.push("ij");
    st.push("klmn");

    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    for (MutantStack<std::string>::iterator it = st.begin(); it != st.end(); it++)
        std::cout << *it;

    std::string out = oss.str();
    std::cout.rdbuf(oldBuf);

    CHECK_EQ(out, "abcdefghijklmn");

    st.pop();

    std::ostringstream oss2;
    oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    for (MutantStack<std::string>::iterator it = st.begin(); it != st.end(); it++)
        std::cout << *it;

    std::string out2 = oss2.str();
    std::cout.rdbuf(oldBuf);

    CHECK_EQ(out2, "abcdefghij");
    
    MutantStack<std::string>::iterator it = ++(st.begin());

    CHECK_EQ(*it, "def");
    CHECK_EQ(*--it, "abc");
}