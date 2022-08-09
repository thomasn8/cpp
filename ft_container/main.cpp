#include "vector.hpp"
#include "Test.hpp"
#include "iterator_traits.hpp"

using namespace std;

template<class It>
void my_reverse(It first, It last)
{
    typename ft::iterator_traits<It>::difference_type n = last - first;

    for (--n; n > 0; n -= 2) 
	{
        typename ft::iterator_traits<It>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

int main()
{
	// int a = 1;
  	// int* p = &a;
	// int b = *p;
	// (void) b;
	
	// int x = 1;
	// int y = *x;

	// ft::vector<int> null;
	// ft::vector<int>::iterator null1(null.begin());
	// ft::vector<int>::iterator null2(null.end());
	// cout << *null1 << endl;
	// cout << *null2 << endl;
	// ft::vector<int> null_range(null1, null2);

	// const ft::vector<int> vec1(5, 10);
	// ft::vector<int> vec1(5, 10);
	// // ft::vector<int>::iterator it = vec1.begin();
	// ft::vector<int>::const_iterator it = vec1.begin();
	// cout << *it << endl;
	// *it = 999;
	// cout << *it << endl;

	// ft::vector<int> vec1(5, 10);
	// cout << &vec1[0] << ": " << vec1[0] << endl;
	// cout << &vec1[1] << ": " << vec1[1] << endl;
	// cout << &vec1[2] << ": " << vec1[2] << endl;
	// cout << &vec1[3] << ": " << vec1[3] << endl;
	// cout << &vec1[4] << ": " << vec1[4] << endl;
	
	// cout << &vec1[5] << ": " << vec1[5] << endl;	// out of range
	// cout << endl;
	// ft::vector<int>::iterator it1(vec1.begin());
	// ft::vector<int>::iterator it2(vec1.end());
	// cout << *it1 << endl;
	// cout << *it2 << endl;							// out of range
	// cout << *(it1 + 0) << endl;
	// cout << *(it1 + 2) << endl;
	// cout << *(2 + it1) << endl;
	// cout << it2 - it1 << endl;
	// cout << *(it1 + 3) << endl;
	// cout << *(it2 - 0) << endl;
	// cout << *(it2 - 1) << endl;
	// cout << *(it2 - 2) << endl;
	// cout << *(it2 - 3) << endl;
	// it1 += 4;
	// cout << *it1 << endl;
	// it1--;
	// --it1;
	// cout << *it1 << endl;
	// it1 -= 2;
	// cout << *it1 << endl;
	// *it1 = 100;

	// ft::iterator_traits<int *>::value_type num = 1;
	// cout << num << endl;

    // my_reverse(it1, it2);
	// for (int n = 0; n < 5; n++)
	// 	cout << vec1[n] << endl;

	// ft::vector<int> vec3(5, 10);
	// ft::vector<int>::iterator it(vec3.begin());
	// ft::vector<int>::iterator ite(vec3.end());
	// ft::vector<int> range(it, ite);
	// cout << &range[0] << ": " << range[0] << endl;
	// cout << &range[1] << ": " << range[1] << endl;
	// cout << &range[2] << ": " << range[2] << endl;
	// cout << &range[3] << ": " << range[3] << endl;
	// cout << &range[4] << ": " << range[4] << endl;
	// cout << &range[5] << ": " << range[5] << endl;
	// cout << endl;

	// ft::vector<int> copy(vec3);
	// cout << &vec3[0] << ": " << vec3[0] << endl;
	// cout << &vec3[1] << ": " << vec3[1] << endl;
	// cout << &vec3[2] << ": " << vec3[2] << endl;
	// cout << &vec3[3] << ": " << vec3[3] << endl;
	// cout << &vec3[4] << ": " << vec3[4] << endl;
	// cout << &copy[0] << ": " << copy[0] << endl;
	// cout << &copy[1] << ": " << copy[1] << endl;
	// cout << &copy[2] << ": " << copy[2] << endl;
	// cout << &copy[3] << ": " << copy[3] << endl;
	// cout << &copy[4] << ": " << copy[4] << endl;
	
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
	ft::vector<Test> vec3(3, 10);
	cout << endl;

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

	// const ft::vector<int> fill(10, 1);
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &fill[i] << ": " << fill[i] << endl;
	// }
	// // *fill = 111;
	// // fill[9] = 999;

	// ft::vector<int>::const_iterator it = fill.begin();
	// ft::vector<int>::const_iterator ite = fill.end();
	// ft::vector<int> range(it, ite);
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &range[i] << ": " << range[i] << endl;
	// }

	ft::vector<int> fill(10, 1);
	for (int i = 0; i < 10; i++)
	{
		cout << &fill[i] << ": " << fill[i] << endl;
	}
	*fill = 111;
	fill[9] = 999;

	ft::vector<int>::iterator it = fill.begin();
	ft::vector<int>::iterator ite = fill.end();
	// ft::vector<int> range(it, ite);
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &range[i] << ": " << range[i] << endl;
	// }

	// ft::vector<int> copy(fill);
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &copy[i] << ": " << copy[i] << endl;
	// }

	// ft::vector<int> assign = copy;
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &assign[i] << ": " << assign[i] << endl;
	// }

	// cout << endl << "HERE: " << it.getP() << endl;
	// cout << endl << "HERE: " << &(*it) << endl;
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << &fill[i] << ": " << fill[i] << endl;
	// }



	// **************************************************************
	// CONSTR 1-2 FONCTIONNE MAIS PAS LE 3
	typedef ft::vector<int>::iterator	iter_type;
	ft::reverse_iterator<iter_type> rev_it1(it);
	// ft::reverse_iterator<iter_type> const & rev_it1_ref = rev_it1;
	// ft::reverse_iterator< ft::reverse_iterator<iter_type> > rev_it2(rev_it1_ref);
	// typedef ft::reverse_iterator<iter_type>	rev;
	// ft::reverse_iterator< rev > rev_it2(rev_it1);
	// **************************************************************

	return 0;
}









////////////////////////////////////////////////////////////////////////////////////////////////










// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
// 	// std::vector<int> vec2(5, 10);	
// 	// cout << &vec2[0] << ": " << vec2[0] << endl;
// 	// cout << &vec2[1] << ": " << vec2[1] << endl;
// 	// cout << &vec2[2] << ": " << vec2[2] << endl;
// 	// cout << &vec2[3] << ": " << vec2[3] << endl;
// 	// cout << &vec2[4] << ": " << vec2[4] << endl;
// 	// // cout << &vec2[5] << ": " << vec2[5] << endl;
// 	// cout << endl;

// 	// std::vector<int>::iterator it(vec2.begin());
// 	// // std::vector<int>::iterator ite(vec2.end());
// 	// // cout << ite - it << endl;
// 	// // cout << *it << endl;
// 	// *(it + 1) = 11;
// 	// cout << it[0] << " " << it[1] << endl;

// 	// // std::vector<int> vec1(5, 10);
// 	// const std::vector<int> vec1(5, 10);
// 	// // std::vector<int>::iterator it = vec1.begin();
// 	// std::vector<int>::const_iterator it = vec1.begin();
// 	// cout << *it << endl;
// 	// *it = 999;
// 	// cout << *it << endl;


// 	// const std::vector<int> fill(10, 1);
// 	// for (int i = 0; i < 10; i++)
// 	// {
// 	// 	cout << &fill[i] << ": " << fill[i] << endl;
// 	// }
// 	// fill[9] = 999;

// 	// std::vector<int>::const_iterator it = fill.begin();
// 	// std::vector<int>::const_iterator ite = fill.end();
// 	// std::vector<int> range(it, ite);
// 	// for (int i = 0; i < 10; i++)
// 	// {
// 	// 	cout << &range[i] << ": " << range[i] << endl;
// 	// }

// 	return 0;
// }