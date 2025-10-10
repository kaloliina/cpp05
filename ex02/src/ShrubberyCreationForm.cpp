#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeExec()) //dont remember if it was okay as even
	{
		std::string FileName = this->_target + "_shrubbery";
		std::ofstream File(FileName);
		if (File.is_open() == false)
			throw FileFailureException();
		File << "Behold, a beautiful tree!" << std::endl;
		//insert actual tree here...
		File.close();
	}
	else
		throw GradeTooLowException();
}

//review
const char* ShrubberyCreationForm::FileFailureException::what() const noexcept
{
	return "Failed to open file";
}
