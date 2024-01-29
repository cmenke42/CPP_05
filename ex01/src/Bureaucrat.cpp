#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"

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
Bureaucrat::Bureaucrat(const std::string& name, int grade)
          : _name(name),
		    _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << this->_name
		 << " couldn't sign "
		 << form.getName()
		 << " because "
		 << e.what()
		 << std::endl;
		 return;
	}
	std::cout << this->_name
	 << " signed "
	 << form.getName()
	 << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName()
     << ", bureaucrat grade "
	 << obj.getGrade();
    return os;
}
