#include "vector.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	ft::vector<int> vec1(5, 10);
	cout << &vec1[0] << ": " << vec1[0] << endl;
	cout << &vec1[1] << ": " << vec1[1] << endl;
	cout << &vec1[2] << ": " << vec1[2] << endl;
	cout << &vec1[3] << ": " << vec1[3] << endl;
	cout << &vec1[4] << ": " << vec1[4] << endl;
	cout << endl;

	ft::vector<int>::iterator it1(&vec1[0]);
	ft::vector<int>::iterator it2(vec1.end());
	cout << *it1 << endl;
	cout << *it2 << endl;
	// cout << *it << endl;
	// ++it;
	// cout << *it << endl;
	// cout << it[0] << " " << it[1] << endl;

	
	// ft::vector<int> vec2(5, 10);
	// cout << vec2 << ": " << *vec2 << endl << endl;
	// cout << &vec2[0] << ": " << vec2[0] << endl;
	// cout << &vec2[1] << ": " << vec2[1] << endl;
	// cout << &vec2[2] << ": " << vec2[2] << endl;
	// cout << &vec2[3] << ": " << vec2[3] << endl;
	// cout << &vec2[4] << ": " << vec2[4] << endl;
	// // cout << &vec2[5] << ": " << vec2[5] << endl;
	// cout << endl;

	// cout << sizeof(Test) << endl;
	// ft::vector<Test> vec3(3, 10);
	// cout << endl;

	// ft::vector<Test> myvector;
	// Test * p;
	// unsigned int i;
	// // allocate an array with space for 5 elements using vector's allocator:
	// p = myvector.get_allocator().allocate(5);
	// // construct values in-place on the array:
	// for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	// cout << "The allocated array contains:";
	// for (i=0; i<5; i++) cout << ' ' << p[i];
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

// 	std::vector<int>::iterator it(vec2.begin());
// 	cout << *it << endl;
// 	cout << it[0] << " " << it[1] << endl;


// 	return 0;
// }