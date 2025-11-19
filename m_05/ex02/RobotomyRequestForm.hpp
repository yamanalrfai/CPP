#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    
    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);
