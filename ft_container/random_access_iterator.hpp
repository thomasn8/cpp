#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include <iostream>
#include <iterator>

using namespace std;

namespace ft
{
	template <typename T>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		protected:
			T * _p;
		
		public:
		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) { /*cout << "random_access_iterator default" << endl;*/ }																				// default
			random_access_iterator(T * p) : _p(p) { /* cout << "random_access_iterator pointer" << endl; */ }																			// special
			random_access_iterator(const random_access_iterator & src) : _p(src.getP()) { /* cout << "random_access_iterator copy" << endl; */ }										// copy
			random_access_iterator & operator=(random_access_iterator const & src) { this->_p = src.getP(); return *this; /* cout << "random_access_iterator assign" << endl; */ }	// assign 
			virtual ~random_access_iterator() { /* cout << "random_access_iterator destruction" << endl; */ }
		// ACCESSORS
			T * getP() const { return this->_p; }

		// SURCHARGES
			random_access_iterator & operator++() { ++this->_p; return *this; }
			random_access_iterator operator++(T) { random_access_iterator tmp(*this); this->_p++; return tmp; }
			random_access_iterator & operator--() { --this->_p; return *this; }
			random_access_iterator operator--(T) { random_access_iterator tmp(*this); this->_p--; return tmp; }
			bool operator==(const random_access_iterator & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const random_access_iterator & rhs) const { return this->_p != rhs._p; }
			bool operator<(const random_access_iterator & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const random_access_iterator & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const random_access_iterator & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const random_access_iterator & rhs) const { return this->_p >= rhs._p; }
			T & operator[](unsigned int index) { return this->_p[index]; }	
			int & operator*() { return *_p; }
			random_access_iterator operator+(int n)								// a + n
			{
				T *tmp = this->_p;
				if (n >= 0)
				{
					while (n--)
						tmp++;
				} 
				else 
				{
					while (n++) 
						tmp--;
				} 
				return tmp; 
			}
			friend random_access_iterator operator+(int n, const random_access_iterator & it)	// n + a
			{
				T *tmp = it._p;
				if (n >= 0)
				{
					while (n--)
						tmp++;
				} 
				else 
				{
					while (n++) 
						tmp--;
				} 
				return tmp; 
			}
			random_access_iterator operator-(int n)								// a - n
			{
				T *tmp = this->_p;
				if (n >= 0)
				{
					while (n--)
						tmp--;
				} 
				else 
				{
					while (n++) 
						tmp++;
				} 
				return tmp; 
			}
			friend int operator-(const random_access_iterator & a, const random_access_iterator & b) { return static_cast<int>(a._p - b._p); }

			// a->m
			// *a = t (à tester)

			// ARITHMETIC
			// a += n
			// a -= n
			// *a++ Two iterators that compare equal, keep comparing equal after being both increased.
			// *a-- Can be decremented (if a dereferenceable iterator value precedes it).

	}; // end of template class

} // end of namespace

#endif
