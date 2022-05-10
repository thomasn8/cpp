#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
// #include <ctype.h>
class Form;

class Intern
{
	public:
	
		Intern & operator=(Intern const & src);
		Intern(Intern const & src);
		Intern();
		~Intern();

		Form *makeForm(std::string formName, std::string target);
};

std::ostream	& operator<<(std::ostream & o, Intern const & inst);
typedef	Form *(*f_ptr)(std::string const & target);

#endif

/*
	le stagiaire a une aptitude importante : la fonction makeForm() qui prend deux strings en paramètres. La première est le nom du formulaire, la seconde la cible du formulaire. 
	
	Elle retourne un pointeur sur un objet Form dont le nom est passé en
	paramètre et dont la cible est le second paramètre.
	
	Elle affiche quelque chose comme :
	Intern creates <form>

	Si le nom du formulaire passé en paramètre n’existe pas, affichez un message d’erreur explicite.
*/