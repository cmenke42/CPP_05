#include "RobotomyRequestForm.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
					 : AForm("RobotomyRequestForm", 72, 45),
					   _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
					 : AForm(other),
					 _target(other._target)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::_executeAction() const
{
	std::cout << "━━━*:･ﾟ✧ BZZZZZZZZZ *:･ﾟ✧" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
