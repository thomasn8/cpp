#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
	class random_access_iterator_tag {};

	template <typename T, typename U>
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
			random_access_iterator() : _p(0) {}										// default
			random_access_iterator(pointer p) : _p(p) {}							// special
			random_access_iterator(reference src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			difference_type getDiff() const { return sizeof(value_type); }

		// SURCHARGES
			it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
			const value_type & operator*() { return *_p; }
			reference operator[](unsigned int index) { return this->_p[index]; }	
			pointer operator->() { return _p;  }
			friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

			it & operator++() { ++this->_p; return *this; }
			it operator++(value_type) { random_access_iterator tmp(*this); this->_p++; return tmp; }
			it & operator--() { --this->_p; return *this; }
			it operator--(value_type) { random_access_iterator tmp(*this); this->_p--; return tmp; }

			bool operator==(const it & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
			bool operator<(const it & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const it & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }

			it operator+(difference_type n)	const { pointer tmp(this->_p + n); return tmp; }					// a + n
			friend it operator+(difference_type n, const it & it) { pointer tmp(it._p + n); return tmp; }		// n + a
			it operator-(difference_type n)	const { pointer tmp(this->_p - n); return tmp; }					// a - n
			it & operator+=(difference_type n) { it tmp(this->_p + n); this->_p = tmp.getP(); return *this; }	// a += n 
			it & operator-=(difference_type n) { it tmp(this->_p - n); this->_p = tmp.getP(); return *this; }	// a-= n

		protected:
			pointer _p;

	}; // end of template ft:random_access_iterator<T>


	// CONST SPECIALIZED
	template <typename T>
	class random_access_iterator<T, int>
	{
		public:

		// MEMBER TYPES
		    typedef T							value_type;
			typedef int							difference_type;
			typedef const T *					pointer;
			typedef const T &					reference;
			typedef random_access_iterator		iterator_category;
			typedef	iterator_category			it;
			typedef int 						SFINAE_condition;	// pour le constructeur de vector avec iterateur

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) {}										// default
			random_access_iterator(pointer p) : _p(p) {}							// special
			random_access_iterator(reference src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			difference_type getDiff() const { return sizeof(value_type); }

		// SURCHARGES
			it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
			value_type & operator*() { return *_p; }
			reference operator[](unsigned int index) { return this->_p[index]; }	
			pointer operator->() { return _p;  }
			friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

			it & operator++() { ++this->_p; return *this; }
			it operator++(value_type) { random_access_iterator tmp(*this); this->_p++; return tmp; }
			it & operator--() { --this->_p; return *this; }
			it operator--(value_type) { random_access_iterator tmp(*this); this->_p--; return tmp; }

			bool operator==(const it & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
			bool operator<(const it & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const it & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }

			it operator+(difference_type n)	const { pointer tmp(this->_p + n); return tmp; }					// a + n
			friend it operator+(difference_type n, const it & it) { pointer tmp(it._p + n); return tmp; }		// n + a
			it operator-(difference_type n)	const { pointer tmp(this->_p - n); return tmp; }					// a - n
			it & operator+=(difference_type n) { it tmp(this->_p + n); this->_p = tmp.getP(); return *this; }	// a += n 
			it & operator-=(difference_type n) { it tmp(this->_p - n); this->_p = tmp.getP(); return *this; }	// a-= n


		protected:
			pointer _p;

	}; // end of template ft:random_access_iterator<T>

} // end of namespace ft::

#endif
