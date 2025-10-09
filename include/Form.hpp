#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

//Same here, I could put copy constructor to default..?
class Form
{
private:
	const std::string _name;
	bool	_isSigned;
	const int _gradeReq;
	const int _gradeExec;
public:
	Form();
	Form(std::string name, int gradeReq, int gradeExec);
	Form(const Form& copy);
	Form &operator=(const Form& src) = delete;
	~Form() = default;

	std::string getName() const;
	bool getSignstatus() const;
	int getGradeReq() const;
	int getGradeExec() const;
	void beSigned(Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};

};

std::ostream& operator<<(std::ostream& os, Form& form);
