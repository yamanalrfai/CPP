#pragma once
#include <string>

class ScalarConverter {
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    static void convert(std::string& literal);
};