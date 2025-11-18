#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>


class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);
        const std::string& getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        ~Bureaucrat();
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
