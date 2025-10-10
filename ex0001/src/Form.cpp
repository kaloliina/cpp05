#include "../include/Form.hpp"

Form::Form(std::string name, int gradeReq, int gradeExec) : _name(name), _gradeReq(gradeReq), _gradeExec(gradeExec)
{
	_isSigned = false;
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form grade too HIIIIGH";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form grade too Lo-o-o-owwww";
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSignstatus() const
{
	return _isSigned;
}

int Form::getGradeReq() const
{
	return _gradeReq;
}

int Form::getGradeExec() const
{
	return _gradeExec;
}

/*Could add a check if form is already signed*/
void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeReq)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	std::string line;
	if (form.getSignstatus() == true)
		line = "Yes";
	else
		line = "No";
	os << form.getName() << ", form signed: " << line << ".\nSigning requirement: " << form.getGradeReq() << ".\nExecution requirement: " << form.getGradeExec() << ".\n";
	return os;
}
