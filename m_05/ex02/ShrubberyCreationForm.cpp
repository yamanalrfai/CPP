#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targ) : AForm("ShrubberyCreationForm", 145, 137), target(targ)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();
    
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not create file");
    
    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    
    file.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
    os << "ShrubberyCreationForm: " << form.getName() 
       << " (signed: " << (form.getSign() ? "yes" : "no")
       << ", sign grade: " << form.getRequire()
       << ", exec grade: " << form.getExecute() << ")";
    return os;
}
