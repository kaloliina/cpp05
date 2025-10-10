#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

class AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	int match = -1;
	std::string strings[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm* form;
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
			throw FormNotFoundException();
		}
		case 0:
		{
			form = new ShrubberyCreationForm(formTarget);
			break ;			
		}
		case 1:
		{
			form = new RobotomyRequestForm(formTarget);
			break ;			
		}
		case 2:
		{
			form = new PresidentialPardonForm(formTarget);
			break ;			
		}
	}
	return form;
}

const char* Intern::FormNotFoundException::what() const noexcept
{
	return "Form does not exist";
}
