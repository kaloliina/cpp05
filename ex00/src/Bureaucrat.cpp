#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	_grade = _grade - 1;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	_grade = _grade + 1;
	if (_grade > 150)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat grade too HIIIIGH";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat grade too Lo-o-o-owwww";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
