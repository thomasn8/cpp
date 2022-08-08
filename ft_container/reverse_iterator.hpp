#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename T, typename U>
	class reverse_iterator : public ft::iterator_traits<T>
	{
		public:

/* 	
		iterator_type		Iterator										Iterator's type
		iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
		reference			iterator_traits<Iterator>::reference			Preserves Iterator's reference type 
*/

		// MEMBER TYPES
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef	typename iterator_traits<T>::difference_type 	difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef	typename iterator_traits<T>::reference			reference;
			typedef	T										iterator_type;
			typedef	typename iterator_traits<T>::iterator_category	iterator_category;

		    // typedef T							value_type;
			// typedef int							difference_type;
			// typedef T *							pointer;
			// typedef T &							reference;
			// typedef random_access_iterator_tag  iterator_category;
			// typedef	iterator_category			it;
			// typedef int 						SFINAE_condition;	// force le choix de l'overload entre les constructeurs d'une outer-class

		// // CONSTRUCTEURS/DESTRUCTEUR
		// 	random_access_iterator_tag() : _p(0) {}										// default
		// 	random_access_iterator_tag(pointer p) : _p(p) {}						// special
		// 	random_access_iterator_tag(reference src) : _p(src.getP()) {}				// copy
		// 	virtual ~random_access_iterator_tag() {}
		
		// // ACCESSEURS
		// 	pointer getP() const { return this->_p; }

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

		protected:
			pointer _p;

	}; // end of template ft:reverse_iterator<T>


// 	// CONST SPECIALIZED
// 	template <typename T>
// 	class reverse_iterator<T, int>
// 	{
// 		public:

// 		// // MEMBER TYPES
// 			typedef	iterator_traits<T>::value_type			value_type
// 			typedef	iterator_traits<T>::difference_type 	difference_type
// 			typedef iterator_traits<T>::pointer				pointer
// 			typedef	iterator_traits<T>::reference			reference
// 			typedef	T										iterator_type
// 			typedef	iterator_traits<T>::iterator_category	iterator_category
// 		//     typedef T							value_type;
// 		// 	typedef int							difference_type;
// 		// 	typedef const T *					pointer;
// 		// 	typedef const T &					reference;
// 		// 	typedef random_access_iterator_tag  iterator_category;
// 		// 	typedef	iterator_category			it;
// 		// 	typedef int 						SFINAE_condition;	// force le choix de l'overload entre les constructeurs d'une outer-class

// 		// // CONSTRUCTEURS/DESTRUCTEUR
// 		// 	random_access_iterator_tag() : _p(0) {}										// default
// 		// 	random_access_iterator_tag(pointer p) : _p(p) {}						// special
// 		// 	random_access_iterator_tag(reference src) : _p(src.getP()) {}				// copy
// 		// 	virtual ~random_access_iterator_tag() {}
		
// 		// // ACCESSEURS
// 		// 	pointer getP() const { return this->_p; }

// 		// // SURCHARGES
// 		// 	it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
// 		// 	const value_type & operator*() { return *_p; }
// 		// 	reference operator[](unsigned int index) { return this->_p[index]; }	
// 		// 	pointer operator->() { return _p;  }
// 		// 	friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

// 		// 	it & operator++() { ++this->_p; return *this; }
// 		// 	it operator++(value_type) { random_access_iterator_tag tmp(*this); this->_p++; return tmp; }
// 		// 	it & operator--() { --this->_p; return *this; }
// 		// 	it operator--(value_type) { random_access_iterator_tag tmp(*this); this->_p--; return tmp; }

// 		// 	bool operator==(const it & rhs) const { return this->_p == rhs._p; }
// 		// 	bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
// 		// 	bool operator<(const it & rhs) const { return this->_p < rhs._p; }
// 		// 	bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
// 		// 	bool operator>(const it & rhs) const { return this->_p > rhs._p; }
// 		// 	bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }

// 		// 	it operator+(int n)	const							// a + n
// 		// 	{
// 		// 		pointer tmp = this->_p;
// 		// 		if (n >= 0)
// 		// 		{
// 		// 			while (n--)
// 		// 				tmp++;
// 		// 		} 
// 		// 		else 
// 		// 		{
// 		// 			while (n++) 
// 		// 				tmp--;
// 		// 		}
// 		// 		return tmp;
// 		// 	}
// 		// 	friend it operator+(int n, const it & it)			// n + a
// 		// 	{
// 		// 		pointer tmp = it._p;
// 		// 		if (n >= 0)
// 		// 		{
// 		// 			while (n--)
// 		// 				tmp++;
// 		// 		} 
// 		// 		else 
// 		// 		{
// 		// 			while (n++) 
// 		// 				tmp--;
// 		// 		} 
// 		// 		return tmp; 
// 		// 	}
// 		// 	it & operator+=(int n)								// a += n 
// 		// 	{
// 		// 		if (n >= 0)
// 		// 		{
// 		// 			while (n--)
// 		// 				this->_p++;
// 		// 		} 
// 		// 		else 
// 		// 		{
// 		// 			while (n++) 
// 		// 				this->_p--;
// 		// 		} 
// 		// 		return *this; 
// 		// 	}
// 		// 	it operator-(int n)	const							// a - n
// 		// 	{
// 		// 		pointer tmp = this->_p;
// 		// 		if (n >= 0)
// 		// 		{
// 		// 			while (n--)
// 		// 				tmp--;
// 		// 		} 
// 		// 		else 
// 		// 		{
// 		// 			while (n++) 
// 		// 				tmp++;
// 		// 		} 
// 		// 		return tmp; 
// 		// 	}
// 		// 	it & operator-=(int n)								// a-= n
// 		// 	{
// 		// 		if (n >= 0)
// 		// 		{
// 		// 			while (n--)
// 		// 				this->_p--;
// 		// 		} 
// 		// 		else 
// 		// 		{
// 		// 			while (n++) 
// 		// 				this->_p++;
// 		// 		} 
// 		// 		return *this; 
// 		// 	}

// 		protected:
// 			pointer _p;

// 	}; // end of template ft:reverse_iterator<T>

} // end of namespace ft::

#endif
