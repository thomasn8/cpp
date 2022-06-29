#ifndef RANDOM_ACCESS_ITERATOR_TAG_HPP
# define RANDOM_ACCESS_ITERATOR_TAG_HPP

namespace ft
{

	template <typename T>
	class random_access_iterator_tag
	{
		public:

		// MEMBER TYPES
		    typedef T							value_type;
			typedef int							difference_type;
			typedef T *							pointer;
			typedef T &							reference;
			typedef random_access_iterator_tag  iterator_category;
			typedef	iterator_category			it;
			typedef int 						SFINAE;	// pour forcer le choix de l'overload entre les constructeurs

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator_tag() : _p(0) {}										// default
			random_access_iterator_tag(T * p) : _p(p) {}								// special
			random_access_iterator_tag(const it & src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator_tag() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }

		// SURCHARGES
			it & operator=(it const & src) { this->_p = src.getP(); return *this; }		// assign 
			value_type & operator*() { return *_p; }
			reference operator[](unsigned int index) { return this->_p[index]; }	
			pointer operator->() { return _p;  }
			friend difference_type operator-(const it & a, const it & b) { return static_cast<int>(a._p - b._p); }

			it & operator++() { ++this->_p; return *this; }
			it operator++(T) { random_access_iterator_tag tmp(*this); this->_p++; return tmp; }
			it & operator--() { --this->_p; return *this; }
			it operator--(T) { random_access_iterator_tag tmp(*this); this->_p--; return tmp; }

			bool operator==(const it & rhs) const { return this->_p == rhs._p; }
			bool operator!=(const it & rhs) const { return this->_p != rhs._p; }
			bool operator<(const it & rhs) const { return this->_p < rhs._p; }
			bool operator<=(const it & rhs) const { return this->_p <= rhs._p; }
			bool operator>(const it & rhs) const { return this->_p > rhs._p; }
			bool operator>=(const it & rhs) const { return this->_p >= rhs._p; }

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

	}; // end of template ft:random_access_iterator_tag<T>

} // end of namespace ft::

#endif
