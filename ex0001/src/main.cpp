
#include "../include/Form.hpp"
int main(void)
{
	try
	{
		Form buds("formi", 20, 20);
		Form budsa(buds);
		std::cout << buds << std::endl;
		std::cout << budsa << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat buds("kartsa", 20);
		Bureaucrat budsa(buds);
		std::cout << buds << std::endl;
		std::cout << budsa << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try {
	std::cout << "HERE" << std::endl;
	Bureaucrat buddy("karo", 1);
	std::cout << buddy << std::endl;
	buddy.incrementGrade();
	buddy.incrementGrade();
	std::cout << "do we get here" << std::endl;
	buddy.decrementGrade();
	Form formie("form", 50, 50);
	std::cout << formie << std::endl;
	buddy.signForm(formie);
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
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
