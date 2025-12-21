#pragma once

class Base {
    public:
    virtual ~Base();
};
void identify(Base* p);
void identify(Base& p);
Base * generate(void);