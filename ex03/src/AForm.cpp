#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <ostream>

AForm::FormException::FormException()
					 : _message("AForm exception")
{
}

AForm::FormException::FormException(const std::string& message)
					 : _message(message)
{
}

AForm::FormException::~FormException() throw() {}

const char*	AForm::FormException::what() const throw()
{
	return (this->_message.c_str());
}

AForm::GradeTooHighException::GradeTooHighException()
						   : FormException("Grade too high")
{
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message)
						   : FormException(message)
{
}

AForm::GradeTooLowException::GradeTooLowException()
						   : FormException("Grade too low")
{
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
						   : FormException(message)
{
}

/**
 * @throws AForm::GradeTooHighException -> If the gradeToSign or gradeToExecute is less than 1.
 * @throws AForm::GradeTooLowException -> If the gradeToSign or gradeToExecute is greater than 150.
 */
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException("GradeToSign is too high");
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException("GradeToSign is too low");
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException("GradeToExecute is too high");
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException("GradeToExecute is too low");
}

AForm::AForm(const AForm& other)
	: _name(other._name),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return (this->_name);
}

bool AForm::isSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/**
 * @throws AForm::GradeTooHighException -> If the gradeToSign or gradeToExecute is less than 1.
 * @throws AForm::GradeTooLowException -> If the gradeToSign or gradeToExecute is greater than 150.
 */
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw AForm::FormException("is already signed");
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException(); 
}

/**
 * @throws AForm::FormException -> If the form is not signed.
 * @throws AForm::GradeTooLowException -> If the bureaucrat's grade is greater than the gradeToExecute.
 */
void AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw AForm::FormException("Is not signed");
	if (executor.getGrade() <= this->_gradeToExecute)
		_executeAction();
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "Form: " << obj.getName()
	 << ", Signed: " << std::boolalpha << obj.isSigned()
	 << ", GradetoSign: " << obj.getGradeToSign()
	 << ", GradeToExecute: " << obj.getGradeToExecute();
	return (os);
}
