#include "../include/Bureaucrat.hpp"

int main(void)
{
	try {
	Bureaucrat buddy("karo", 1);
	std::cout << buddy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

