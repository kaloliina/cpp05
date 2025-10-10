#pragma once
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	bool	_isSigned;
	const int _gradeReq;
	const int _gradeExec;
public:
	AForm();
	AForm(std::string name, int gradeReq, int gradeExec);
	AForm(const AForm& copy) = default;
	AForm &operator=(const AForm& src) = delete;
	~AForm() = default;

	std::string getName() const;
	bool getSignstatus() const;
	int getGradeReq() const;
	int getGradeExec() const;
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class FormNotSignedException : public std::exception
	{
		const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, AForm& AForm);
