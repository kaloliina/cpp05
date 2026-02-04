#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy) = default;
	PresidentialPardonForm &operator=(const PresidentialPardonForm& src) = delete;
	~PresidentialPardonForm() = default;

	void	execute(Bureaucrat const& executor) const;
};
