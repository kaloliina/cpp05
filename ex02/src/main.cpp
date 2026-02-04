#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
//	std::cout << "--------Abstract class test--------" << std::endl;
//	AForm form("Important", 0, 50);
	std::cout << "--------Execute unsigned form test--------" << std::endl;
	try
	{
		Bureaucrat person("Sylvanas", 1);
        PresidentialPardonForm form1("Lala");
        RobotomyRequestForm form2("Lele");
        ShrubberyCreationForm form3("Lili");
        person.executeForm(form1);
        person.executeForm(form2);
        person.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Execute with too high execution grade test--------" << std::endl;
	try
	{
		Bureaucrat person1("Sylvanas", 142);
        ShrubberyCreationForm form1("Formie");
        person1.signForm(form1);
        person1.executeForm(form1);
		Bureaucrat person2("Anduin", 70);
        RobotomyRequestForm form2("Formie");
        person2.signForm(form2);
        person2.executeForm(form2);
		Bureaucrat person3("Jaina", 20);
        PresidentialPardonForm form3("Formie");
        person3.signForm(form3);
        person3.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Execute succesfully test--------" << std::endl;
	try
	{
		Bureaucrat person1("Sylvanas", 1);
        ShrubberyCreationForm form1("Formie");
        person1.signForm(form1);
        person1.executeForm(form1);
		Bureaucrat person2("Anduin", 1);
        RobotomyRequestForm form2("Formie");
        person2.signForm(form2);
        person2.executeForm(form2);
		Bureaucrat person3("Jaina", 1);
        PresidentialPardonForm form3("Formie");
        person3.signForm(form3);
        person3.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Execute succesfully with exact grades test--------" << std::endl;
	try
	{
        Bureaucrat signer("Rainbow Dash", 1);
        Bureaucrat executioner1("Hihi", 137);
        Bureaucrat executioner2("Hehe", 45);
        Bureaucrat executioner3("Haha", 5);
        ShrubberyCreationForm form1("Formie");
        signer.signForm(form1);
        executioner1.executeForm(form1);
		Bureaucrat person2("Anduin", 1);
        RobotomyRequestForm form2("Formie");
        signer.signForm(form2);
        executioner2.executeForm(form2);
		Bureaucrat person3("Jaina", 1);
        PresidentialPardonForm form3("Formie");
        signer.signForm(form3);
        executioner3.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Execute twice test--------" << std::endl;
	try
	{
        Bureaucrat signer("Rainbow Dash", 1);
        Bureaucrat executioner1("Hihi", 137);
        Bureaucrat executioner2("Hehe", 45);
        Bureaucrat executioner3("Haha", 5);
        ShrubberyCreationForm form1("Formie");
        signer.signForm(form1);
        executioner1.executeForm(form1);
        executioner1.executeForm(form1);
		Bureaucrat person2("Anduin", 1);
        RobotomyRequestForm form2("Formie");
        signer.signForm(form2);
        executioner2.executeForm(form2);
        executioner2.executeForm(form2);
		Bureaucrat person3("Jaina", 1);
        PresidentialPardonForm form3("Formie");
        signer.signForm(form3);
        executioner3.executeForm(form3);
        executioner3.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}