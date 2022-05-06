#
#!/bin/bash
# Autogen ClassName.hpp and ClassName.cpp with canonical functions
#
echo "C++ class files generator (*.hpp + *.cpp)"
read -p 'Enter a ClassName : ' ClassName

#
#	Demande le nom de la class
#
while [ -n "$ClassName" ]
do
	#
	#	Check dans le current dir si des fichiers existent déjà avec ce nom
	#
	if [ -e "$ClassName.hpp" ] || [ -e "$ClassName.cpp" ]
	then
		echo "Impossible: files using this ClassName already exist"
	else
		#
		#	Créer les fichiers et les remplit avec le modèle adapté à la class
		#
		`touch "$ClassName.hpp" "$ClassName.cpp"`

#########################################
#                 .HPP                  #
#########################################
define="$(echo $ClassName | tr 'a-z' 'A-Z')_HPP"

echo "#ifndef $define
# define $define

#include <iostream>

class $ClassName
{
	public:
	
		$ClassName & operator=($ClassName const & src);
		$ClassName($ClassName const & src);
		$ClassName(std::string const & name);
		$ClassName();
		~$ClassName();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, $ClassName const & inst);

#endif" >> "$ClassName.hpp"

#########################################
#                 .CPP                  #
#########################################
echo "#include \"$ClassName.hpp\"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void $ClassName::setName(std::string const & name)
{
	this->_name = name;
}

std::string	$ClassName::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, $ClassName const & instance)
{
	o << instance.getName();
	return o;
}

$ClassName	& $ClassName::operator=($ClassName const & src)
{
	this->_name = src.getName();
	std::cout << \"(\" << this << \" - assign.) $ClassName (\" << &src << \") copied\" << std::endl;
	return *this;
}

$ClassName::$ClassName($ClassName const & src) :
_name(src.getName())
{
	std::cout << \"(\" << this << \" - copy) $ClassName created\" << std::endl;
}

$ClassName::$ClassName(std::string const & name) :
_name(name)
{
	std::cout << \"(\" << this << \" - string) $ClassName created\" << std::endl;
}

$ClassName::$ClassName()
{
	std::cout << \"(\" << this << \" - default) $ClassName created\" << std::endl;
}

$ClassName::~$ClassName()
{
	std::cout << \"(\" << this << \" - default) $ClassName destroyed\" << std::endl;
}" >> $ClassName.cpp

#########################################
#              GENERATED!               #
#########################################

		echo "$ClassName.hpp and $ClassName.cpp generated"
	fi


	read -p 'Enter a ClassName : ' ClassName

done
