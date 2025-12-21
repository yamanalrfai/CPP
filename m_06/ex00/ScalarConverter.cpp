#include "ScalarConverter.hpp"
#include <iostream>
#include <errno.h>
#include <limits>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

bool ispseudo(const std::string& str) {
    return (str == "nan" || str == "+inf" || str == "-inf" ||
            str == "nanf" || str == "+inff" || str == "-inff");
}

bool ischar(const std::string& str) {
    return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool isfloat(const std::string& str) {
    int i = 0;
    int minusCount = 0;
    while (i < str.size() && (str[i] == '+' || str[i] == '-')) {
        i++;
    }
    bool hasDigits = false;
    while (i < str.size() && isdigit(str[i])) {
        i++;
        hasDigits = true;
    }
    if (i < str.size() && str[i] == '.') {
        i++;
        while (i < str.size() && isdigit(str[i])) {
            i++;
            hasDigits = true;
        }
    }
    if (i < str.size() && str[i] == 'f') {
        i++;
    }
    return (hasDigits && i == str.size());
}

bool isdouble(const std::string& str) {
    int i = 0;
    while (i < str.size() && (str[i] == '+' || str[i] == '-')) {
        i++;
    }
    bool hasDigits = false;
    while (i < str.size() && isdigit(str[i])) {
        i++;
        hasDigits = true;
    }
    if (i < str.size() && str[i] == '.') {
        i++;
        while (i < str.size() && isdigit(str[i])) {
            i++;
            hasDigits = true;
        }
    }
    return (hasDigits && i == str.size());
}

void ScalarConverter::convert(std::string& input) {
    if (input.size() == 0) {
        std::cout << "Error: Empty input." << std::endl;
    }
    else if (ispseudo(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input[input.size() - 1] == 'f') {
            input.pop_back();
        }
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
    else if (ischar(input)) {
        std::cout << "char: " << input[1] << std::endl;
        std::cout << "int: " << static_cast<int>(input[1]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[1]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(input[1]) << std::endl;
    }
    else if (isfloat(input)) {
        float fvalue = std::strtof(input.c_str(), nullptr);
        if (errno == ERANGE) {
            std::cout << "Error: Float value out of range." << std::endl;
            return;
        }
        std::cout << "char: ";
        if (isprint(fvalue) && fvalue == static_cast<int>(fvalue))
            std::cout << static_cast<char>(fvalue) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (fvalue < std::numeric_limits<int>::min() || fvalue > std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(fvalue) << std::endl;  
        else
            std::cout << "int: impossible" << std::endl;
        if (fvalue < -std::numeric_limits<float>::max() || fvalue > std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << fvalue << "f" << std::endl;
        if (fvalue < -std::numeric_limits<double>::max() || fvalue > std::numeric_limits<double>::max())
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(fvalue) << std::endl;
    }
    else if (isdouble(input)) {
        double dvalue = std::strtod(input.c_str(), nullptr);
        if (errno == ERANGE) {
            std::cout << "Error: Double value out of range." << std::endl;
            return;
        }
        std::cout << "char: ";
        if (isprint(dvalue) && dvalue == static_cast<int>(dvalue))
            std::cout << static_cast<char>(dvalue) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (dvalue < std::numeric_limits<int>::min() || dvalue > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
        if (dvalue < -std::numeric_limits<float>::max() || dvalue > std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
        std::cout << "double: " << dvalue << std::endl;
    }
    else {
        char *endptr;
        int ivalue = std::strtol(input.c_str(), &endptr, 10);
        if (errno == ERANGE) {
            std::cout << "Error: Integer value out of range." << std::endl;
            return;
        }
        if (*endptr != '\0') {
            std::cout << "Error: Invalid input." << std::endl;
            return;
        }
        std::cout << "char: ";
        if (isprint(ivalue))
            std::cout << static_cast<char>(ivalue) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (ivalue < std::numeric_limits<int>::min() || ivalue > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << ivalue << std::endl;
        if (ivalue < -std::numeric_limits<float>::max() || ivalue > std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(ivalue) << "f" << std::endl;
        if (ivalue < -std::numeric_limits<double>::max() || ivalue > std::numeric_limits<double>::max())
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(ivalue) << std::endl; 
    }
}
