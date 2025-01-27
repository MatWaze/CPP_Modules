#ifndef SPAN_HPP
# define SPAN_HPP

class   Span
{
    private:
        int *_list;
        int _size;
        int _counter;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &sp);
        ~Span();

        Span  &operator=(const Span &sp);

        void    addNumber(int num);
        
        template<typename Iter>
        void    addRange(Iter begin, Iter end);
        
        int shortestSpan();
        int longestSpan();

        int getSize() const;
        int getCounter() const;
};

template<typename Iter>
void    Span::addRange(Iter begin, Iter end)
{
    for (Iter it = begin; it != end; it++)
        this->addNumber(*it);
}

#endif