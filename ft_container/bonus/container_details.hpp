#ifndef CONTAINER_DETAILS_HPP
# define CONTAINER_DETAILS_HPP

#include <iostream>
using namespace std;
#include "set.hpp"

namespace ft
{
// AFFICHE LE DETAIL D'UN FT::SET CONTAINER
	template<class T>
	void set_details(const ft::set<T> & s)
	{
		cout << endl << "----------------------- DETAILS ------------------------" << endl;
		cout << "Size = " << s.size() << endl << endl;
		if (s.size())
		{
			typename ft::set<T>::const_iterator it = s.cbegin();
			typename ft::set<T>::const_iterator ite = s.cend();
			while (it != ite)
			{
				cout << "It  " << it.getNode() << ": " << *it << endl;
				it++;
			}
			cout << "Ite " << ite.getNode() << endl;
		}
		else
			cout << "set container is empty" << endl << endl;
		cout << "--------------------------------------------------------" << endl;
	}
	template<class T>
	void set_rev_details(const ft::set<T> & s)
	{
		cout << endl << "----------------------- DETAILS ------------------------" << endl;
		cout << "Size = " << s.size() << endl << endl;
		if (s.size())
		{
			typename ft::set<T>::const_reverse_iterator it = s.crbegin();
			typename ft::set<T>::const_reverse_iterator ite = s.crend();
			while (it != ite)
			{
				cout << "It  " << it.base().getNode() << ": " << *it << endl;
				it++;
			}
			cout << "Its " << ite.base().getNode() << endl;
		}
		else
			cout << "set container is empty" << endl << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}

#endif