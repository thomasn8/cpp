// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std:: enable_if< std::is_integral<T>::value, bool >::type is_odd (T i)
{
	/* 	
		si is_integral<T>::value est true
		bool -> 1 (donc odd/=impair)
		1 % 2 = 1
		return bool(1) -> 1

		si is_integral<T>::value est false
		bool -> 0 (donc not odd)
		0 % 2 = 0
		return bool(0) -> 0
	*/
	return bool(i % 2);
}

// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename std::enable_if< std::is_integral<T>::value >::type >
bool is_even (T i) 
{
	return !bool(i % 2);
}

int main() {
//   int i = 9;		// code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}

/* 
	Output:
	i is odd: true
	i is even: false
*/