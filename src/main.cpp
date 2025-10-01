#include "../include/Bureaucrat.hpp"

int main(void)
{
	try {
	Bureaucrat buddy("karo", 0);
	if (buddy.getGrade() < 1)
	{
		throw Bureaucrat();
	}
	}
	catch (const Bureaucrat& e)
	{
		std::cout << "e.whaaaaaat();";
	}

}

