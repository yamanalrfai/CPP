#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::string x = "dsfsf";
    std::cout << "Address str = " << &str << std::endl;
    std::cout << "Address stringPTR = " << stringPTR << std::endl;
    std::cout << "Address stringREF = " << &stringREF << std::endl;
    std::cout << "Value str = " << str << std::endl;
    std::cout << "Value pointed to by stringPTR = " << *stringPTR << std::endl;
    std::cout << "Value referred to by stringREF = " << stringREF << std::endl;
    return 0;
}