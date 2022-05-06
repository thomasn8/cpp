# ClassGen
Generate c++ Class files (*.cpp and *.hpp) based on templates in: ClassGen/class_files

## Copier le dossier ClassGen quelque part, par exemple dans /Users/thomas

	$ cd ~ && git clone https://github.com/thomasn8/ClassGen.git

## Dans .zshrc ou .bashrc, modifier $PATH avec le chemin vers ClassGen :

	$ vim .zshrc

	Add:
		PATH=$PATH:/Users/thomas/ClassGen

## Dans ce même .zshrc ou .bashrc, ajouter une alias pour ClassGen.sh

	Add: 
		alias class="ClassGen.sh"

## Utiliser cette alias comme commande pour générer des classes dans le dossier courant

	$ class
	
	C++ class files generator (*.hpp + *.cpp)
	Enter ClassName(s) (separated by whitespace) :

#### - écrire une ou plusieurs 'ClassName' et presser 'enter' 
#### - pour quitter le prog: laisser vider et presser 'enter'
