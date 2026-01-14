#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(){

}

Span::Span(unsigned int N){
    n = N;
}

Span::~Span() {

}

Span &Span::operator=(const Span o){
    if (this != &o)
    {
        this->n = o.n;
        this->s = o.s;
    }
    return *this;
}

Span::Span(const Span &o){
    *this = o;
}

void Span::addNumber(int num){
    if (this->s.size() == n) {
        throw FullSize();
    }
    s.insert(num);
}

int Span::shortestSpan(){
    if (this->s.size() <= 1) {
        throw NoSpan();
    }
    std::vector<int> ans;
    std::multiset<int>::iterator it1 = this->s.begin(), it2 = this->s.begin();
    it1++;
    while (it1 != this->s.end()){
        ans.push_back(*it1 - *it2);
        it1++;
        it2++;
    }
    std::sort(ans.begin(), ans.end());
    return (ans[0]);
}

int Span::longestSpan() {
    if (this->s.size() <= 1) {
        throw NoSpan();
    }
    return (*this->s.rbegin() - *this->s.begin());
}

void Span::addNumber(std::vector<int>::iterator be, std::vector<int>::iterator en){
    while (be < en)
    {
        addNumber(*be);
        be++;
    }
}

const char* Span::FullSize::what() const throw() {
    return ("The Span is full");
}

const char* Span::NoSpan::what() const throw() {
    return ("You need two element to find the Sapn");
}
