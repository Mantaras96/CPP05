#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form (void): name("default"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}

Form::Form( const Form &f ): name(f.name), isSigned(false), gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw Form::GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw Form::GradeTooLowException();
        std::cout << "Form " << name << " created" << std::endl;
    }

Form::~Form()
{
    std::cout << "Form " << name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    this->isSigned = rhs.getIsSigned();
    return *this;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::ostream	&operator<<( std::ostream &o, const Form &f )
{
    o << "Form " << f.getName() << " is " << (f.getIsSigned() ? "" : "not ") << "signed and requires a grade of " << f.getGradeToSign() << " to sign and a grade of " << f.getGradeToExecute() << " to execute." << std::endl;
    return o;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
