#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeExec()) //dont remember if it was okay as even
	{
		std::cout << "BRRRRRRR" << std::endl;
		if (rand() % 2 == 0)
			std::cout << _target << " has been succesfully robotomized!" << std::endl;
		else
			std::cout << "Robotomy unfortunately failed" << std::endl;
	}
	else
		throw GradeTooLowException();
}
