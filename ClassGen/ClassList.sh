#
#!/bin/bash
# Autogen ClassName.hpp and ClassName.cpp with canonical functions
#
echo "C++ class files generator (*.hpp + *.cpp)"
read -p 'Enter ClassName(s) (separated by whitespace) : ' ClassList

#
#	Demande le nom de la class
#
while [ -n "$ClassList" ]
do
	#
	#	Check dans le current dir si des fichiers existent déjà avec ce nom
	#
	for Class in $ClassList
	do

		if [ -e "$Class.hpp" ] || [ -e "$Class.cpp" ]
		then
			echo "Impossible: files using ClassName $Class already exist"
		else
			#
			#	Créer les fichiers et les remplit avec le modèle adapté à la class
			#
			`touch "$Class.hpp" "$Class.cpp"`

#########################################
#                 .HPP                  #
#########################################
define="$(echo $Class | tr 'a-z' 'A-Z')_HPP"

echo "#ifndef $define
# define $define

#include <iostream>

class $Class
{
	public:
	
		$Class & operator=($Class const & src);
		$Class($Class const & src);
		$Class(std::string const & name);
		$Class();
		~$Class();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, $Class const & inst);

#endif" >> "$Class.hpp"

#########################################
#                 .CPP                  #
#########################################
echo "#include \"$Class.hpp\"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void $Class::setName(std::string const & name)
{
	this->_name = name;
}

std::string	$Class::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, $Class const & instance)
{
	o << instance.getName();
	return o;
}

$Class	& $Class::operator=($Class const & src)
{
	this->_name = src.getName();
	std::cout << \"(\" << this << \" - assign.) $Class (\" << &src << \") copied\" << std::endl;
	return *this;
}

$Class::$Class($Class const & src) :
_name(src.getName())
{
	std::cout << \"(\" << this << \" - copy) $Class created\" << std::endl;
}

$Class::$Class(std::string const & name) :
_name(name)
{
	std::cout << \"(\" << this << \" - string) $Class created\" << std::endl;
}

$Class::$Class()
{
	std::cout << \"(\" << this << \" - default) $Class created\" << std::endl;
}

$Class::~$Class()
{
	std::cout << \"(\" << this << \" - default) $Class destroyed\" << std::endl;
}" >> $Class.cpp

#########################################
#              GENERATED!               #
#########################################

			echo "$Class.hpp and $Class.cpp generated"
		fi

	done

	read -p 'Enter ClassName(s) (separated by whitespace) : ' ClassList

done
