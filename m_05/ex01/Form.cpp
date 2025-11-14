#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form() : name("Default"), sign(false), require(150), execute(150)
{
}

Form::~Form()
{
}

Form::Form(const std::string& nam, double req, double exe) : name(nam), sign(false), require(req), execute(exe)
{
    if (req < 1 || exe < 1)
        throw GradeTooHighException();
    if (req > 150 || exe > 150)
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > require)
        throw GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form Name: " << form.getName() << std::endl;
    os << "Signed: " << (form.getSign() ? "Yes" : "No") << std::endl;
    return os;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

double Form::getRequire() const
{
    return require;
}

double Form::getExecute() const
{
    return execute;
}

