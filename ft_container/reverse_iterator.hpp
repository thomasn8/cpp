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
			reverse_iterator(void)
			{
				_iterator = Iterator();
				cout << endl << "(" << this << " - #1) rev_it created" << endl;
				return;
			}

			explicit reverse_iterator(iterator_type it) : _iterator(it)
			{
				// Constructs a reverse iterator from some original iterator it. 
				// The behavior of the constructed object replicates the original, 
				// except that it iterates through its pointed elements in the reverse order.
				cout << endl << "(" << this << " - #2) rev_it created" << endl;
				return;
			}

			reverse_iterator(const reverse_iterator<Iterator> & rev_it)
			{
				// Constructs a reverse iterator from some other reverse iterator. 
				// The constructed object keeps the same sense of iteration as rev_it.
				this->_iterator = rev_it._iterator;
				cout << endl << "(" << this << " - #3) rev_it created" << endl;
				return;
			}

			virtual ~reverse_iterator() {}
		
		// ACCESSEURS
			// ...

		// // SURCHARGES
		// 	it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
		// 	value_type & operator*() { return *_p; }
		// 	reference operator[](unsigned int index) { return this->_p[index]; }	
		// 	pointer operator->() { return _p;  }
		// 	friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

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
