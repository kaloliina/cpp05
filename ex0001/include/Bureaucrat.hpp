#pragma once
#include <iostream>

class Form;

/*
- Remember that you have combined the first and the second exercise into this so remember to separate them
and remove the signForm and beSigned functions etc..
- You could have another look and check that const is used when needed as well as references.
- Also could I basically set the copy constructor to default..?
- Also was default constructor even part of the orthodox canonical form
*/
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat() = delete;
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy) = default;
	Bureaucrat &operator=(const Bureaucrat& src) = delete;
	~Bureaucrat() = default;

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
