#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& nam, double grad) : name(nam), grade(grad)
{
    if (grad < 1)
        throw std::out_of_range("Grade too high");
    if (grad > 150)
        throw std::out_of_range("Grade too low");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

double Bureaucrat::getGrade() const
{
    return grade;
}


void Bureaucrat::setGrade(double grad)
{
    if (grad < 1)
        throw (GradeTooHighException());
    if (grad > 150)
        throw (GradeTooLowException());
    grade = grad;
}

void Bureaucrat::incrementGrade()
{
    try {
        setGrade(grade - 1);
    }
    catch (const std::exception& e) {
        throw;
    }
}

void Bureaucrat::decrementGrade()
{
    try {
        setGrade(grade + 1);
    }
    catch (const std::exception& e) {
        throw;
    }
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low exception";
}
