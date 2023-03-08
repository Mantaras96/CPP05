#include "../inc/Intern.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::Intern( const Intern &f )
{
    *this = f;
    return ;
}

Intern::~Intern()
{
    return ;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}

const char *Intern::UnknownFormException::what() const throw()
{
    return ("Unknown form exception");
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    if (form == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (form == "presidential pardon")
        return new PresidentialPardonForm(target);
    else if (form == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else
        throw Intern::UnknownFormException();
}

