
#include "../include/Intern.hpp"

int main(void)
{
    AForm* form1;
    AForm* form2;
    AForm* form3;
	std::cout << "--------Intern succesfully creating forms test--------" << std::endl;
	try
	{
        Intern intern;
        form1 = intern.makeForm("RobotomyRequestForm", "Karo");
        form2 = intern.makeForm("ShrubberyCreationForm", "Karo");
        form3 = intern.makeForm("PresidentialPardonForm", "Karo");

        Bureaucrat bureaucrat("boss", 1);
        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);
        delete form1;
        delete form2;
        delete form3;
	}
	catch(const std::exception& e)
	{
        delete form1;
        delete form2;
        delete form3;
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------Intern making a strange form--------" << std::endl;
	try
	{
        Intern intern;
        form1 = intern.makeForm("I want to quit", "Karo");

        Bureaucrat bureaucrat("boss", 1);
        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/*Test cases for...
--00--
- Grade too high
- Grade too low
- Grade just on the edges
- Regular tests that work
- Overflow? Negative..
- Test case for incrementing or decrementing and if reaching out of bounds
- Making sure the output stream works

--01--
- If form cannot be signed because of grade
- If form is being signed again? (Do we need an error that its already signed...)
- If bureaucrats grade is just on the edge
- Regular tests
- Making sure the output stream works

- Remember to check that you are writing things to STDERR!
*/
