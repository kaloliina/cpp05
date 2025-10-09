#include "../include/Form.hpp"

Form::Form(std::string name, int gradeReq, int gradeExec) : _name(name), _gradeReq(gradeReq), _gradeExec(gradeExec)
{
	_isSigned = false;
}

Form::Form(const Form& copy) : Form(copy._name, copy._gradeReq, copy._gradeExec)
{
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "GradeTooLOUUUWW";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "GradeTooHIIIIEEEGH";
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

//what if the form is already signed?
void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeReq)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

//need to make sure the boolean is in understandable format
std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << form.getName() << "\n" << form.getSignstatus() << "\n" << form.getGradeReq() << "\n" << form.getGradeExec();
	return os;
}
