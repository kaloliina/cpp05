#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeExec())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
	}
	else
		throw GradeTooLowException();
}
