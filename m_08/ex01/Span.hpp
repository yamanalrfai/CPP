#pragma once
#include <vector>
#include <climits>
#include <set>
#include <stdexcept>
class Span
{
private:
    std::multiset<int> s;
    unsigned int n;
    Span();
public:
    ~Span();
    Span(unsigned int N);
    Span(const Span &N);
    Span &operator=(const Span);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    class FullSize : public std::exception
    {
    public:
		virtual const char* what() const throw();
    };
    class NoSpan : public std::exception
    {
    public:
		virtual const char* what() const throw();
    };
};
