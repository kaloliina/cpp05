#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (getSignstatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeExec())
	{
		std::string FileName = this->_target + "_shrubbery";
		std::ofstream File(FileName);
		if (File.is_open() == false)
			throw FileFailureException();
		File << "        &&& &&  & &&" << std::endl;
		File << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		File << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		File << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		File << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		File << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		File << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		File << "     &&     \\|||" << std::endl;
		File << "             |||" << std::endl;
		File << "             |||" << std::endl;
		File << "             |||" << std::endl;
		File << "       , -=-~  .-^- _" << std::endl;
		File << "Behold, a beautiful tree!" << std::endl;
		File.close();
	}
	else
		throw GradeTooLowException();
}

const char* ShrubberyCreationForm::FileFailureException::what() const noexcept
{
	return "Failed to open file";
}
