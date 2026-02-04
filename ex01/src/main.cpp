
#include "../include/Form.hpp"

int main(void)
{
	std::cout << "--------Form Sign Requirement too high test--------" << std::endl;
	try
	{
		Form form("Important", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Form Sign Requirement too low test--------" << std::endl;
	try
	{
		Form form("Important", 151, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Form Execute Requirement too high test--------" << std::endl;
	try
	{
		Form form("Important", 50, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Form Execute Requirement too low test--------" << std::endl;
	try
	{
		Form form("Important", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Regular Form Test--------" << std::endl;
	try
	{
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Succesful sign Test--------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Karoliina", 50);
		std::cout << bureaucrat << std::endl;
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Succesful sign Test--------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Karoliina", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Failed sign Test--------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Karoliina", 51);
		std::cout << bureaucrat << std::endl;
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Multiple sign Test--------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Karoliina", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Multiple Failed sign Test--------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Karoliina", 51);
		std::cout << bureaucrat << std::endl;
		Form form("Important", 50, 50);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}