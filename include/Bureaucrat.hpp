#pragma once
#include <iostream>
#include "./Form.hpp"

//Remember that this is combining the first and second exercise!
//Once you are ready to divide it into two folders, remove the signForm from
//this one
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
//copy constructor and copy assignment...
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int increment);
	void decrementGrade(int decrement);
	void signForm(Form& form);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
//and why do we need separate functions for incrementation and decrement..?
