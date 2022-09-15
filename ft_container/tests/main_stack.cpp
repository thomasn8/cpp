// --------------------------------------------------------------------------
// -------------------------------- FT TESTS -------------------------------- 

#include <iostream>
using namespace std;
#include "../vector.hpp"
#include "../stack.hpp"
#include "../container_details.hpp"
#include <vector>

int main()
{
	ft::vector<int> v1(5, 999);
	ft::vector_details(v1);
	
	ft::stack<int> s1;
	cout << "size: " << s1.size() << endl;
	cout << "empty: " << s1.empty() << endl;
	
	cout << endl;

	ft::stack<int> s2(v1);
	cout << "size: " << s2.size() << endl;
	cout << "empty: " << s2.empty() << endl;
	cout << "top: " << s2.top() << endl;
	s2.top() -= 333;
	cout << "top: " << s2.top() << endl;
	s2.push(4);
	cout << "top: " << s2.top() << endl;
	s2.push(v1.front());
	cout << "top: " << s2.top() << endl;
	s2.pop();
	cout << "top: " << s2.top() << endl;

	cout << endl;

	cout << "size: " << s1.size() << endl;
	cout << "size: " << s2.size() << endl;
	s2.swap(s1);
	cout << "size: " << s1.size() << endl;
	cout << "size: " << s2.size() << endl;
	ft::swap(s1, s2);
	cout << "size: " << s1.size() << endl;
	cout << "size: " << s2.size() << endl;

	cout << endl;

	ft::vector<int> foo_v (3,100);   // three ints with a value of 100
	ft::vector<int> bar_v (2,200);   // two ints with a value of 200
	ft::stack<int> foo(foo_v);
	ft::stack<int> bar( bar_v);
	if (foo == bar) cout << "foo and bar are equal\n";
	if (foo != bar) cout << "foo and bar are not equal\n";
	if (foo  < bar) cout << "foo is less than bar\n";
	if (foo  > bar) cout << "foo is greater than bar\n";
	if (foo <= bar) cout << "foo is less than or equal to bar\n";
	if (foo >= bar) cout << "foo is greater than or equal to bar\n";

	return 0;
}