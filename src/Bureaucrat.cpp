#include "../include/Bureaucrat.hpp"

//Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
//This sounds like the try catch for this situation needs to be handled in main because
//we cannot check invalid grade during instantiation because that doesnt happen in the body...? or
//Settings them to default value..
Bureaucrat::Bureaucrat() : _name("DefaultName"), _grade(0)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

//Setting the parameterized one
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

//Not sure if destructor needs anything at this point?
Bureaucrat::~Bureaucrat()
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

//Grade 1 is the highest one and the 150 is the lowest.
//So if we INCREMENT, we actually lower lower it (put it closer to 0)
//And if we DECREMENT, it goes higher
//Is it default incrementation by one or can we choose how much we increment?
//I assume in these blocks we need to use try catch
//Same as constructor
void Bureaucrat::incrementGrade(int increment)
{
	_grade = _grade - increment;
}

void Bureaucrat::decrementGrade(int decrement)
{
	_grade = _grade + decrement;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "GradeTooHIIIIGH";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "GradeTooLo-o-o-owwww";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form& form)
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
