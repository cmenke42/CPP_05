#include "Bureaucrat.hpp"

#include <ostream>

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

/**
 * @throws Bureaucrat::GradeTooHighException -> If the grade is less than 1.
 * @throws Bureaucrat::GradeTooLowException -> If the grade is greater than 150.
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/**
 * @brief 
 * 
 * @throws Bureaucrat::GrdeTooHighException -> if resulting grade is less than 1 OR input < 0.
 
 */
void Bureaucrat::incrementGrade(int number)
{
	if (number < 0 || number > 150 || number >= this->_grade)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= number;
}

/**
 * @brief 
 * 
 * @throws Bureaucrat::GradeTooLowException -> if resulting grade is greater than 150 OR input < 0.
 */
void Bureaucrat::decrementGrade(int number)
{
	if (number < 0 || number > 150 || this->_grade + number > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += number;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName()
     << ", bureaucrat grade "
	 	 << obj.getGrade();
    return os;
}
