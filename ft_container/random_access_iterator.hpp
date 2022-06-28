#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include <iostream>
#include <iterator>

using namespace std;

namespace ft
{
	// class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	template <typename T>
	class random_access_iterator
	{		
		public:

		// MEMBER TYPES
			typedef	random_access_iterator	it;
		    typedef T						value_type;
			typedef int						difference_type;
			typedef T *						pointer;
			typedef T &						reference;
			// typedef Category  iterator_category;

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) {}															// default
			random_access_iterator(T * p) : _p(p) {}													// special
			random_access_iterator(const random_access_iterator & src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSORS
			pointer getP() const { return this->_p; }

		// SURCHARGES
			it & operator=(random_access_iterator const & src) { this->_p = src.getP(); return *this; }	// assign 
			it & operator++() { ++this->_p; return *this; }
			it operator++(T) { random_access_iterator tmp(*this); this->_p++; return tmp; }
			it & operator--() { --this->_p; return *this; }
			it operator--(T) { random_access_iterator tmp(*this); this->_p--; return tmp; }
			bool operator==(const random_access_iterator & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const random_access_iterator & rhs) const { return this->_p != rhs._p; }
			bool operator<(const random_access_iterator & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const random_access_iterator & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const random_access_iterator & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const random_access_iterator & rhs) const { return this->_p >= rhs._p; }
			reference operator[](unsigned int index) { return this->_p[index]; }	
			int & operator*() { return *_p; }
			pointer operator->() { return _p;  }
			friend int operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); } // a - b
			it operator+(int n)	const							// a + n
			{
				pointer tmp = this->_p;
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
			friend it operator+(int n, const it & it)			// n + a
			{
				pointer tmp = it._p;
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
			it & operator+=(int n)								// a += n 
			{
				if (n >= 0)
				{
					while (n--)
						this->_p++;
				} 
				else 
				{
					while (n++) 
						this->_p--;
				} 
				return *this; 
			}
			it operator-(int n)	const							// a - n
			{
				pointer tmp = this->_p;
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
			it & operator-=(int n)								// a-= n
			{
				if (n >= 0)
				{
					while (n--)
						this->_p--;
				} 
				else 
				{
					while (n++) 
						this->_p++;
				} 
				return *this; 
			}

		protected:
			pointer _p;

	}; // end of template ft:random_access_iterator<T>

} // end of namespace ft::

#endif
