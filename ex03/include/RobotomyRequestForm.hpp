#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm() = delete;
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy) = default;
	RobotomyRequestForm &operator=(const RobotomyRequestForm& src) = default;
	~RobotomyRequestForm() = default;

	void execute(Bureaucrat const& executor) const;
};
