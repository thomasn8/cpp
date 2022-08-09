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
			typedef int 						SFINAE_condition;	// force le choix de l'overload entre les constructeurs d'une outer-class

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) {}										// default
			random_access_iterator(pointer p) : _p(p) {}							// special
			random_access_iterator(reference src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			difference_type getDiff() const { return sizeof(T); }

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
			typedef int 						SFINAE_condition;	// force le choix de l'overload entre les constructeurs d'une outer-class

		// CONSTRUCTEURS/DESTRUCTEUR
			random_access_iterator() : _p(0) {}										// default
			random_access_iterator(pointer p) : _p(p) {}							// special
			random_access_iterator(reference src) : _p(src.getP()) {}				// copy
			virtual ~random_access_iterator() {}
		
		// ACCESSEURS
			pointer getP() const { return this->_p; }
			difference_type getDiff() const { return sizeof(this->_p); }

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
