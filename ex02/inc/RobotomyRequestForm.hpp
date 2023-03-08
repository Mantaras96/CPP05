#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        // Canonical //
        RobotomyRequestForm(void);
        RobotomyRequestForm( const RobotomyRequestForm &f );
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const & executor) const;
    };

#endif