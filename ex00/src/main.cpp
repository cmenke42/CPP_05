#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat one("Bone", 23);
	Bureaucrat two("Btwo", 22);

	try 
	{
		Bureaucrat three("Bthree", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat four("Bfour", 151);
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

	std::cout << "\ntesting incrementGrade and decrementGrade." << std::endl;
	std::cout << "Starting with: " << one << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Incrementing grade by 2." << std::endl;
		one.incrementGrade(2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << one << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Incrementing grade by 150." << std::endl;
		one.incrementGrade(150);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << one << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Decrementing grade by 2." << std::endl;
		one.decrementGrade(2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << one << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Decrementing grade by -2." << std::endl;
		one.decrementGrade(-2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << one << std::endl;

	return (0);
}