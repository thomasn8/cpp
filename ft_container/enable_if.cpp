#include <iostream>
#include <type_traits>

namespace ft
{

	/////////////////////////// IMPLEMENTATION #1
	template<bool Cond, class T = void> 
	struct enable_if {};
	
	template<class T> 
	struct enable_if<true, T> 
	{ 
		typedef T type; 
	};

}

/////////////////////////// EXAMPLES
// // 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if< std::is_integral<T>::value, bool >::type is_odd (T i)
{
	return bool(i % 2);
}

// // 2. the second template argument is only valid if T is an integral type:
// template < class T, class = typename ft::enable_if< std::is_integral<T>::value >::type >
// bool is_even (T i) 
// {
// 	return !bool(i % 2);
// }

/////////////////////////// TESTS
int main()		// code does not compile if type of i is not integral
{
//   int i = 9;
  
//   std::string s("Hello");
 
  int j = 1;
  int *i = &j;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
//   std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}
