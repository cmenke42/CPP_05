#include "Bureaucrat.hpp"

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	max("max", 6);
	// ShrubberyCreationForm tree("testing");

	AForm* tree = new PresidentialPardonForm("testing");

	max.signForm(*tree);
	max.executeForm(*tree);
	
	// AForm		buyComputer("buyComputer", 49, 60);

	// max.signForm(buyComputer);

	// std::cout << buyComputer << std::endl;
}