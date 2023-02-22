#ifndef BUROCRAT_H
#define BUROCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif