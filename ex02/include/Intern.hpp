#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
//Look again at these
class Intern
{
public:
	Intern() = default;
	Intern(std::string name, int grade) = delete;
	Intern(const Intern& copy);
	Intern &operator=(const Intern& src) = delete;
	~Intern() = default;
	class Form* makeForm(std::string formName, std::string formTarget);
};
