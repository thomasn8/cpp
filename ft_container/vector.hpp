#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>			// cout << 
#include <memory>			// allocator<T>
#include <stdexcept>		// exceptions
#include "iterators.hpp"
#include "utils.hpp"

using namespace std;

namespace ft
{
	template <typename T, typename Alloc = allocator<T> >
	class vector
	{
		public :
	// MEMBER TYPES
		typedef T 												value_type;
		typedef unsigned int 									size_type;
		typedef allocator<value_type> 							allocator_type;
		typedef typename allocator_type::reference 				reference;			// T &
		typedef typename allocator_type::const_reference 		const_reference;	// const T &
		typedef	typename allocator_type::pointer 				pointer;			// T *
		typedef	typename allocator_type::const_pointer 			const_pointer;		// const T *
		typedef int												difference_type;	// pour marquer les distances entre 2 ptr
		typedef	ft::random_access_iterator<value_type>			iterator;
		typedef	ft::random_access_iterator<const value_type>	const_iterator;
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
	// CONSTRUCTEURS/DESTRUCTEUR
		explicit vector(const allocator_type & alloc = allocator_type()) 						// CONSTR #1
		: _n(0), _c(0), _capacityFactor(2), _alloc(alloc)
		{
			this->_pointer = this->_alloc.allocate(1);
			this->_first = this->_pointer;
			this->_last = --this->_pointer;
			cout << endl << "(" << this << " - null) vector created" << endl;
		}

		explicit vector(size_type n, const value_type & val = value_type(), 					// CONSTR #2
			const allocator_type & alloc = allocator_type())
		: _n(n), _c(n), _capacityFactor(2), _alloc(alloc)
		{
			if (n > this->max_size())
			{
				this->capacity_error();
				return;
			}
			this->_pointer = this->_alloc.allocate(n + 1);
			this->_first = this->_pointer;
			for (size_type i = 0; i < n; i++)
			{
				// this->_alloc.construct(this->_pointer, val+i);
				this->_alloc.construct(this->_pointer, val);
				this->_pointer++;
			}
			this->_pointer--;
			this->_last = this->_pointer;
			cout << endl << "(" << this << " - fill) vector created" << endl;
		}
		
		// le typedef SFINAE dans random_access_iterator force le choix pour ce constructeur 
		// car constructeur à 2 args comme le #2
		template <typename InputIterator>														// CONSTR #3
		vector(InputIterator first, InputIterator last, 
			const allocator_type & alloc = allocator_type(), 
			typename InputIterator::SFINAE_condition = 0) : 
			_capacityFactor(2), _alloc(alloc)
		{
			this->_n = last - first;
			this->_c = this->_n;
			if (this->_c > this->max_size())
			{
				this->capacity_error();
				return;
			}
			if (this->_n)
			{
				this->_pointer = this->_alloc.allocate(this->_n + 1);
				this->_first = this->_pointer;
				while (first != last)
				{
					this->_alloc.construct(this->_pointer, *first);
					++first;
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
			}
			else
			{
				this->_pointer = this->_alloc.allocate(1);
				this->_first = this->_pointer;
				this->_last = --this->_pointer;
			}
			cout << endl << "(" << this << " - range) vector created" << endl;
		}

		vector(const vector & x) :															// CONSTR #4
			_capacityFactor(2), _alloc(x.get_allocator())
		{
			iterator first = x.begin();
			iterator last = x.end();
			this->_n = x.size();
			this->_c = this->_n;
			if (this->_c > this->max_size())
			{
				this->capacity_error();
				return;
			}
			this->_pointer = x.get_allocator().allocate(this->_n + 1);
			this->_first = this->_pointer;
			while (first != last)
			{
				x.get_allocator().construct(this->_pointer, *first);
				++first;
				this->_pointer++;
			}
			this->_pointer--;
			this->_last = this->_pointer;
			cout << endl << "(" << this << " - copy) vector created" << endl;
		}

		virtual ~vector() 																	// DESTR #1
		{
			this->get_allocator().deallocate(this->_first, this->size());
			cout << endl << "(" << this << " - default) vector destroyed" << endl;
		}

	// ITERATORS
		iterator begin() { return iterator(this->_first); };
		iterator end() { return iterator(this->_last + 1); };
		const_iterator begin() const { return const_iterator(this->_first); }
		const_iterator end() const { return const_iterator(this->_last + 1); }
		const_iterator cbegin() const { return const_iterator(this->_first); }
		const_iterator cend() const { return const_iterator(this->_last + 1); }			
		reverse_iterator rbegin() { reverse_iterator from(this->_last + 1); return from; }
		const_reverse_iterator rbegin() const { const_reverse_iterator from(this->_last + 1); return from; }
		reverse_iterator rend() { reverse_iterator until(this->_first); return until; }
		const_reverse_iterator rend() const { const_reverse_iterator until(this->_first); return until; }
		const_reverse_iterator crbegin() const { const_reverse_iterator from(this->_last + 1); return from; }
		const_reverse_iterator crend() const { const_reverse_iterator until(this->_first); return until; }
	
	// ERRORS
		class length_error : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("Allocation impossible: capacity exceeded"); }
		};
		class out_of_range_error : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("Error: out of range"); }
		};

	// ELEMENT ACCESS
		reference operator[](size_type index)				{ return this->_first[index]; }
		const_reference operator[](size_type index) const	{ return this->_first[index]; }
		reference front() 						{ return *this->_first; }
		const_reference front() const 			{ return *this->_first; }
		reference back() 						{ return *this->_last; }
		const_reference back() const 			{ return *this->_last; }
		value_type * data() 					{ return this->_first; }
		const value_type * data() const 		{ return this->_first; }
		reference at(size_type n)
		{
			if (n >= this->_n)
				this->range_error();
			return *(this->_first + n);
		}
		const_reference at(size_type n) const
		{
			if (n >= this->_n)
				this->range_error();
			return *(this->_first + n);
		}

	// CAPACITY
		size_type size() const 					{ return this->_n; }
		bool empty() const 						{ return bool(!this->_n); }
		size_type capacity() const				{ return this->_c; }
		size_type max_size() const				{ return this->_alloc.max_size(); }
		
		void shrink_to_fit()
		{
			size_type distance = this->_c - this->_n;
			if (distance > 0)
			{
				iterator old_first = this->begin();
				iterator old_last = this->end();
				this->_pointer = this->_alloc.allocate(this->_n + 1);
				pointer new_first = this->_pointer;
				while (old_first != old_last)
				{
					this->_alloc.construct(this->_pointer, *old_first);
					old_first++;
					this->_pointer++;
				}
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_first = new_first;
				this->_last = --this->_pointer;
				this->_c = this->_n;
			}
		}

		void reserve(size_type n)
		{
			if (n > this->max_size())
				return this->capacity_error();
			if (n > this->_c)
			{
				iterator old_first = this->begin();
				iterator old_last = this->end();
				this->_pointer = this->_alloc.allocate(n + 1);
				pointer new_first = this->_pointer;
				while (old_first != old_last)
				{
					this->_alloc.construct(this->_pointer, *old_first);
					old_first++;
					this->_pointer++;
				}
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_first = new_first;
				this->_last = --this->_pointer;
				this->_c = n;
			}
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->_n)
			{
				iterator first(this->_first + n);
				iterator last = this->end();
				erase(first, last);
			}
			else if (n > this->_n)
			{
				size_type diff = n - this->_n;
				for (size_type i = 0; i < diff; i++)
					this->push_back(val);
			}
		}

	// MODIFIERS
		void assign(size_type n, const value_type & val)
		{
			iterator old_first = this->begin();
			iterator old_last = this->end();
			this->_pointer = this->_alloc.allocate(n + 1);
			pointer new_first = this->_pointer;
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(this->_pointer++, val);
			this->_alloc.deallocate(this->_first, this->_c + 1);
			this->_first = new_first;
			this->_last = --this->_pointer;
			this->_n = n;
			this->_c = this->_n;
		}
		
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, 
			typename InputIterator::SFINAE_condition = 0)
		{
			iterator old_first = this->begin();
			iterator old_last = this->end();
			size_type n = last - first;
			this->_pointer = this->_alloc.allocate(n + 1);
			pointer new_first = this->_pointer;
			while (first != last)
				this->_alloc.construct(this->_pointer++, *first++);
			this->_alloc.deallocate(this->_first, this->_c + 1);
			this->_first = new_first;
			this->_last = --this->_pointer;
			this->_n = n;
			this->_c = this->_n;
		}

		void push_back(const value_type & val)
		{
			if (this->_n + 1 <= this->_c)
				this->_alloc.construct(this->_last++ + 1, val);
			else
			{
				size_type new_capacity = this->_c * this->_capacityFactor;
				if (new_capacity > this->max_size())
					return this->capacity_error();
				iterator old_first = this->begin();
				iterator old_last = this->end();
				this->_pointer = this->_alloc.allocate(new_capacity + 1);
				pointer new_first = this->_pointer;
				while (old_first != old_last)
					this->_alloc.construct(this->_pointer++, *old_first++);
				this->_alloc.construct(this->_pointer, val);
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_first = new_first;
				this->_last = this->_pointer;
				this->_c = new_capacity;
			}
			this->_n++;
		}

		void pop_back()
		{
			if (this->_n > 0)
			{
				this->_alloc.destroy(this->_last--);
				this->_n--;
			}
		}

		iterator insert(iterator position, const value_type & val)
		{
			iterator r_value;
			if (this->_n == this->_c)
			{
				iterator it = this->begin();
				this->_pointer = this->_alloc.allocate(this->_n + 2);
				pointer f = this->_pointer;
				cout << endl;
				while (it != position)
					this->_alloc.construct(this->_pointer++, *it++);
				r_value = this->_pointer;
				this->_alloc.construct(this->_pointer, val);
				this->_pointer++;
				while (it != this->_last + 1)
					this->_alloc.construct(this->_pointer++, *it++);
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_c++;
				this->_last = this->_pointer - 1;
				this->_first = f;
			}
			else
			{
				r_value = position;
				value_type tmp = *position;
				value_type tmp2;
				this->_alloc.construct(position.getP(), val);
				while (position != this->_last + 1)
				{
					tmp2 = *(++position);
					this->_alloc.construct(position.getP(), tmp);
					tmp = tmp2;
				}
				this->_last++;
			}
			this->_n++;
			return r_value;
		}

		void insert(iterator position, size_type n, const value_type & val)
		{
			iterator it = this->begin();
			if (this->_n + n > this->_c)
			{
				this->_pointer = this->_alloc.allocate(this->_n + n + 1);
				pointer f = this->_pointer;
				while (it != position)
					this->_alloc.construct(this->_pointer++, *it++);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(this->_pointer++, val);
				while (it != this->_last + 1)
					this->_alloc.construct(this->_pointer++, *it++);
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_c += n;
				this->_last = this->_pointer - 1;
				this->_first = f;
			}
			else
			{
				vector<T> cpy(it, this->end());
				iterator it_cpy = cpy.begin();
				size_type index = this->get_index(position);
				size_type new_index;
				size_type dist = this->_last - position + 1;
				for (size_type i = 0; i < dist; i++)
				{
					new_index = index + n + i;
					this->_alloc.construct(this->_first + new_index, *(it_cpy + new_index - n));
				}
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_first[this->get_index(position++)], val);
				this->_last = this->_first + new_index;
			}
			this->_n += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			size_type n = last - first;
			iterator it = this->begin();
			if (this->_n + n > this->_c)
			{
				this->_pointer = this->_alloc.allocate(this->_n + n + 1);
				pointer f = this->_pointer;
				while (it != position)
					this->_alloc.construct(this->_pointer++, *it++);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(this->_pointer++, *first++);
				while (it != this->_last + 1)
					this->_alloc.construct(this->_pointer++, *it++);
				this->_alloc.deallocate(this->_first, this->_c + 1);
				this->_c += n;
				this->_last = this->_pointer - 1;
				this->_first = f;
			}
			else
			{
				vector<T> cpy(it, this->end());
				iterator it_cpy = cpy.begin();
				size_type index = this->get_index(position);
				size_type dist = this->_last - position + 1;
				size_type new_index;
				for (size_type i = 0; i < dist; i++)
				{
					new_index = index + n + i;
					this->_alloc.construct(this->_first + new_index, *(it_cpy + new_index - n));
				}
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_first[this->get_index(position++)], *first++);
				this->_last = this->_first + new_index;
			}
			this->_n += n;
		}

		iterator erase(iterator position)
		{
			iterator r_value = position;
			size_type dist = this->_last - position + 1;
			while (--dist)
				this->_alloc.construct(position.getP(), *(position++ + 1));
			this->get_allocator().destroy(this->_last);
			this->_last--;
			this->_n--;
			return r_value;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator r_value = first;						
			size_type dist = this->_last - last + 2;
			while (--dist)
				this->_alloc.construct((first++).getP(), *last++);
			size_type erased = last - first;
			this->_last -= erased;
			this->_n -= erased;
			while (erased)
				this->get_allocator().destroy(this->_last - erased-- + 1);
			return r_value;
		}

		void swap(vector & x)
		{
			size_type n_this = this->_n;
			size_type c_this = this->_c;
			pointer f_this = this->_first;
			pointer l_this = this->_last;
			this->_n = x.size();
			this->_c = x.capacity();
			this->_first = x.data();
			this->_last = x.data() + x.size() - 1;
			x._n = n_this;
			x._c = c_this;
			x._first = f_this;
			x._last = l_this;
		}

		void clear()
		{
			for (size_type i = 0; i < this->_n; i++)
				this->_alloc.destroy(this->_first + i);
			this->_alloc.deallocate(this->_first, this->_c + 1);
			this->_pointer = this->_alloc.allocate(1);
			this->_first = this->_pointer;
			this->_last = --this->_pointer;
			this->_n = 0;
			this->_c = 0;
		}

	// ALLOCATOR
		allocator_type get_allocator() const 				{ return this->_alloc; }

		private :
		Alloc			_alloc;				// the default allocator
		size_type		_n;					// size: number of elements in container
		size_type		_c;					// capacity: storage space expressed in terms of elements
		size_type		_capacityFactor;	// incremental factor for capacity reallocation
		pointer			_first;				// first element
		pointer			_last;				// last element
		pointer			_pointer;			// random pointer for multi-usage

		size_type get_index(pointer p) const { return p - this->_first; }
		size_type get_index(iterator it) { return it - this->begin(); }
		
		void	capacity_error()
		{
			try { throw vector::length_error(); }
			catch (const vector::length_error & e) { cerr << e.what() << endl; }
		}
		void	range_error()
		{
			try { throw vector::out_of_range_error(); }
			catch (const vector::out_of_range_error & e) { cerr << e.what() << endl; }
		}
	};

	template <class T, class Alloc>
	void swap(vector<T,Alloc> & x, vector<T,Alloc> & y) { x.swap(y); }

// RELATIONAL OPERATORS
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::less_equal<T>());
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::greater<T>());
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::greater_equal<T>());
	}

}

#endif
