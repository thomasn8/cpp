#include <iostream>
// #include <type_traits>

namespace ft
{
	/////////////////////////// Enable if
	template<bool Cond, class T = void> 				// ft::enable_if< FALSE, bool >
	struct enable_if {};
	
	template<class T> 									// ft::enable_if< TRUE, bool >
	struct enable_if<true, T> { typedef T type; };



	/////////////////////////// Is integer
	// It is a struct<T>, whose constexpr bool value member is set to true if T is an “integral type” 
	// (or any const, volatile and reference to it) and false otherwise.
	template<typename T>
	struct is_integral { const static bool value = false; };
	template<>
	struct is_integral<int> { const static bool value = true; };
	template<>
	struct is_integral<char> { const static bool value = true; };
	template<>
	struct is_integral<unsigned int> { const static bool value = true; };
	template<>
	struct is_integral<unsigned char> { const static bool value = true; };
	template<>
	struct is_integral<short unsigned int> { const static bool value = true; };
	template<>
	struct is_integral<short int> { const static bool value = true; };
	template<>
	struct is_integral<long unsigned int> { const static bool value = true; };
	template<>
	struct is_integral<long int> { const static bool value = true; };
	template<>
	struct is_integral<bool> { const static bool value = true; };
	template<>
	struct is_integral<wchar_t> { const static bool value = true; };

}

/////////////////////////// EXAMPLES

// ft::is_integral<T>::value 			= FALSE car type complexe
// ft::is_integral<int>::value  		= TRUE car type simple
// 
// =>
// 
// ft::enable_if< FALSE, bool >::type	=> existe pas
// ft::enable_if< TRUE, bool >::type	=> existe

template <class T>
typename ft::enable_if< ft::is_integral<T>::value, bool >::type is_odd (T i)
{																			
	return bool(i % 2);														
}																			

template < class T>
typename ft::enable_if< ft::is_integral<T>::value, bool >::type is_even (T i) 
{
	return !bool(i % 2);
}

/////////////////////////// TESTS
int main()		// code does not compile if type of i is not integral
{
	int i = 9;			// Permet la compil
   
	// int j = 1;		// Bloque la compil -> SFINAE
	// int *i = &j;		// "

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;

	return 0;
}
