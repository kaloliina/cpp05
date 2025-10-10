#include "../include/AForm.hpp"

AForm::AForm(std::string name, int gradeReq, int gradeExec) : _name(name), _gradeReq(gradeReq), _gradeExec(gradeExec)
{
	_isSigned = false;
}

AForm::AForm(const AForm& copy) : AForm(copy._name, copy._gradeReq, copy._gradeExec)
{

}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "AForm grade too HIIIIGH";
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "AForm grade too Lo-o-o-owwww";
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

/*Could add a check if AForm is already signed*/
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
	os << AForm.getName() << ", AForm signed: " << line << ".\nSigning requirement: " << AForm.getGradeReq() << ".\nExecution requirement: " << AForm.getGradeExec() << ".\n";
	return os;
}
