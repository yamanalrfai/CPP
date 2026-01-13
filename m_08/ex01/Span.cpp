#include <Span.hpp>
#include <stdexcept>

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
    if (this->s.size() != n) {
        s.insert(num);
    }
    else {
        throw FullSize();
    }
}

const char* Span::FullSize::what() const {
    return ("The Span is full");
}

const char* Span::NoSpan::what() const {
    return ("You need two element to find the Sapn");
}
