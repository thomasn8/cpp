#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

		virtual IMateriaSource & operator=(IMateriaSource const & src);
		MateriaSource(IMateriaSource const & src);
		MateriaSource();
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const & type);
		
		 AMateria * getMateria(int idx) const;
		 void seeMaterias() const;

	private:

		virtual void deleteMaterias();
		AMateria *_materias[4];
};

#endif

/* 
• learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.

• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment
par la MateriaSource et dont le type est le même que celui passé en paramètre.
Retourne 0 si le type est inconnu.

En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
 */