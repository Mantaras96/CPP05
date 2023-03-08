#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &f ) : AForm(f), target(f.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    this->target = rhs.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->AForm::checkExec(executor);
    int	random = rand() % 2;
	if (random == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " has failed to be robotomized." << std::endl;
}