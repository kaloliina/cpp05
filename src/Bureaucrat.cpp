#include "../include/Bureaucrat.hpp"

//Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
//This sounds like the try catch for this situation needs to be handled in main because
//we cannot check invalid grade during instantiation because that doesnt happen in the body...? or
//Settings them to default value..
Bureaucrat::Bureaucrat() : _name("DefaultName"), _grade(0)
{
}

//Setting the parameterized one
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
}

//Not sure if destructor needs anything at this point?
Bureaucrat::~Bureaucrat()
{
	
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

//Grade 1 is the highest one and the 150 is the lowest.
//So if we INCREMENT, we actually lower lower it (put it closer to 0)
//And if we DECREMENT, it goes higher
//Is it default incrementation by one or can we choose how much we increment?
//I assume in these blocks we need to use try catch
//Same as constructor
void Bureaucrat::incrementGrade(int increment)
{
	_grade = _grade - increment;
}

void Bureaucrat::decrementGrade(int decrement)
{
	_grade = _grade + decrement;
}

// //Should this one actually be the one checking the grade too high etc and give string regarding that?
// const char* Bureaucrat::what() const
// {
// 	return "hello";
// }
