#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>
using namespace std;

namespace ft
{
	template <class T1, class T2> 
	class pair
	{
		public : 
		typedef T1				first_type;
		typedef T2				second_type;
		first_type 	 _first;
		second_type	 _second;
		pair() : _first(first_type()), _second(second_type()) {}
		template<class U, class V> 
		pair(const pair<U, V> & pr) : _first(pr._first), _second(pr._second) {}
		pair(const first_type & a, const second_type & b) : _first(a), _second(b) {}
		pair & operator=(const pair & pr) { this->_first = pr._first; this->_second = pr._second; return *this; }
		~pair() {}
		void swap(pair & pr)
		{
			// pair<first_type, second_type> tmp = pr;
			// pair tmp = pr;
			pair tmp = pr;
			pr._first = this->_first;
			pr._second = this->_second;
			this->_first = tmp._first;
			this->_second = tmp._second;
		}

	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) { return (pair<T1,T2>(x,y)); }

}

#endif
