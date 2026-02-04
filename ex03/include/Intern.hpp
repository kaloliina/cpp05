#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern() = default;
	Intern(const Intern& copy) = delete;
	Intern &operator=(const Intern& src) = delete;
	~Intern() = default;

	AForm*	makeForm(std::string formName, std::string formTarget);
	class FormNotFoundException : public std::exception
	{
		const char* what() const noexcept override;
	};
};
