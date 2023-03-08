#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm (void): name("default"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}

AForm::AForm( const AForm &f ): name(f.name), isSigned(false), gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw AForm::GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw AForm::GradeTooLowException();
        std::cout << "AForm " << name << " created" << std::endl;
    }

AForm::~AForm()
{
    std::cout << "AForm " << name << " destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
    this->isSigned = rhs.getIsSigned();
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

std::ostream	&operator<<( std::ostream &o, const AForm &f )
{
    o << "AForm " << f.getName() << " is " << (f.getIsSigned() ? "" : "not ") << "signed and requires a grade of " << f.getGradeToSign() << " to sign and a grade of " << f.getGradeToExecute() << " to execute." << std::endl;
    return o;
}

void	AForm::checkExec(const Bureaucrat &executor ) const
{
	if (this->isSigned == false)
		throw(AForm::FormNotSigned());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char	*AForm::FormNotSigned::what( void ) const throw()
{
	return ("Exception: AForm is not signed!");
}

const char	*AForm::FileNotOpen::what( void ) const throw()
{
	return ("Exception: File couldn't be opened!");
}

