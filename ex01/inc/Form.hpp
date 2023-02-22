#ifndef FORM_HPP
#define FORM_HPP

#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form:
    {
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;
        Form();
    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        ~Form();
        Form &operator=(Form const &rhs);

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

    }

    std::ostream	&operator<<( std::ostream &o, const Form &f );

#endif