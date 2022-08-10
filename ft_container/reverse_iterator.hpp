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
			typedef reverse_iterator<Iterator>									iterator_category;
			typedef	iterator_category											rev_it;

		// CONSTRUCTEURS/DESTRUCTEUR
			reverse_iterator(void) { this->_iterator = Iterator(); }
			explicit reverse_iterator(Iterator it) : _iterator(it) {}
			reverse_iterator(const reverse_iterator<Iterator> & rev_it) { this->_iterator = rev_it._iterator; }
			virtual ~reverse_iterator() {}

		// SURCHARGES
			rev_it & operator=(const Iterator & src) { this->_iterator = src; return *this; }
			rev_it & operator=(const reverse_iterator<Iterator> & src) { this->_iterator = src._iterator; return *this; }
			value_type operator*() { return *(this->_iterator - 1); }
			value_type operator[](unsigned int index) { return *(this->_iterator - (index + 1)); }
			pointer operator->() { return (this->_iterator - 1);  }
			friend difference_type operator-(const reverse_iterator<Iterator> & a, const reverse_iterator<Iterator> & b) 
			{ 
				return static_cast<int>(b._iterator - a._iterator);
			}
			rev_it & operator++() { --this->_iterator; return *this; }
			rev_it operator++(value_type)
			{
				Iterator tmp = this->_iterator;
				this->_iterator--;
				return reverse_iterator<Iterator>(tmp);
			}
			rev_it & operator--() { ++this->_iterator; return *this; }
			rev_it operator--(value_type) 
			{
				Iterator tmp = this->_iterator;
				this->_iterator++;
				return reverse_iterator<Iterator>(tmp);
			}
			rev_it operator+(difference_type n)	const
			{
				Iterator tmp = this->_iterator;
				tmp -= n;
				return reverse_iterator<Iterator>(tmp);
			}
  			friend rev_it operator+(difference_type n, const reverse_iterator<Iterator> & rev_it)
			{
				Iterator tmp = rev_it._iterator;
				tmp -= n;
				return reverse_iterator<Iterator>(tmp);
			}
			rev_it operator-(difference_type n) const
			{
				Iterator tmp = this->_iterator;
				tmp += n;
				return reverse_iterator<Iterator>(tmp);
			}
			rev_it & operator+=(difference_type n) { this->_iterator -= n; return *this; }
			rev_it & operator-=(difference_type n) { this->_iterator += n; return *this; }

		private :

			Iterator		_iterator;

	}; // end of template ft:reverse_iterator<T>

} // end of namespace ft::

#endif
