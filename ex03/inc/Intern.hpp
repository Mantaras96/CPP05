#ifndef INTERN_HPP
#define INTERN_HPP

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class Intern{
    public:
        // Canonical //
        Intern(void);
        Intern( const Intern &f );
        ~Intern();
        Intern &operator=(Intern const &rhs);

        AForm *makeForm(std::string form, std::string target);

        class UnknownFormException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    };

#endif