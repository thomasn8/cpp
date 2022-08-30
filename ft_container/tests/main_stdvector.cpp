// --------------------------------------------------------------------------
// -------------------------------- STD TESTS -------------------------------- 

#include <iostream>
using namespace std;
#include <vector>
#include "../container_details.hpp"
#include "../class_test/Test.hpp"

int main()
{
	// ************************************************************
	// ******************** TESTS CONSTRUCTORS ********************
	// std::vector<int> v1;
	// vector_details(v1);
	// std::vector<int> v2(5, 999);
	// vector_details(v2);
	// std::vector<int> v3(v2.begin(), v2.end());
	// vector_details(v3);
	// std::vector<int> v4(3);
	// vector_details(v4);
	// std::vector<int> v5 = v4;
	// vector_details(v5);
	// std::vector<int> v6(3, 333);
	// vector_details(v6);
	// v5 = v6;
	// vector_details(v5);
	// v5 = v1;
	// vector_details(v5);
	// v1 = v6;
	// vector_details(v1);

	// ************************************************************
	// ******************* TESTS ELEMENT ACCESS *******************
	// std::vector<int> v10;
	// for (int i = 0; i < 10; i++)
	// 	v10.push_back(i);
	// vector_details(v10);
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
	// std::vector<int> v20;
	// vector_details(v20);
	// cout << "size = " << v20.size() << endl;
	// cout << "empty ? " << v20.empty() << endl;
	// cout << "capacity = " << v20.capacity() << endl;
	// cout << "max size = " << v20.max_size() << endl;
	// std::vector<int> v10;
	// for (int i = 0; i < 10; i++)
	// 	v10.push_back(i);
	// vector_details(v10);
	// cout << "size = " << v10.size() << endl;
	// cout << "empty ? " << v10.empty() << endl;
	// cout << "capacity = " << v10.capacity() << endl;
	// cout << "max size = " << v10.max_size() << endl;

	// v20.shrink_to_fit();
	// vector_details(v20);
	// v10.shrink_to_fit();
	// vector_details(v10);
	// std::vector<int> v30;
	// std::vector<int> v40(4,10);
	// std::vector<int> v50(40,10);
	
	// v30.reserve(10);
	// v40.reserve(10);
	// v50.reserve(10);
	// vector_details(v30);
	// vector_details(v40);
	// vector_details(v50);
	// std::vector<int> v60(4,10);
	// vector_details(v60);
	// v60.reserve(4);
	// vector_details(v60);

	// std::vector<int> v70;
	// v70.resize(1, 1);
	// v70.resize(10, 10);
	// v70.resize(5, 5);
	// vector_details(v70);
	// std::vector<int> v80(5,10);
	// v80.resize(0, 9);
	// v80.resize(100, 9);
	// v80.resize(50, 9);
	// vector_details(v80);

	// std::vector<int> v80(5,10);
	// v80.resize(4, 9);
	// vector_details(v80);
	// v80.resize(0, 9);
	// vector_details(v80);
	// v80.resize(100, 9);
	// vector_details(v80);
	// v80.resize(50, 9);
	// vector_details(v80);

	// ************************************************************
	// ************************ MODIFIERS *************************
	// // 1. clear (partout)
	// std::vector<int> v100;
	// std::vector<int> v110(1000, 110);
	// std::vector<int> v120(v110);
	// v100.clear();
	// v110.clear();
	// v120.clear();
	// std::vector<int> v130(v110);
	// v130.clear();
	// vector_details(v100);
	// vector_details(v110);
	// vector_details(v120);
	// vector_details(v130);

	// // 2. assign (operator=, insert)
	// std::vector<int> v200;
	// v200.assign(10,200);
	// vector_details(v200);
	// std::vector<int> v210(10,210);
	// v210.assign(5,9);
	// vector_details(v210);
	// v210.assign(25,9);
	// vector_details(v210);
	// v210.clear();
	// vector_details(v210);
	// v210.assign(v200.begin(),v200.end());
	// vector_details(v210);
	// v210.clear();
	// std::vector<int> v220;
	// v220.assign(v210.begin(),v210.end());
	// vector_details(v220);
	// std::vector<int> v230;
	// std::vector<int> v240;
	// v240.assign(v230.begin(),v230.end());
	// vector_details(v240);

	// 3. erase (resize)
	// std::vector<int> v300;
	// v300.assign(5,5);
	// vector_details(v300);
	// v300.erase(v300.end() - 2);
	// vector_details(v300);
	// v300.erase(v300.begin());
	// vector_details(v300);
	// v300.erase(v300.begin(), v300.end());
	// vector_details(v300);
	// v300.assign(5,5);
	// v300.erase(v300.begin()+1, v300.end()-1);
	// vector_details(v300);
	// v300.assign(5,5);
	// cout << &*v300.erase(v300.begin()+2, v300.end()-2)<< endl;
	// vector_details(v300);
	// cout << &*v300.erase(v300.begin(), v300.end())<< endl;
	// vector_details(v300);
	// cout << &*v300.erase(v300.begin(), v300.end())<< endl;
	// vector_details(v300);

	// ************************************************************
	// **************** TESTS RELATIONAL OPERATORS ****************
	// std::vector<int> foo (3,100);   // three ints with a value of 100
	// std::vector<int> bar (2,200);   // two ints with a value of 200

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
