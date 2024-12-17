#ifndef ARRAY_HPP
# define ARRAY_HPP

template<class T>
class Array
{
    private:
        T   *_container;
        int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& ar);

        ~Array();

        T&  operator=(const Array &ar);
        T&  operator[](int i);
        const T&  operator[](int i) const;

        int size() const;
};

#endif