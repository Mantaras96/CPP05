#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        // Canonical //
        PresidentialPardonForm(void);
        PresidentialPardonForm( const PresidentialPardonForm &f );
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;
    };

#endif