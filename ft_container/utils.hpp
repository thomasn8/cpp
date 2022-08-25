#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
// ENABLE_IF
	template<bool Cond, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

// IS_INTEGRAL
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

#endif