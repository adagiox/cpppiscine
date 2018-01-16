#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				GradeTooLowException(const GradeTooLowException &src);
				GradeTooLowException &operator=(const GradeTooLowException &rhs);
	 			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				virtual ~GradeTooHighException() throw();
				GradeTooHighException(const GradeTooHighException &src);
				GradeTooHighException &operator=(const GradeTooHighException &rhs);
				virtual const char *what() const throw();
		};

		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif