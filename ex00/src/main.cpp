
#include "../include/Bureaucrat.hpp"

int main(void)
{
	std::cout << "--------Regular test--------" << std::endl;
	try
	{
		Bureaucrat person1("Twilight Sparkle", 20);
		Bureaucrat person2(person1); //copy constructor check
		std::cout << person1 << std::endl; //overload operator
		std::cout << person2 << std::endl;
		person1.decrementGrade();
		person2.incrementGrade();
		std::cout << person1 << std::endl;
		std::cout << person2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Grade too high test--------" << std::endl;
	try
	{
		Bureaucrat person1("Pinkie Pie", 1);
		std::cout << person1 << std::endl;
		person1.incrementGrade();
		person1.incrementGrade(); //we should not get here because error is thrown already
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Initial grade too high test--------" << std::endl;
	try
	{
		Bureaucrat person1("Raindow Dash", 0);
		std::cout << person1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Initial grade too low test--------" << std::endl;
	try
	{
		Bureaucrat person1("Spike", 151);
		std::cout << person1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Grade too low test--------" << std::endl;
	try
	{
		Bureaucrat person1("Rarity", 148);
		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Negative number test--------" << std::endl;
	try
	{
		Bureaucrat person1("Applejack", -8);
		std::cout << person1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
