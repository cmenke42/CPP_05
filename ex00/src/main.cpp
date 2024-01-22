#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat one("Blender", 23);
	Bureaucrat two("Fender", 22);

	try 
	{
		Bureaucrat three("Fender", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat four("Fender", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << one << std::endl;
	std::cout << two << std::endl;
	
	one = two;

	std::cout << one << std::endl;
	std::cout << two << std::endl;
}