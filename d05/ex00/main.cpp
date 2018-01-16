#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Abe", 1);
		std::cout << a;
		Bureaucrat b("Bobby", 150);
		std::cout << b;
		Bureaucrat c("Carl", -1);
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("Abe", 1);
		std::cout << a;
		Bureaucrat b("Bobby", 150);
		std::cout << b;
		Bureaucrat d("Dave", 200);
		std::cout << d;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("Abe", 1);
		std::cout << a;
		a.incGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Bob", 150);
		std::cout << b;
		b.decGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}