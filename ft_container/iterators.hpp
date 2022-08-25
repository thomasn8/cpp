#ifndef ITERATORS_HPP
# define ITERATORS_HPP

namespace ft
{
	class random_access_iterator_tag {};

	template <typename T>
	class random_access_iterator
	{
		public:

		// MEMBER TYPES
		    typedef T							value_type;
			typedef int							difference_type;
			typedef T *							pointer;
			typedef T &							reference;
			typedef random_access_iterator	 	iterator_category;
			typedef	iterator_category			it;
			typedef int 						SFINAE_condition;	// pour le constructeur de vector avec iterateur

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) {}											// default
			random_access_iterator(pointer p) : _p(p) {}								// special
			random_access_iterator(reference src) : _p(src.getP()) {}					// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			difference_type getDiff() const { return sizeof(value_type); }

		// SURCHARGES
			it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
			reference operator*() { return *_p; }
			reference operator*() const { return *_p; }
			reference operator[](unsigned int index) { return this->_p[index]; }	
			pointer operator->() { return _p;  }
			friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }
			it & operator++() { ++this->_p; return *this; }
			it operator++(value_type) { it tmp(*this); this->_p++; return tmp; }
			it & operator--() { --this->_p; return *this; }
			it operator--(value_type) { it tmp(*this); this->_p--; return tmp; }
			bool operator==(const it & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
			bool operator<(const it & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const it & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }
			it operator+(difference_type n)	const { pointer tmp(this->_p + n); return tmp; }
			friend it operator+(difference_type n, const it & it) { pointer tmp(it._p + n); return tmp; }
			it operator-(difference_type n)	const { pointer tmp(this->_p - n); return tmp; }
			it & operator+=(difference_type n) { it tmp(this->_p + n); this->_p = tmp.getP(); return *this; }
			it & operator-=(difference_type n) { it tmp(this->_p - n); this->_p = tmp.getP(); return *this; }

		protected :
			pointer _p;
	};

	template<typename T>
	struct iterator_traits
	{
		public :
			typedef typename	T::difference_type 		difference_type;
			typedef typename 	T::value_type			value_type;
			typedef typename	T::pointer				pointer;
			typedef typename	T::reference			reference;
			typedef typename	T::iterator_category	iterator_category;
	};
	template <typename T>
	struct iterator_traits<T *>
	{
		public :
			typedef int								difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};
	template <typename T>
	struct iterator_traits<const T *>
	{
		public :
			typedef int								difference_type;
			typedef T								value_type;
			typedef const T *						pointer;
			typedef const T &						reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};

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
