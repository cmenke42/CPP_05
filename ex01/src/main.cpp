#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat	max("max", 50);
	Form				buyComputer("buyComputer", 49, 60);
	Form				buyCar("buyCar", 51, 60);	

	try
	{
		std::cout << "Trying to create: invalidForm(invalidForm, 0, 0)" << std::endl;
		Form invalidForm("invalidForm", 0, 0);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "Trying to create: invalidForm(invalidForm, 151, 0)" << std::endl;
		Form invalidForm("invalidForm", 151, 0);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	max.signForm(buyComputer);
	std::cout << std::endl;

	max.signForm(buyCar);
	std::cout << std::endl;
	return (0);
}