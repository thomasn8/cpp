#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/*
	The type T is enabled as member type enable_if::type if Cond is true.
	Otherwise, enable_if::type is not defined.

	Usage: 
				typename std::enable_if< std::is_integral<T>::value, bool >::type
				
	Décomposition:

				typename
				std::enable_if
				< 
					std::is_integral<T>::value, 	// condition part
					bool 
				>
				::type

	This is useful to hide signatures on compile time when a particular condition is not met, 
	since in this case, the member enable_if::type will not be defined and 
	attempting to compile using it should fail.
*/
namespace ft
{
	// Cond is true -> type T is enabled as member type enable_if::type
	template <class T> 
	class enable_if<true, T> { typedef T type; };

	// enable_if::type is not defined because a particular condition is not met
	// so attempting to compile using it should fail
	template <bool Cond, class T = void> 
	class enable_if {};
}

#endif

/* 
	SFINAE ("Substitution Failure Is Not An Error")
	"L'échec de substitution n'est pas une erreur" fait référence à une situation en C ++ 
	où une substitution non valide des paramètres de modèle n'est pas en soi une erreur. 

	This rule applies during overload resolution of function templates: 
	When substituting the explicitly specified or deduced type for the template parameter fails, 
	the specialization is discarded from the overload set instead of causing a compile error.
	This feature is used in template metaprogramming. 

	https://en.cppreference.com/w/cpp/language/sfinae
	https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error
*/
