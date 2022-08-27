#ifndef CONTAINER_DETAILS_HPP
# define CONTAINER_DETAILS_HPP

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"

namespace ft
{
// AFFICHE LE DETAIL D'UN FT::VECTOR CONTAINER
	template<class T>
	void vector_details(const ft::vector<T> & v)
	{
		cout << endl << "----------------------- DETAILS ------------------------" << endl;
		cout << "Size = " << v.size() << " | Capacity = " << v.capacity() << endl << endl;
		if (v.size())
		{
			typename ft::vector<T>::const_iterator it = v.begin();
			typename ft::vector<T>::const_iterator ite = v.end();
			while (it != ite)
			{
				cout << "It  " << &*it << ": " << *it << endl;
				it++;
			}
			cout << "Ite " << &*ite << endl;
		}
		else
			cout << "vector container is empty" << endl << endl;

		cout << "--------------------------------------------------------" << endl;
	}

// AFFICHE LE DETAIL D'UN FT::MAP CONTAINER
	template<class T1, class T2>
	void map_details(const ft::map<T1,T2> & m)
	{
		cout << endl << "----------------------- DETAILS ------------------------" << endl;
		cout << "Size = " << m.size() << " | Sizeof(value_type) = " << sizeof(typename ft::map<T1,T2>::value_type) << endl << endl;
		if (m.size())
		{
			typename ft::map<T1,T2>::const_iterator it = m.begin();
			typename ft::map<T1,T2>::const_iterator ite = m.end();
			while (it != ite)
			{
				cout << "It  " << &*it << ": " << (*it).first << " | " << (*it).second << endl;
				it++;
			}
			cout << "Ite " << &*ite << endl;
		}
		else
			cout << "map container is empty" << endl << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}


// AFFICHE LE DETAIL D'UN STD::VECTOR CONTAINER COMME ft::vector_details()
template<class T>
void vector_details(const std::vector<T> & v)
{
	cout << endl << "----------------------- DETAILS ------------------------" << endl;
	cout << "Size = " << v.size() << " | Capacity = " << v.capacity() << endl << endl;
	if (v.size())
	{
		typename std::vector<T>::const_iterator it = v.begin();
		typename std::vector<T>::const_iterator ite = v.end();
		while (it != ite)
		{
			cout << "It  " << &*it << ": " << *it << endl;
			it++;
		}
		cout << "Ite " << &*ite << endl;
	}
	else
		cout << "vector container is empty" << endl << endl;

	cout << "--------------------------------------------------------" << endl;
}

// AFFICHE LE DETAIL D'UN STD::MAP CONTAINER COMME ft::map_details()
template<class T1, class T2>
void map_details(std::map<T1,T2> m)
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

#endif