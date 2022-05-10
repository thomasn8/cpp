#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::action() const
{
	std::string filename = this->getName().append("_shrubbery");
	std::string tree;
	
	tree  = "the\n";
	tree += "├── quick\n";
	tree += "│   └── brown\n";
	tree += "├── fox\n";
	tree += "├── jumps\n";
	tree += "│   ├── over\n";
	tree += "│   │   └── the\n";
	tree += "│   └── lazy\n";
	tree += "└── dog";
	tree += "\n";
	tree += "               ,@@@@@@@,\n";
	tree += "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	tree += "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	tree += "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	tree += "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	tree += "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	tree += "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	tree += "       |o|        | |         | |\n";
	tree += "       |.|        | |         | |\n";
	tree += "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\n";
	
	std::ofstream file;
  	file.open(filename, std::ofstream::out | std::ofstream::app);
	file << tree;
	std::cout << BLU;
	std::cout << filename << " written" << std::endl;
	std::cout << WHI;
	file.close();
}

Form		*newShrubberyCreationForm(std::string const & target)
{
	Form *ptr = new ShrubberyCreationForm(target);
	return ptr;
}

void ShrubberyCreationForm::abstract() const
{
	return ;
}

/* *****************
	Getters/Setters
***************** */



/* *****************
	Canonical
***************** */

ShrubberyCreationForm	& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "(" << this << " - assign.) Can't reassign an existing form" << std::endl;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
Form(src.getName(), 145, 137)
{
	// this->print_tree();
	std::cout << "(" << this << " - copy) ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
Form(target, 145, 137)
{
	// this->print_tree();
	std::cout << "(" << this << " - string) ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(" << this << " - default) ShrubberyCreationForm destroyed" << std::endl;
}
