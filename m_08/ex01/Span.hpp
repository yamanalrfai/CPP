#pragma once
#include <vector>
#include <climits>
class Span
{
private:
    int mi = INT_MAX;
    int ma = INT_MIN;
    unsigned int n;
    unsigned int i = 0;
    Span();
public:
    ~Span();
    Span(unsigned int N);
    Span &operator=(const Span);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    int size();
    int getI();
    int setI();
    
};
