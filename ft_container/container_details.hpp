#ifndef CONTAINER_DETAILS_HPP
# define CONTAINER_DETAILS_HPP

#include <vector>
#include <map>


//
// AFFICHE LE DETAIL D'UN STD::VECTOR CONTAINER COMME ft::vector_details()
//

/* ... */

//
// AFFICHE LE DETAIL D'UN STD::MAP CONTAINER COMME ft::map_details()
//
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