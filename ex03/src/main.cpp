#include "Bureaucrat.hpp"

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{

	Intern someRandomIntern;
	AForm* rrf = NULL;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	Bureaucrat	max("max", 149);
	// ShrubberyCreationForm tree("testing");

	// AForm* tree = new PresidentialPardonForm("testing");

	max.signForm(*rrf);
	max.executeForm(*rrf);
	
	delete rrf;
	// AForm		buyComputer("buyComputer", 49, 60);

	// max.signForm(buyComputer);

	// std::cout << buyComputer << std::endl;
}