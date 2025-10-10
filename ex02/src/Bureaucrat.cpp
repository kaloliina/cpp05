#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}
/*I'm not entirely sure why this works if its markes as default.
If its markes as default, does copy constructor call default constructor? But in our case
default constructor has been deleted..?*/
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : Bureaucrat(copy._name, copy._grade)
{

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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign" << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;		
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
