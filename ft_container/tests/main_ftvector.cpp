// --------------------------------------------------------------------------
// -------------------------------- FT TESTS -------------------------------- 

#include <iostream>
using namespace std;
#include "../vector.hpp"
#include "../container_details.hpp"
#include "../class_test/Test.hpp"

int main()
{
	// ************************************************************
	// ******************** TESTS CONSTRUCTORS ********************
	ft::vector<int> v1;
	ft::vector_details(v1);
	ft::vector<int> v2(5, 999);
	ft::vector_details(v2);
	ft::vector<int> v3(v2.begin(), v2.end());
	ft::vector_details(v3);
	ft::vector<int> v4(3);
	ft::vector_details(v4);
	ft::vector<int> v5 = v4;
	ft::vector_details(v5);
	ft::vector<int> v6(3, 333);
	ft::vector_details(v6);
	v5 = v6;
	ft::vector_details(v5);
	v5 = v1;
	ft::vector_details(v5);
	v1 = v6;
	ft::vector_details(v1);

	// ************************************************************
	// ******************* TESTS ELEMENT ACCESS *******************


	// ************************************************************
	// **************** TESTS RELATIONAL OPERATORS ****************
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


	return 0;
}
