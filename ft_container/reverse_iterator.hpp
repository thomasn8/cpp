#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

using namespace std;

namespace ft
{
	template <typename Iterator>
	class reverse_iterator : public ft::iterator_traits<Iterator>
	{
		public:

		// MEMBER TYPES
			typedef	Iterator													iterator_type;
			typedef	typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename ft::iterator_traits<Iterator>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef	typename ft::iterator_traits<Iterator>::reference			reference;
			typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;


		// CONSTRUCTEURS/DESTRUCTEUR
			reverse_iterator(void) { _iterator = Iterator(); }
			explicit reverse_iterator(iterator_type it) : _iterator(it) {}
			reverse_iterator(const reverse_iterator<Iterator> & rev_it) { this->_iterator = rev_it._iterator; }
			virtual ~reverse_iterator() {}
		
		// ACCESSEURS
			// ...

		// // SURCHARGES
			value_type & operator*() { return *(_iterator - 1); }
			reference operator[](unsigned int index) { return *(this->_iterator - (index + 1)); }
			pointer operator->() { return (_iterator - 1);  }
			friend difference_type operator-(const reverse_iterator<Iterator> & a, const reverse_iterator<Iterator> & b) 
			{ 
				return static_cast<int>(b._iterator - a._iterator);
			}
			// friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

		// 	it & operator++() { ++this->_p; return *this; }
		// 	it operator++(value_type) { random_access_iterator_tag tmp(*this); this->_p++; return tmp; }
		// 	it & operator--() { --this->_p; return *this; }
		// 	it operator--(value_type) { random_access_iterator_tag tmp(*this); this->_p--; return tmp; }

		// 	bool operator==(const it & rhs) const { return this->_p == rhs._p; }
		// 	bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
		// 	bool operator<(const it & rhs) const { return this->_p < rhs._p; }
		// 	bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
		// 	bool operator>(const it & rhs) const { return this->_p > rhs._p; }
		// 	bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }

		// 	it operator+(int n)	const							// a + n
		// 	{
		// 		pointer tmp = this->_p;
		// 		if (n >= 0)
		// 		{
		// 			while (n--)
		// 				tmp++;
		// 		} 
		// 		else 
		// 		{
		// 			while (n++) 
		// 				tmp--;
		// 		}
		// 		return tmp;
		// 	}
		// 	friend it operator+(int n, const it & it)			// n + a
		// 	{
		// 		pointer tmp = it._p;
		// 		if (n >= 0)
		// 		{
		// 			while (n--)
		// 				tmp++;
		// 		} 
		// 		else 
		// 		{
		// 			while (n++) 
		// 				tmp--;
		// 		} 
		// 		return tmp; 
		// 	}
		// 	it & operator+=(int n)								// a += n 
		// 	{
		// 		if (n >= 0)
		// 		{
		// 			while (n--)
		// 				this->_p++;
		// 		} 
		// 		else 
		// 		{
		// 			while (n++) 
		// 				this->_p--;
		// 		} 
		// 		return *this; 
		// 	}
		// 	it operator-(int n)	const							// a - n
		// 	{
		// 		pointer tmp = this->_p;
		// 		if (n >= 0)
		// 		{
		// 			while (n--)
		// 				tmp--;
		// 		} 
		// 		else 
		// 		{
		// 			while (n++) 
		// 				tmp++;
		// 		} 
		// 		return tmp; 
		// 	}
		// 	it & operator-=(int n)								// a-= n
		// 	{
		// 		if (n >= 0)
		// 		{
		// 			while (n--)
		// 				this->_p--;
		// 		} 
		// 		else 
		// 		{
		// 			while (n++) 
		// 				this->_p++;
		// 		} 
		// 		return *this; 
		// 	}

		private :

			Iterator		_iterator;

	}; // end of template ft:reverse_iterator<T>

} // end of namespace ft::

#endif
