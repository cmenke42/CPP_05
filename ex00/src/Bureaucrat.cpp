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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName()
     << ", bureaucrat grade "
	 << obj.getGrade();
    return os;
}
