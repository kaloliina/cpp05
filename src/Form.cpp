#include "../include/Form.hpp"

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
	return name;
}

bool Form::getSignstatus() const
{
	return issigned;
}

int Form::getGradeReq() const
{
	return grade_req;
}

int Form::getGradeExec() const
{
	return grade_exec;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_req)
		issigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& form);
