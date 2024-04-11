#include "Bureaucrat.hpp"

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "colors.h"

int main(void)
{
	Intern someRandomIntern;
	AForm* tree = NULL;
	AForm* robot = NULL;
	AForm* president = NULL;

	try
	{
		tree = someRandomIntern.makeForm("shrubbery creation", "treeTarget");
		robot = someRandomIntern.makeForm("robotomy request", "robotTarget");
		president = someRandomIntern.makeForm("presidential pardon", "presidentTarget");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		delete tree;
		delete robot;
		return 1;
	}

	Bureaucrat	max("max", 1);

	std::cout << RED << *tree << RESET << std::endl;
	std::cout << RED << *robot << RESET << std::endl;
	std::cout << RED << *president << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << max << RESET << "\n";
	max.signForm(*tree);
	max.signForm(*robot);
	max.signForm(*president);
	std::cout << std::endl;

	std::cout << RED << *tree << RESET << std::endl;
	std::cout << RED << *robot << RESET << std::endl;
	std::cout << RED << *president << RESET << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	max.executeForm(*tree);
	std::cout << std::endl;
	max.executeForm(*robot);
	std::cout << std::endl;
	max.executeForm(*president);
	std::cout << std::endl;

	delete tree;
	delete robot;
	delete president;

	try
	{
		AForm* invalidForm = someRandomIntern.makeForm("invalid form", "invalidTarget");
		(void)invalidForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}