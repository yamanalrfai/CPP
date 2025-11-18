#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form() : name("Default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::~Form()
{
}

Form::Form(const std::string& nam, int req, int exe) : name(nam), sign(false), gradeToSign(req), gradeToExecute(exe)
{
    if (req < 1 || exe < 1)
        throw GradeTooHighException();
    if (req > 150 || exe > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
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
    if (bureaucrat.getGrade() > gradeToSign)
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

int Form::getRequire() const
{
    return gradeToSign;
}

int Form::getExecute() const
{
    return gradeToExecute;
}

