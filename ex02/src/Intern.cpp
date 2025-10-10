#include "../include/Intern.hpp"

// Intern() = delete;
// 	Intern(std::string name, int grade);
// 	Intern(const Intern& copy);
// 	Intern &operator=(const Intern& src) = delete;
// 	~Intern() = default;

class Form* Intern::makeForm(std::string formName, std::string formTarget)
{
	int match = -1;
	std::string strings[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(strings[i]) == 0)
		{
			match = i;
			break;
		}
	}
	switch (match)
	{
		case -1:
		{
			//THROW ERROR
		}
		case 0:
		{
			AForm* form = new ShrubberyCreationForm(formTarget);
			break ;			
		}
		case 1:
		{
			AForm* form = new RobotomyRequestForm(formTarget);
			break ;			
		}
		case 2:
		{
			AForm* form = new PresidentialPardonForm(formTarget);
			break ;			
		}
	}
}
