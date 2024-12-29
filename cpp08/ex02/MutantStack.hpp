#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
struct  Iterator
{
    Iterator();
    Iterator(const Iterator &it);
    Iterator(T* dq);

    Iterator    &operator=(const Iterator &it);
    Iterator    &operator++();
    Iterator    &operator--();

    Iterator    operator++(int);
    Iterator    operator--(int);

    bool    operator==(const Iterator &it) const;
    bool    operator!=(const Iterator &it) const;
    bool    operator>(const Iterator &it) const;
    bool    operator>=(const Iterator &it) const;
    bool    operator<(const Iterator &it) const;
    bool    operator<=(const Iterator &it) const;

    T    operator*() const;

    private:
        T   *_dq;
};

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef Iterator<T> iterator;
    
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &mt);

        MutantStack  operator=(const MutantStack &mt);

        Iterator<T> begin();
        Iterator<T> end();
};

#endif