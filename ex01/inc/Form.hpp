#ifndef FORM_HPP
#define FORM_HPP

#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool isSigned;
        const int  gradeToSign;
        const int gradeToExecute;
    public:
        // Canonical //
        Form(void);
        Form( const Form &f );
        ~Form();
        Form &operator=(Form const &rhs);

        Form(std::string name, int gradeToSign, int gradeToExecute);

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

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
    };

    std::ostream	&operator<<( std::ostream &o, const Form &f );

#endif