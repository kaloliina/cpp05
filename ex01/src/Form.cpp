#include "../include/Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too Lo-o-o-owwww";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too HIIIIGH";
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSignstatus() const
{
	return _isSigned;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExec() const
{
	return _gradeExec;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
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
	os << form.getName() << ", form signed: " << line << ".\nSigning requirement: " << form.getGradeSign() << ".\nExecution requirement: " << form.getGradeExec() << ".";
	return os;
}
