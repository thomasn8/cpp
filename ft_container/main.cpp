
#include "vector.hpp"
#include "map.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	// ft::vector<int> vec1;
	// cout << endl;
	
	cout << sizeof(int) << endl;
	ft::vector<int> vec2(5, 10);
	cout << vec2 << ": " << *vec2 << endl << endl;
	cout << &vec2[0] << ": " << vec2[0] << endl;
	cout << &vec2[1] << ": " << vec2[1] << endl;
	cout << &vec2[2] << ": " << vec2[2] << endl;
	cout << &vec2[3] << ": " << vec2[3] << endl;
	cout << &vec2[4] << ": " << vec2[4] << endl;
	// cout << &vec2[5] << ": " << vec2[5] << endl;
	cout << endl;

	// cout << sizeof(Test) << endl;
	// ft::vector<Test> vec3(3, 10);
	// cout << endl;
	
	// ft::map<int> map1;
	// cout << endl;

	return 0;
}

/* 
	- Toutes les fonctions membres, les fonctions non-membres et les surcharges d’un container sont attendues
	- Vous conformer au nommage original
	- Si le container possède un système d’itérateur, vous devez l’implémenter
	- Utiliser std::allocator
	- Pour les surcharges non-membres, le mot-clé friend est autorisé
*/

/* 
	Vous devez aussi implémenter :
	• iterators_traits
	• reverse_iterator
	• enable_if
	• is_integral
	• equal et/ou lexicographical_compare
	• std::pair
	• std::make_pair
*/












// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
// 	std::vector<int> vec2(5, 10);
// 	cout << &vec2[0] << ": " << vec2[0] << endl;
// 	cout << &vec2[1] << ": " << vec2[1] << endl;
// 	cout << &vec2[2] << ": " << vec2[2] << endl;
// 	cout << &vec2[3] << ": " << vec2[3] << endl;
// 	cout << &vec2[4] << ": " << vec2[4] << endl;
// 	cout << &vec2[5] << ": " << vec2[5] << endl;
// 	cout << endl;

// 	return 0;
// }