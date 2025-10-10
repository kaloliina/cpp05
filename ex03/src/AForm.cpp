#include "../include/AForm.hpp"

AForm::AForm(std::string name, int gradeReq, int gradeExec) : _name(name), _gradeReq(gradeReq), _gradeExec(gradeExec)
{
	_isSigned = false;
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Form grade too HIIIIGH";
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Form grade too Lo-o-o-owwww";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form has not been signed";
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSignstatus() const
{
	return _isSigned;
}

int AForm::getGradeReq() const
{
	return _gradeReq;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeReq)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& AForm)
{
	std::string line;
	if (AForm.getSignstatus() == true)
		line = "Yes";
	else
		line = "No";
	os << AForm.getName() << ", form signed: " << line << ".\nSigning requirement: " << AForm.getGradeReq() << ".\nExecution requirement: " << AForm.getGradeExec() << ".\n";
	return os;
}
