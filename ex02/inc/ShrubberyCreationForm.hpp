#ifndef SHURBERRYCREATIONFORM_HPP
#define SHURBERRYCREATIONFORM_HPP

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        // Canonical //
        ShrubberyCreationForm(void);
        ShrubberyCreationForm( const ShrubberyCreationForm &f );
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const & executor) const;
    };

#endif