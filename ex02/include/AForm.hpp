#pragma once
#include "Bureaucrat.hpp"

//	virtual void beSigned(Bureaucrat& bureaucrat) = 0; ..?
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
	AForm(const AForm& copy);
	AForm &operator=(const AForm& src) = delete;
	~AForm() = default;

	std::string getName() const;
	bool getSignstatus() const;
	int getGradeReq() const;
	int getGradeExec() const;
	void beSigned(Bureaucrat& bureaucrat);
	void execute(Bureaucrat const& executor) const;
	class GradeTooHighException : public std::exception
	{
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, AForm& AForm);
