#
#!/bin/bash
# Autogen ClassName.hpp and ClassName.cpp with canonical functions
#

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
hpp_file=$SCRIPT_DIR/class_files/ClassName.hpp
cpp_file=$SCRIPT_DIR/class_files/ClassName.cpp

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
			echo "Impossible: files $Class.*pp already exist"
		else
			#
			#	Créer les fichiers et les remplit avec le modèle adapté à la class
			#
			`touch "$Class.hpp" "$Class.cpp"`

			#########################################
			#                 .HPP                  #
			#########################################
			define="$(echo $Class | tr 'a-z' 'A-Z')_HPP"
			`sed "s/ClassName/$Class/g" $hpp_file > $Class.hpp`
			`sed -i '' "s/CLASSNAME_HPP/$define/g" $Class.hpp`

			#########################################
			#                 .CPP                  #
			#########################################
			`sed "s/ClassName/$Class/g" $cpp_file > $Class.cpp`

			#########################################
			#              GENERATED!               #
			#########################################
			echo "$Class.hpp and $Class.cpp generated"

		fi

	done

	read -p '
Enter ClassName(s) (separated by whitespace) : ' ClassList

done
