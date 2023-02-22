#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	joe = Bureaucrat("Joe", 1);
		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jack = Bureaucrat("Jack", 150);
		std::cout << jack << std::endl;
		jack.incrementGrade();
		std::cout << jack << std::endl;
		jack.decrementGrade();
		std::cout << jack << std::endl;
		jack.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		john = Bureaucrat("John", 0);
		std::cout << john << std::endl;
		john.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jillian = Bureaucrat("Jillian", 151);
		std::cout << jillian << std::endl;
		jillian.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}