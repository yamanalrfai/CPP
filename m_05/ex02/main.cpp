#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");

        std::cout << bob << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << alice << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << president << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Execution without signing ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 1);
        PresidentialPardonForm pardon2("Ford Prefect");

        std::cout << charlie << std::endl;
        charlie.executeForm(pardon2);  // Should fail - not signed
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat lowGrade("LowGrade", 50);
        PresidentialPardonForm pardon3("Zaphod");

        std::cout << lowGrade << std::endl;
        lowGrade.signForm(pardon3);  // Should fail - grade too low
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
