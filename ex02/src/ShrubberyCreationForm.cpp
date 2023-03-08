#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &f ) : AForm(f), target(f.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    this->target = rhs.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->AForm::checkExec(executor);
	std::fstream	fileout;

	fileout.open((this->target + "_shrubbery").c_str(), std::ios::out);
	if (!fileout)
		throw(FileNotOpen());
	fileout << "      *           *           *           *" << std::endl;
	fileout << "     ***         ***         ***         ***" << std::endl;
	fileout << "    *****       *****       *****       *****" << std::endl;
	fileout << "   *******     *******     *******     *******" << std::endl;
	fileout << "  *********   *********   *********   *********" << std::endl;
	fileout << " *********** *********** *********** ***********" << std::endl;
	fileout << "    |            |            |            |" << std::endl;

	fileout.close();
}