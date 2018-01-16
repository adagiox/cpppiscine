#include "Bureaucrat.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException
(const Bureaucrat::GradeTooLowException &src) { *this = src; }
Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator= 
(const GradeTooLowException &rhs) { static_cast <void> (rhs); return *this; }
const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return ("GRADE TOO LOW!!!!! ABORT!!! ABORT!!! ABORT!!!"); }
Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooHighException::GradeTooHighException
(const Bureaucrat::GradeTooHighException &src) { *this = src; }
Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator= 
(const GradeTooHighException &rhs) { static_cast <void> (rhs); return *this; }
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return ("GRADE TOO HIGH!!!!! ABORT!!! ABORT!!! ABORT!!!"); }

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	if (src.grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (src.grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	this->grade = src.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) 
{
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incGrade() 
{
	if (this->grade <= 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (this->grade >= 150)
		throw (Bureaucrat::GradeTooHighException());
	this->grade--;
}

void Bureaucrat::decGrade()
{
	if (this->grade <= 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (this->grade >= 150)
		throw (Bureaucrat::GradeTooHighException());
	this->grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o; 
}