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
			reverse_iterator(void) { this->_iterator = iterator_type(); }
			explicit reverse_iterator(iterator_type it) : _iterator(it) {}
			reverse_iterator(const reverse_iterator<iterator_type> & rev_it) { this->_iterator = rev_it._iterator; }
			virtual ~reverse_iterator() {}

		// MEMBER FUNCTION
			iterator_type base() const { return this->_iterator; }

		// SURCHARGES
			rev_it & operator=(const iterator_type & src) { this->_iterator = src; return *this; }
			rev_it & operator=(const reverse_iterator<Iterator> & src) { this->_iterator = src._iterator; return *this; }
			value_type operator*() { return *(this->_iterator - 1); }
			value_type operator*() const { return *(this->_iterator - 1); }
			value_type operator[](unsigned int index) { return *(this->_iterator - (index + 1)); }
			pointer operator->() { return (this->_iterator - 1);  }
			friend difference_type operator-(const reverse_iterator<iterator_type> & a, const reverse_iterator<iterator_type> & b) 
			{ 
				return static_cast<int>(b._iterator - a._iterator);
			}
			rev_it & operator++() { --this->_iterator; return *this; }
			rev_it operator++(value_type)
			{
				iterator_type tmp = this->_iterator;
				this->_iterator--;
				return reverse_iterator<iterator_type>(tmp);
			}
			rev_it & operator--() { ++this->_iterator; return *this; }
			rev_it operator--(value_type) 
			{
				iterator_type tmp = this->_iterator;
				this->_iterator++;
				return reverse_iterator<iterator_type>(tmp);
			}
			rev_it operator+(difference_type n)	const
			{
				iterator_type tmp = this->_iterator;
				tmp -= n;
				return reverse_iterator<iterator_type>(tmp);
			}
  			friend rev_it operator+(difference_type n, const reverse_iterator<iterator_type> & rev_it)
			{
				iterator_type tmp = rev_it._iterator;
				tmp -= n;
				return reverse_iterator<iterator_type>(tmp);
			}
			rev_it operator-(difference_type n) const
			{
				iterator_type tmp = this->_iterator;
				tmp += n;
				return reverse_iterator<iterator_type>(tmp);
			}
			rev_it & operator+=(difference_type n) { this->_iterator -= n; return *this; }
			rev_it & operator-=(difference_type n) { this->_iterator += n; return *this; }

		// NON-MEMBER FUNCTION OVERLOADS
			friend bool operator==(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator == rhs._iterator; }
			friend bool operator!=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator != rhs._iterator; }
			friend bool operator<(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator < rhs._iterator; }
			friend bool operator<=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator <= rhs._iterator; }
			friend bool operator>(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator > rhs._iterator; }
			friend bool operator>=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return lhs._iterator >= rhs._iterator; }

		private :
			iterator_type		_iterator;

	};

}

#endif
