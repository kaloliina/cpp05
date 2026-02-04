#include "../include/AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too Lo-o-o-owwww";
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too HIIIIGH";
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

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
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
	os << AForm.getName() << ", Form signed: " << line << ".\nSigning requirement: " << AForm.getGradeSign() << ".\nExecution requirement: " << AForm.getGradeExec() << ".";
	return os;
}