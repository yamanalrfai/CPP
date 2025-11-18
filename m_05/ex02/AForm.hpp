#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name, int require, int execute);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName() const;
        bool getSign() const;
        int getRequire() const;
        int getExecute() const;
        virtual void execute(const Bureaucrat& executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& form);
