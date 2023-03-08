#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned)
{
    if (src._gradeToSign < 1 || src._gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (src._gradeToSign > 150 || src._gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
    {
        if (rhs._gradeToSign < 1 || rhs._gradeToExecute < 1)
            throw Form::GradeTooHighException();
        else if (rhs._gradeToSign > 150 || rhs._gradeToExecute > 150)
            throw Form::GradeTooLowException();
        _isSigned = rhs._isSigned;
    }
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





