#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm() : name("Default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::~AForm()
{
}

AForm::AForm(const std::string& nam, int req, int exe) : name(nam), sign(false), gradeToSign(req), gradeToExecute(exe)
{
    if (req < 1 || exe < 1)
        throw GradeTooHighException();
    if (req > 150 || exe > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Exception: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Exception: Grade too low";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
    os << "AForm Name: " << Aform.getName() << std::endl;
    os << "Signed: " << (Aform.getSign() ? "Yes" : "No") << std::endl;
    return os;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

int AForm::getRequire() const
{
    return gradeToSign;
}

int AForm::getExecute() const
{
    return gradeToExecute;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

