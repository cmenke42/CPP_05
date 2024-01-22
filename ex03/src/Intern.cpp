#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::FormNotFound::FormNotFound(const std::string& message)
					 : _message(message)
{
}

Intern::FormNotFound::~FormNotFound() throw() {}

const char*	Intern::FormNotFound::what() const throw()
{
	return (this->_message.c_str());
}

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

Intern::~Intern() {}

const std::string			Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const Intern::_FormCreator	Intern::_formCreators[3] = {
	&Intern::_makeShrubberyCreationForm,
	&Intern::_makeRobotomyRequestForm,
	&Intern::_makePresidentialPardonForm
};

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == Intern::_formNames[i])
			return ((this->*Intern::_formCreators[i])(target));
	}
	throw Intern::FormNotFound("Form: \"" + formName + "\" not found.");
	return (NULL);
}

AForm*	Intern::_makeShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_makeRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_makePresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}
