#include <iostream>

class Bureaucrat : public std::exception
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
//copy constructor and copy assignment...
	const char* what() const noexcept override { return "Hello"; }
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int increment);
	void decrementGrade(int decrement);
};
//and why do we need separate functions for incrementation and decrement..?
