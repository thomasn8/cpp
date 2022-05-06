# ClassGen
Generate c++ Class files (*.cpp and *.hpp) based on templates

## Copier le dossier ClassGen quelque part, par exemple dans /Users/thomas

	$ cd ~ && git clone https://github.com/thomasn8/ClassGen.git

## Dans .zshrc ou .bashrc, modifier $PATH avec le chemin vers ClassGen :

	$ vim .zshrc

	Insert:
		PATH=$PATH:/Users/thomas/ClassGen

## Dans ce même .zshrc ou .bashrc, ajouter une alias pour "ClassGen.sh"

	Insert : 
		alias class="ClassList.sh"

## Utiliser cette alias comme commande pour générer des classes dans le dossier courant depuis n'importe où

	$ class
	
	C++ class files generator (*.hpp + *.cpp)
	Enter ClassName(s) (separated by whitespace) : ...

## Modifier les fichiers template dans ClassGen/class_files

	...