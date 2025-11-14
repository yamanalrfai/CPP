#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const double require;
        const double execute;
    public:
        Form();
        Form(const std::string& name, double require, double execute);
        ~Form();
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName() const;
        bool getSign() const;
        double getRequire() const;
        double getExecute() const;
};
std::ostream& operator<<(std::ostream& os, const Form& form);
