#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

/*rand generates "random numbers" and if it's never set, the compiler uses a default setting,
meaning the outcome is always the same.
That's why we need srand because that sets the starting point for the number generator.*/
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeExec())
	{
		std::cout << "BRRRRRRR" << std::endl;
		std::srand(std::time(nullptr));
		if (rand() % 2 == 0)
			std::cout << _target << " has been succesfully robotomized!" << std::endl;
		else
			std::cout << "Robotomy unfortunately failed" << std::endl;
	}
	else
		throw GradeTooLowException();
}
