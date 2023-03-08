#ifndef AFORM_HPP
#define AFORM_HPP

#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool isSigned;
        const int  gradeToSign;
        const int gradeToExecute;
    public:
        // Canonical //
        AForm(void);
        AForm( const AForm &f );
        virtual ~AForm();
        AForm &operator=(AForm const &rhs);

        AForm(std::string name, int gradeToSign, int gradeToExecute);

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        	class FormNotSigned : public std::exception
        {
            public:
                const char	*what( void ) const throw();
        };

        class FileNotOpen : public std::exception
        {
            public:
                const char	*what( void ) const throw();
        };

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        virtual void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void	checkExec(const Bureaucrat &executor ) const;
    };

    std::ostream	&operator<<( std::ostream &o, const AForm &f );

#endif