#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.h"

int main(void)
{
	Bureaucrat	max("max", 1);
	Bureaucrat	min("min", 150);

	ShrubberyCreationForm tree("tree");
	RobotomyRequestForm robot("robot");
	PresidentialPardonForm president("president");

	std::cout << RED << tree << RESET << std::endl;
	std::cout << RED << robot << RESET << std::endl;
	std::cout << RED << president << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << max << RESET << "\n";
	max.signForm(tree);
	max.signForm(robot);
	max.signForm(president);
	std::cout << std::endl;

	std::cout << RED << tree << RESET << std::endl;
	std::cout << RED << robot << RESET << std::endl;
	std::cout << RED << president << RESET << std::endl;
	std::cout << std::endl;

	max.executeForm(tree);
	std::cout << std::endl;
	max.executeForm(robot);
	std::cout << std::endl;
	max.executeForm(president);
	std::cout << std::endl;
	std::cout << std::endl;

// ---------------------
	std::cout << BLUE << min << RESET << "\n";
	min.signForm(tree);
	min.signForm(robot);
	min.signForm(president);
	std::cout << std::endl;

	min.executeForm(tree);
	min.executeForm(robot);
	min.executeForm(president);
	std::cout << std::endl;

// ------------------------

	AForm* treePtr = new PresidentialPardonForm("testing");

	std::cout << RED << *treePtr << RESET << std::endl;

	max.executeForm(*treePtr);

	delete treePtr;
}
