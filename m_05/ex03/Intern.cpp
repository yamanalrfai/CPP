#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (*formCreators[])(const std::string&) = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPresidentialForm
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
