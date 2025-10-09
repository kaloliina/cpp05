#pragma once
#include <iostream>

class Form;

//Remember that this is combining the first and second exercise!
//Once you are ready to divide it into two folders, remove the signForm from
//this one
//Could I basically set the copy constructor to also default..?
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat() = delete;
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=(const Bureaucrat& src) = delete;
	~Bureaucrat() = default;
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
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
//and why do we need separate functions for incrementation and decrement..?
