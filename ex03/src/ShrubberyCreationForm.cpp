#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
					 : AForm("ShrubberyCreationForm", 145, 137),
					   _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
					 : AForm(other),
					 _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::_executeAction() const
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file;

	file.open(fileName.c_str(),
	          std::ofstream::binary | std::ofstream::trunc);
	if (!file.is_open() || !file.good())
		throw AForm::FormException("Couldn't open the file: " + this->_target + "_shrubbery");
	
    const char* tree =
        "      ^\n"
        "     ^^^\n"
        "    ^^^^^       ^\n"
        "   ^^^^^^^     ^^^\n"
        "  ^^^^^^^^^   ^^^^^\n"
        " ^^^^^^^^^^^ ^^^^^^^\n";
	file << tree;
}