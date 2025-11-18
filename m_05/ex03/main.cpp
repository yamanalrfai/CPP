#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Intern creates shrubbery creation form ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("shrubbery creation", "garden");
        
        Bureaucrat bob("Bob", 137);
        bob.signForm(*form);
        bob.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Intern creates robotomy request form ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        
        Bureaucrat alice("Alice", 40);
        alice.signForm(*form);
        alice.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Intern creates presidential pardon form ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        
        Bureaucrat president("President", 1);
        president.signForm(*form);
        president.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Intern fails to create unknown form ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("unknown form", "target");
        
        delete form;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Multiple interns creating different forms ===" << std::endl;
    try {
        Intern intern1;
        Intern intern2;
        Intern intern3;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "home");
        AForm* form2 = intern2.makeForm("robotomy request", "Marvin");
        AForm* form3 = intern3.makeForm("presidential pardon", "Ford Prefect");
        
        Bureaucrat boss("Boss", 1);
        
        boss.signForm(*form1);
        boss.executeForm(*form1);
        
        boss.signForm(*form2);
        boss.executeForm(*form2);
        
        boss.signForm(*form3);
        boss.executeForm(*form3);
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
