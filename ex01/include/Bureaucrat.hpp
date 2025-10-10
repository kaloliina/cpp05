#pragma once
#include <iostream>

class Form;

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
