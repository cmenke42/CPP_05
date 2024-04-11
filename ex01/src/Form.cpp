#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <ostream>

Form::FormException::FormException()
					 : _message("Form exception")
{
}

Form::FormException::FormException(const std::string& message)
					 : _message(message)
{
}

Form::FormException::~FormException() throw() {}

const char*	Form::FormException::what() const throw()
{
	return (this->_message.c_str());
}

Form::GradeTooHighException::GradeTooHighException()
						   : FormException("Grade too high")
{
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message)
						   : FormException(message)
{
}

Form::GradeTooLowException::GradeTooLowException()
						   : FormException("Grade too low")
{
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message)
						   : FormException(message)
{
}

/**
 * @throws Form::GradeTooHighException -> If the gradeToSign or gradeToExecute is less than 1.
 * @throws Form::GradeTooLowException -> If the gradeToSign or gradeToExecute is greater than 150.
 */
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException("GradeToSign is too high");
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException("GradeToSign is too low");
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException("GradeToExecute is too high");
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException("GradeToExecute is too low");
}

Form::Form(const Form& other)
	: _name(other._name),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return (this->_name);
}

bool Form::isSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/**
 * @throws Form::GradeTooLowException -> If the bureaucrat's grade is not high enough.
 */
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException(); 
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Form: " << obj.getName()
	 << ", Signed: " << std::boolalpha << obj.isSigned()
	 << ", GradetoSign: " << obj.getGradeToSign()
	 << ", GradeToExecute: " << obj.getGradeToExecute();
	return (os);
}
