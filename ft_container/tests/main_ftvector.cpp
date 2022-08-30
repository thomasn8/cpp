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
	// ft::vector<int> v1;
	// ft::vector_details(v1);
	// ft::vector<int> v2(5, 999);
	// ft::vector_details(v2);
	// ft::vector<int> v3(v2.begin(), v2.end());
	// ft::vector_details(v3);
	// ft::vector<int> v4(3);
	// ft::vector_details(v4);
	// ft::vector<int> v5 = v4;
	// ft::vector_details(v5);
	// ft::vector<int> v6(3, 333);
	// ft::vector_details(v6);
	// v5 = v6;
	// ft::vector_details(v5);
	// v5 = v1;
	// ft::vector_details(v5);
	// v1 = v6;
	// ft::vector_details(v1);

	// ************************************************************
	// ******************* TESTS ELEMENT ACCESS *******************
	// ft::vector<int> v10;
	// for (int i = 0; i < 10; i++)
	// 	v10.push_back(i);
	// ft::vector_details(v10);
	// cout << "v10[0] = " << v10[0] << endl;
	// cout << "v10[9] = " << v10[9] << endl;
	// cout << "v10[10] = " << v10[10] << endl;
	// cout << "front() = " << v10.front() << endl;
	// cout << "back() = " << v10.back() << endl;
	// cout << "data() = " << &*v10.data() << " = " << *v10.data() << endl;
	// cout << "at(0) = " << v10.at(0) << endl;
	// cout << "at(1) = " << v10.at(1) << endl;

	// ************************************************************
	// ************************* CAPACITY *************************
	// ft::vector<int> v20;
	// ft::vector_details(v20);
	// cout << "size = " << v20.size() << endl;
	// cout << "empty ? " << v20.empty() << endl;
	// cout << "capacity = " << v20.capacity() << endl;
	// cout << "max size = " << v20.max_size() << endl;
	// ft::vector<int> v10;
	// for (int i = 0; i < 10; i++)
	// 	v10.push_back(i);
	// ft::vector_details(v10);
	// cout << "size = " << v10.size() << endl;
	// cout << "empty ? " << v10.empty() << endl;
	// cout << "capacity = " << v10.capacity() << endl;
	// cout << "max size = " << v10.max_size() << endl;
	
	// v20.shrink_to_fit();
	// ft::vector_details(v20);
	// v10.shrink_to_fit();
	// ft::vector_details(v10);
	// ft::vector<int> v30;
	// ft::vector<int> v40(4,10);
	// ft::vector<int> v50(40,10);
	
	// v30.reserve(10);
	// v40.reserve(10);
	// v50.reserve(10);
	// ft::vector_details(v30);
	// ft::vector_details(v40);
	// ft::vector_details(v50);
	// ft::vector<int> v60(4,10);
	// ft::vector_details(v60);
	// v60.reserve(4);
	// ft::vector_details(v60);

	// ft::vector<int> v70;
	// v70.resize(1, 1);
	// v70.resize(10, 10);
	// v70.resize(5, 5);
	// ft::vector_details(v70);
	// ft::vector<int> v80(5,10);
	// v80.resize(0, 9);
	// v80.resize(100, 9);
	// v80.resize(50, 9);
	// ft::vector_details(v80);

	// ft::vector<int> v80(5,10);
	// v80.resize(4, 9);
	// ft::vector_details(v80);
	// v80.resize(0, 9);
	// ft::vector_details(v80);
	// v80.resize(100, 9);
	// ft::vector_details(v80);
	// v80.resize(50, 9);
	// ft::vector_details(v80);

	// ************************************************************
	// ************************ MODIFIERS *************************
	// // 1. clear (partout)
	// ft::vector<int> v100;
	// ft::vector<int> v110(1000, 110);
	// ft::vector<int> v120(v110);
	// v100.clear();
	// v110.clear();
	// v120.clear();
	// ft::vector<int> v130(v110);
	// v130.clear();
	// ft::vector_details(v100);
	// ft::vector_details(v110);
	// ft::vector_details(v120);
	// ft::vector_details(v130);

	// // 2. assign (operator=, insert)
	// ft::vector<int> v200;
	// v200.assign(10,200);
	// ft::vector_details(v200);
	// ft::vector<int> v210(10,210);
	// v210.assign(5,9);
	// ft::vector_details(v210);
	// v210.assign(25,9);
	// ft::vector_details(v210);
	// v210.clear();
	// ft::vector_details(v210);
	// v210.assign(v200.begin(),v200.end());
	// ft::vector_details(v210);
	// v210.clear();
	// ft::vector<int> v220;
	// v220.assign(v210.begin(),v210.end());
	// ft::vector_details(v220);
	// ft::vector<int> v230;
	// ft::vector<int> v240;
	// v240.assign(v230.begin(),v230.end());
	// ft::vector_details(v240);

	// 3. erase (resize)
	ft::vector<int> v300;
	v300.assign(5,5);
	ft::vector_details(v300);
	v300.erase(v300.end() - 2);
	ft::vector_details(v300);
	v300.erase(v300.begin());
	ft::vector_details(v300);
	v300.erase(v300.begin(), v300.end());
	ft::vector_details(v300);
	v300.assign(5,5);
	v300.erase(v300.begin()+1, v300.end()-1);
	ft::vector_details(v300);
	v300.assign(5,5);
	cout << &*(v300.erase(v300.begin()+2, v300.end()-2)) << endl;
	ft::vector_details(v300);
	cout << &*(v300.erase(v300.begin(), v300.end()))<< endl;
	ft::vector_details(v300);
	cout << &*(v300.erase(v300.begin(), v300.end()))<< endl;
	ft::vector_details(v300);

	// 4. insert (resize)
	// 5. push_back
	// 6. pop_back
	// 7. swap

	// ************************************************************
	// **************** TESTS RELATIONAL OPERATORS ****************
	// ft::vector<int> foo (3,100);   // three ints with a value of 100
	// ft::vector<int> bar (2,200);   // two ints with a value of 200

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


	return 0;
}
