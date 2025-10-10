#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
//again not sure if needed
// ShrubberyCreationForm::ShrubberyCreationForm()
// {

// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}
//Skip for now
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw GradeTooHighException(); // really this should form not signed exception
	if (executor.getGrade() <= this->getGradeExec()) //dont remember if it was okay as even
	{
		std::string FileName = this->_target + "_shrubbery";
		std::ofstream File(FileName);
		if (File.is_open() == false)
		{
			throw GradeTooHighException();
			//I guess we need an exception for this one as well
		}
		File << "Behold, a beautiful tree!" << std::endl;
		//insert actual tree here...
		File.close();
	}
	else
		throw GradeTooLowException();
}

// void RobotomyRequestForm::execute(Bureaucrat const& executor) const
// {
// 	if (getSignstatus() == false)
// 		throw GradeTooHighException(); // really this should form not signed exception
// 	if (executor.getGrade() <= this->getGradeExec()) //dont remember if it was okay as even
// 	{
// 		std::cout << "BRRRRRRR" << std::endl;
// 		if (rand() % 2 == 0)
// 			std::cout << _target << " has been succesfully robotomized!" << std::endl;
// 		else
// 			std::cout << "robotomy unfortunately failed" << std::endl; //Is this considered an error..?
		
// 	}
// 	else
// 		throw GradeTooLowException();
// }

// void PresidentialPardonForm::execute(Bureaucrat const& executor) const
// {
// 	if (getSignstatus() == false)
// 		throw GradeTooHighException(); // really this should form not signed exception
// 	if (executor.getGrade() <= this->getGradeExec()) //dont remember if it was okay as even
// 	{
// 		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
// 	}
// 	else
// 		throw GradeTooLowException();
// }
