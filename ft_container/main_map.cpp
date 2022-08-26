#include "vector.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "class_test/Test.hpp"
#include <vector>
#include <map>

using namespace std;

template<class T1, class T2>
void details(std::map<T1,T2> m)
{
	cout << endl << "----------------------- DETAILS ------------------------" << endl;
	cout << "Size = " << m.size() << " | Sizeof(value_type) = " << sizeof(typename std::map<T1,T2>::value_type) << endl << endl;
	if (m.size())
	{
		typename std::map<T1,T2>::iterator it = m.begin();
		typename std::map<T1,T2>::iterator ite = m.end();
		while (it != ite)
		{
			cout << "It  " << &*it << ": " << (*it).first << " | " << (*it).second << endl;
			it++;
		}
		cout << "Ite " << &*ite << endl;
	}
	else
		cout << "container is empty" << endl << endl;
	cout << "--------------------------------------------------------" << endl;
}

int main()
{
	cout << endl;
	ft::map<char,int> ft1;
	// ft1.details();

	ft1.insert(ft::pair<char,int>('a',100));
	// ft1.details();

	ft1.insert(ft::pair<char,int>('b',200));
	// ft1.details();
	
	ft1.insert(ft::pair<char,int>('c',400));
	// ft1.details();

	ft1.insert(ft::pair<char,int>('c',400));	// DOIT ETRE REFUSE CAR KEY 'c' EXISTE DEJA
	// ft1.details();

	ft1.insert(ft::pair<char,int>('d',800));
	// ft1.details();

	ft1.insert(ft::pair<char,int>('e',1600));
	// ft1.details();

	ft1.insert(ft::pair<char,int>('f',3200));
	// ft1.details();

	ft1.insert(ft::pair<char,int>('g',6400));
	// ft1.details();

	ft1['z'] = -100;
	// ft1.details();

	ft1['z'] = -100;
	ft1.details();

	ft::map<char,int> ft2(ft1.begin(), ft1.end());
	ft2.details();

	ft::map<char,int> ft3(ft1);
	ft3.details();

	ft::map<char,int> ft4 = ft1;
	ft4.details();

	ft::map<char,int> ft5;
	ft5.details();
	ft5.insert(ft::pair<char,int>('m',10000));
	ft5.details();
	ft5 = ft1;
	ft5.details();

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