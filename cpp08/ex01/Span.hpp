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
        int shortestSpan();
        int longestSpan();

        int getSize() const;
};

#endif