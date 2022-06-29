/* 
	SFINAE ("Substitution Failure Is Not An Error")
	L'échec de substitution n'est pas une erreur fait référence à une situation en C ++ 
	où une substitution non valide des paramètres de modèle n'est pas en soi une erreur. 
	= technique de programmation associée.

	A substitution failure is any situation when the type or expression above would be ill-formed 
	(with a required diagnostic), if written using the substituted arguments.
	Only the failures in the types and expressions in the immediate context of the function type or 
	its template parameter types are SFINAE errors.

	The type T is enabled as member type enable_if::type if Cond is true.
	Otherwise, enable_if::type is not defined.
	This is useful to hide signatures on compile time when a particular condition is not met, 
	since in this case, the member enable_if::type will not be defined and 
	attempting to compile using it should fail.


	Cond
		A compile-time constant of type bool

	T
		A type
*/

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	// Cond is true -> type T is enabled as member type enable_if::type
	template <class T> 
	class enable_if<true, T>
	{
		typedef T type;
	};

	// enable_if::type is not defined because a particular condition is not met
	// so attempting to compile using it should fail
	template <bool Cond, class T = void> 
	class enable_if 
	{ };
}

#endif