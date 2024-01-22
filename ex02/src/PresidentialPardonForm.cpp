#include "PresidentialPardonForm.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
					 : AForm("PresidentialPardonForm", 25, 5),
					   _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
					 : AForm(other),
					 _target(other._target)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::_executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
