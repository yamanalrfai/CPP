#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>
#include "Form.hpp"


class Bureaucrat
{
    private:
        const std::string name;
        double grade;
    public:
        Bureaucrat(const std::string& name, double grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);
        const std::string& getName() const;
        double getGrade() const;
        void setGrade(double grade);
        void incrementGrade();
        void decrementGrade();
        ~Bureaucrat();
        void signForm(Form& formName, const std::string& reason);
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
