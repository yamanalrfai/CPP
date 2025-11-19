#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targ) : AForm("RobotomyRequestForm", 72, 45), target(targ)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();
    
    std::cout << "* Drilling noises *" << std::endl;
    
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
    os << "RobotomyRequestForm: " << form.getName() 
       << " (signed: " << (form.getSign() ? "yes" : "no")
       << ", sign grade: " << form.getRequire()
       << ", exec grade: " << form.getExecute() << ")";
    return os;
}
