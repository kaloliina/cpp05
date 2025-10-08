#pragma once
#include <iostream>
#include "./Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool	issigned;
	const int grade_req;
	const int grade_exec;
public:
//are we inheriting from other class here...
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};
	std::string getName() const;
	bool getSignstatus() const;
	int getGradeReq() const;
	int getGradeExec() const;
	void beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, Form& form);
