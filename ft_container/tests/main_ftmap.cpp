#include <iostream>
#include <map>
using namespace std;
// #include <map>
#include "../map.hpp"
#include "../pair.hpp"
#include "../container_details.hpp"

/* 
Moreover, map is a node-based container, so each element goes into a distinct, 
separate allocation (so as to permit maximal iterator and reference non-invalidation). 
Elements are almost certainly not contiguous in memory, and probably scattered 
about in a way that reflects how you added them.

Practically, a map will be implemented as some type of balanced tree in order 
to achieve logarithmic lookup, insertion and deletion times.
*/

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
	// ************************************************************
	// ******************** TESTS CONSTRUCTORS ********************
	// #1
	ft::map<char,int> ft1;
	ft1['c'] = 3;
	ft1['b'] = 2;
	ft1['a'] = 1;

	for (ft::map<char,int>::iterator it = ft1.begin(); it != ft1.end(); ++it)
    	cout << it->first << " => " << it->second << endl;
	cout << endl;
	// for (ft::map<char,int>::reverse_iterator it = ft1.rbegin(); it != ft1.rend(); ++it)
    // 	std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int> ft2(ft1);
	for (ft::map<char,int>::iterator it = ft2.begin(); it != ft2.end(); ++it)
    	cout << it->first << " => " << it->second << '\n';
	cout << endl;

	ft::map<char,int> ft3;
	ft3 = ft2;
	ft3.insert(ft::make_pair<char,int>('u',6));
	ft3.insert(ft::make_pair<char,int>('r',19));
	ft3.insert(ft::make_pair<char,int>('r',12));
	for (ft::map<char,int>::iterator it = ft3.begin(); it != ft3.end(); ++it)
    	cout << it->first << " => " << it->second << '\n';
	cout << endl;

	ft::map<char,int> ft4(ft3.begin(), ft3.end());
	for (ft::map<char,int>::iterator it = ft4.begin(); it != ft4.end(); ++it)
    	cout << it->first << " => " << it->second << '\n';
	cout << endl;

	// ft::map_details(ft5);

	// // ************************************************************
	// // ******************* TESTS ELEMENT ACCESS *******************
	// cout << ft5['a'] << "|" << ft5['z'] << endl;
	// ft5['a'] = 1;
	// ft::map_details(ft5);

	// // ************************************************************
	// // ******************* TESTS COMPARISON SORT ******************
	// ft::map<char,int> ft6;
	// ft6.insert(ft::pair<char,int>('b',200));
	// ft6.insert(ft::pair<char,int>('d',800));
	// ft6.insert(ft::pair<char,int>('a',100));
	// ft6.insert(ft::pair<char,int>('c',400));
	// ft::map_details(ft6);

	// cout << ft6.key_comp()('a','b') << endl;
	// cout << ft6.key_comp()(2,1) << endl;

	// std::map<char,int> mymap;

	// mymap['b'] = 100;
	// std::map<char,int>::iterator first=mymap.begin();
	// cout << "B pair: " << mymap['b'] << " " << &*first++ << endl;
	// mymap['a'] = 200;
	// cout << "A pair: " << mymap['a'] << " " << &*first << endl;

	// // show content:
	// std::map<char,int>::iterator it2=mymap.begin();
	// std::map<char,int>::iterator it2e=mymap.end();
	// cout << "TEST: " << it2->first << &*it2 << endl;
	// cout << "TEST: " << it2e->first << &*it2 << endl;
	// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// {
	// 	std::cout << it->first << " => " << it->second << " (" << &*it << ")" << '\n';
	// }
	// cout << endl << endl;
	/* 
	Because map containers keep their elements ordered at all times, begin points to the element 
	that goes first following the container's sorting criterion.
		
		B pair: 100 0x7fc5dbd00b0c		<		ptr sur la pair b-100
		A pair: 200 0x7ffee28ffff4		<		ptr sur la pair a-200
		
		a => 200 (0x7fc5dbd00b3c)		<		ptr sur la pair a-200 après ordonnancement
		b => 100 (0x7fc5dbd00b0c)		<		ptr sur la pair b-100 après ordonnancement

		-------------------------------

		B pair: 100 0x7fda71402aec		<		ptr sur la pair b-100
		A pair: 200 0x7ffee2854ff4		<		ptr sur la pair a-200

		a => 200 (0x7fda71402b1c)		<		ptr sur la pair a-200 après ordonnancement
		b => 100 (0x7fda71402aec)		<		ptr sur la pair b-100 après ordonnancement

	*/

	return 0;
}





// int main()
// {
// 	ft::pair<int, char> p1;
// 	cout << "Paire1: ";
// 	cout << "	#1 = " << p1._first << "	";
// 	cout << "	#2 = " << p1._second << endl;
// 	ft::pair<int, Test> p2(p1);
// 	cout << "Paire2 ";
// 	cout << "	#1 = " << p2._first << "	";
// 	cout << "	#2 = " << p2._second << endl;
// 	ft::pair<int, float> p3(1, 4.31f);
// 	cout << "Paire3 ";
// 	cout << "	#1 = " << p3._first << "	";
// 	cout << "	#2 = " << p3._second << endl;
// 	ft::pair<int, Test> p4(p3);
// 	cout << "Paire4 ";
// 	cout << "	#1 = " << p4._first << "	";
// 	cout << "	#2 = " << p4._second << endl;
// 	ft::pair<char, Test> p5;
// 	cout << "Paire5 ";
// 	cout << "	#1 = " << p5._first << "	";
// 	cout << "	#2 = " << p5._second << endl;
// 	ft::pair<float, char> p6 = p3;
// 	cout << "Paire6 ";
// 	cout << "	#1 = " << p6._first << "	";
// 	cout << "	#2 = " << p6._second << endl;
// 	ft::pair<float, float> p7 = ft::make_pair<float,float>(1.1f,2.2f);
// 	cout << "Paire7 ";
// 	cout << "	#1 = " << p7._first << "	";
// 	cout << "	#2 = " << p7._second << endl;
// 	ft::make_pair<float,float>(1.1f,2.2f);
	
// 	cout << endl;
// 	p2.swap(p4);
// 	cout << "Paire2 ";
// 	cout << "	#1 = " << p2._first << "	";
// 	cout << "	#2 = " << p2._second << endl;
// 	cout << "Paire4 ";
// 	cout << "	#1 = " << p4._first << "	";
// 	cout << "	#2 = " << p4._second << endl;
// 	ft::swap(p2, p4);
// 	cout << "Paire2 ";
// 	cout << "	#1 = " << p2._first << "	";
// 	cout << "	#2 = " << p2._second << endl;
// 	cout << "Paire4 ";
// 	cout << "	#1 = " << p4._first << "	";
// 	cout << "	#2 = " << p4._second << endl;

// 	cout << endl;
// 	ft::pair<int,char> foo2(10,'z');
// 	ft::pair<int,char> bar2(90,'a');
// 	if (foo2==bar2) std::cout << "foo and bar are equal\n";
// 	if (foo2!=bar2) std::cout << "foo and bar are not equal\n";
// 	if (foo2< bar2) std::cout << "foo is less than bar\n";
// 	if (foo2> bar2) std::cout << "foo is greater than bar\n";
// 	if (foo2<=bar2) std::cout << "foo is less than or equal to bar\n";
// 	if (foo2>=bar2) std::cout << "foo is greater than or equal to bar\n";

// 	return 0;
// }






// int main()
// {
// 	cout << endl;
	
// 	std::map<char,int> std1;
// 	details(std1);

// 	std1.insert(std::pair<char,int>('a',100));
// 	details(std1);

// 	std1.insert(std::pair<char,int>('b',200));
// 	details(std1);
	
// 	std1.insert(std::pair<char,int>('c',400));
// 	details(std1);

// 	std1.insert(std::pair<char,int>('d',800));
// 	details(std1);

// 	std1.insert(std::pair<char,int>('e',1600));
// 	details(std1);

// 	std1.insert(std::pair<char,int>('f',3200));
// 	details(std1);

// 	std1.insert(std::pair<char,int>('g',6400));
// 	details(std1);

// 	ft::map<char,int> ft2;
// 	ft2['a']=10;
// 	ft2['b']=30;
// 	ft2['c']=50;
// 	ft2['d']=70;
// 	ft::map<char,int>::iterator it = ft2.begin();
// 	ft::map<char,int>::iterator ite = ft2.end();
// 	ft::map<char,int> ft3(it, ite);



// 	std::vector<int> vec1(10, 3);
// 	std::vector<int>::iterator it = vec1.begin();
// 	std::vector<int>::iterator ite = vec1.end();
// 	std::map<int, char> map2(it, ite);
// 	return 0;
// }