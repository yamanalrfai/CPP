#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);

        std::cout << bob << std::endl;

        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();

        std::cout << "After grade increment:" << std::endl;
        std::cout << bob << std::endl;
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
        charlie.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test exception: invalid grade in constructor
        Bureaucrat invalid("Invalid", 151); // This should throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
