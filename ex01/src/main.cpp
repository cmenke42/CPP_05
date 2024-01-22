#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat	max("max", 50);
	Form		buyComputer("buyComputer", 49, 60);

	max.signForm(buyComputer);
}