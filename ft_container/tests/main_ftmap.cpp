#include <iostream>
#include <map>
using namespace std;
#include "../map.hpp"
#include "../pair.hpp"
#include "../container_details.hpp"


int main()
{
	// ************************************************************
	// ******************** TESTS CONSTRUCTORS ********************
	// #1
	// ft::map<char,int> ft1;
	// ft1['c'] = 3;
	// ft1['b'] = 2;
	// ft1['a'] = 1;
	// ft::map_details(ft1);
	// ft1.erase( (++ft1.begin()) );
	// ft::map_details(ft1);

	// ft::map<char,int> ft2;
	// ft2['a'] = 17;
	// ft2['x'] = 7;
	// ft2['y'] = 8;
	// ft2['c'] = 5;
	// ft2['z'] = 9;
	// ft2['b'] = 19;
	// ft::map_details(ft2);
	// ft2.erase( (++ft2.begin()) );
	// ft::map_details(ft2);
	// ft2.erase( (ft2.begin()) );
	// ft::map_details(ft2);
	// ft2.erase( (++ft2.begin()) );
	// ft::map_details(ft2);
	// ft2.erase( (ft2.begin()) );
	// ft::map_details(ft2);

	ft::map<char,int> ft3;
	ft3['a'] = 17;
	ft3['b'] = 7;
	ft3['c'] = 5;
	ft3['d'] = 8;
	ft3['e'] = 9;
	ft3['f'] = 9;
	ft3['g'] = 9;
	// ft3['h'] = 9;
	// ft3['i'] = 9;
	// ft3['j'] = 9;
	// ft3['k'] = 9;
	ft3._rbt->print_tree();
	ft::map_details(ft3);
	ft3.erase(ft3.find('a'));
	ft::map_details(ft3);
	ft3.erase(ft3.find('c'));
	ft::map_details(ft3);
	ft3.erase(ft3.find('g'));

	// ft2['m'];
	// ft::pair<char,int> p1;
	// ft::pair<char,int> p2;
	// ft2.insert(p1);
	// ft2.insert(p2);
	// // ft::map_details(ft2);

	// ft1.insert(ft2.begin(), ft2.end());
	// // ft::map_details(ft1);

	// ft1.at('x') = 77777;
	// ft1.at('q');					// OUT OF RANGE
	// ft1.at('g');					// OUT OF RANGE
	// // ft::map_details(ft1);

	// ft1.clear();
	// ft1['c'] = 3;
	// ft1['b'] = 2;
	// ft1['a'] = 1;
	// ft::map_details(ft1);

	// ft::map_details(ft1);
	// ft::map_details(ft2);
	// ft1.swap(ft2);
	// ft::map_details(ft1);
	// ft::map_details(ft2);

	// ft::map<char,int>::iterator a = ft1.find('m');
	// cout << a->first << endl;
	// ft::map<char,int>::iterator b = ft2.find('b');
	// cout << b->first << endl;
	// ft::map<char,int>::iterator c = ft2.find('v');
	// cout << c->first << endl;

	// ft::map<char,int> ft3(ft1);
	// ft::map_details(ft3);

	// ft::map<char,int> ft4;
	// ft4 = ft2;
	// ft4.insert(ft::make_pair<char,int>('u',6));
	// ft4.insert(ft::make_pair<char,int>('r',19));
	// ft4.insert(ft::make_pair<char,int>('r',12));
	// ft::map_details(ft4);

	// ft::map<char,int> ft5(ft4.begin(), ft4.end());
	// ft::map_details(ft5);
	// for (ft::map<char,int>::const_iterator it = ft5.cbegin(); it != ft5.cend(); ++it)
    // 	std::cout << it->first << " => " << it->second << '\n';

	// ft::map<char,int> ft6;
	// ft6['m'] = 17;
	// ft6['c'] = 7;
	// ft6['p'] = 8;
	// ft6['a'] = 5;
	// ft6['h'] = 9;
	// ft6['e'] = 19;
	// ft6['n'] = 19;
	// ft6['t'] = 19;
	// ft6['s'] = 19;
	// ft6['y'] = 19;
	// ft::map_details(ft6);
	// ft6.lower_bound('f');
	// ft6.lower_bound('u');
	// ft6.lower_bound('c');
	// (*ft6.lower_bound('n')).second = 1;
	// ft6.lower_bound('z');
	
	// ft6.upper_bound('f');
	// ft6.upper_bound('u');
	// ft6.upper_bound('c');
	// ft6.upper_bound('n');
	// ft6.upper_bound('z');
	

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