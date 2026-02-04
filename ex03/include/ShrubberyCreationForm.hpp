#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy) = default;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src) = delete;
	~ShrubberyCreationForm() = default;

	void	execute(Bureaucrat const& executor) const;
	class FileFailureException : public std::exception
	{
		const char* what() const noexcept override;
	};
};
