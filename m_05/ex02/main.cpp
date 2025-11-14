#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 45, 30);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm, "insufficient grade");

        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();

        std::cout << "After grade increment:" << std::endl;
        std::cout << bob << std::endl;

        bob.signForm(taxForm, "insufficient grade");

        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
