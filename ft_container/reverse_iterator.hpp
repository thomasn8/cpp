#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <type_traits>

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
			typedef int 														Test_SFINAE;	// force le choix de l'overload entre les constructeurs d'une outer-class


		// CONSTRUCTEURS/DESTRUCTEUR
			reverse_iterator() : _p(0), _base(0) 								// #1 default
			{
				cout << endl << "(" << this << " - #1) rev_it created" << endl;
			}

			explicit reverse_iterator(iterator_type it) :						// A FAIRE PLANTER AVEC UN SFINAE !!!!!
			// explicit reverse_iterator(iterator_type it,
			// typename std::enable_if< std::is_integral<Iterator>::value>::type * = 0) :
			// typename std::enable_if< not std::is_same<Iterator, ft::reverse_iterator<Iterator> >::value>::type * = 0) :
			// typename std::enable_if< ! std::is_reference<Iterator>::value >::type * = 0) :						// A FAIRE PLANTER AVEC UN SFINAE !!!!!
			_p(reinterpret_cast<pointer>(&(*it))), 
			_base(reinterpret_cast<pointer>(&(*it))),
			_diff(it.getDiff())													// #2 initalization
			{
				// Constructs a reverse iterator from some original iterator it. 
				// The behavior of the constructed object replicates the original, 
				// except that it iterates through its pointed elements in the reverse order.

				// this->_p = reinterpret_cast<pointer>(&(*it));
				// this->_base = reinterpret_cast<pointer>(&(*it));
				// std::cout << "HERE: " << this->_p << std::endl;
				// std::cout << "HERE: " << this->_diff << std::endl;
				cout << endl << "(" << this << " - #2) rev_it created" << endl;
			}

			// template <class Iter>												// #3 copy/type-cast 
  			// reverse_iterator(const reverse_iterator<Iter> & rev_it)	:			// checker que le type et l'argument soient du même type
			// // template <class Iter>												// #3 copy/type-cast 
  			// // reverse_iterator(const reverse_iterator<Iter> & rev_it,
			// // typename Iter::Test_SFINAE = 0) :			// checker que le type et l'argument soient du même type
			// _p(rev_it.getP()),													// pour s'assurer qu'il faut utiliser ce constructeur
			// _base(rev_it.getBase()),
			// _diff(rev_it.getDiff())
			// {
			// 	// Constructs a reverse iterator from some other reverse iterator. 
			// 	// The constructed object keeps the same sense of iteration as rev_it.
			// 	// this->_p = rev_it.getP();													// pour s'assurer qu'il faut utiliser ce constructeur
			// 	// this->_base = rev_it.getBase();
			// 	// this->_diff = rev_it.getDiff();
			// 	cout << endl << "(" << this << " - #3) rev_it created" << endl;
			// }
			
			virtual ~reverse_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			pointer getBase() const { return this->_base; }
			difference_type getDiff() const { return this->_diff; }

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
			pointer _p;
			pointer _base;
			difference_type _diff;

	}; // end of template ft:reverse_iterator<T>

} // end of namespace ft::

#endif
