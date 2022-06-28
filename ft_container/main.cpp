#include "vector.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	// ft::vector<int> null;
	// ft::vector<int>::iterator null1(null.begin());
	// ft::vector<int>::iterator null2(null.end());
	// cout << *null1 << endl;
	// cout << *null2 << endl;
	// ft::vector<int> null_range(null1, null2);

	ft::vector<int> vec1(5, 10);
	cout << &vec1[0] << ": " << vec1[0] << endl;
	cout << &vec1[1] << ": " << vec1[1] << endl;
	cout << &vec1[2] << ": " << vec1[2] << endl;
	cout << &vec1[3] << ": " << vec1[3] << endl;
	cout << &vec1[4] << ": " << vec1[4] << endl;
	cout << &vec1[5] << ": " << vec1[5] << endl;	// out of range
	cout << endl;
	ft::vector<int>::iterator it1(vec1.begin());
	ft::vector<int>::iterator it2(vec1.end());
	// cout << *it1 << endl;
	// cout << *it2 << endl;							// out of range
	cout << *(it1 + 0) << endl;
	cout << *(it1 + 2) << endl;
	cout << *(2 + it1) << endl;
	cout << it2 - it1 << endl;
	// cout << *(it1 + 3) << endl;
	// cout << *(it2 - 0) << endl;
	// cout << *(it2 - 1) << endl;
	// cout << *(it2 - 2) << endl;
	// cout << *(it2 - 3) << endl;

	// ft::vector<int> range(it1, it2);
	// cout << &range[0] << ": " << range[0] << endl;
	// cout << &range[1] << ": " << range[1] << endl;
	// cout << &range[2] << ": " << range[2] << endl;
	// cout << &range[3] << ": " << range[3] << endl;
	// cout << &range[4] << ": " << range[4] << endl;
	// cout << endl;
	// cout << it1[0] << " " << it1[1] << endl;
	// cout << it1[2] << " " << it1[3] << endl;
	// cout << it1[4] << " " << it1[5] << endl;

	
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









////////////////////////////////////////////////////////////////////////////////////////////////










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
// 	// cout << &vec2[5] << ": " << vec2[5] << endl;
// 	cout << endl;

// 	std::vector<int>::iterator it(vec2.begin());
// 	std::vector<int>::iterator ite(vec2.end());
// 	cout << ite - it << endl;
// 	// cout << *it << endl;
// 	// cout << it[0] << " " << it[1] << endl;


// 	return 0;
// }