#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
using namespace std;
#include <memory>
#include <stdexcept>
#include "iterators.hpp"
#include "utils.hpp"

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
			_ptr = _alloc.allocate(1);
			_first = _ptr;
			_last = --_ptr;
		}

		explicit vector(size_type n, const value_type & val = value_type(), 					// CONSTR #2
			const allocator_type & alloc = allocator_type())
		: _n(n), _c(n), _capacityFactor(2), _alloc(alloc)
		{
			if (n > max_size())
			{
				capacity_error();
				return;
			}
			_ptr = _alloc.allocate(n + 1);
			_first = _ptr;
			for (size_type i = 0; i < n; i++)
			{
				// _alloc.construct(_ptr, val+i);
				_alloc.construct(_ptr, val);
				_ptr++;
			}
			_ptr--;
			_last = _ptr;
		}
		
		// le typedef SFINAE dans random_access_iterator force le choix pour ce constructeur 
		// car constructeur à 2 args comme le #2
		template <typename InputIterator>														// CONSTR #3
		vector(InputIterator first, InputIterator last, 
			const allocator_type & alloc = allocator_type(), 
			typename InputIterator::SFINAE_condition = 0) : 
			_capacityFactor(2), _alloc(alloc)
		{
			_n = last - first;
			_c = _n;
			if (_c > max_size())
			{
				capacity_error();
				return;
			}
			if (_n)
			{
				_ptr = _alloc.allocate(_n + 1);
				_first = _ptr;
				while (first != last)
				{
					_alloc.construct(_ptr, *first);
					++first;
					_ptr++;
				}
				_ptr--;
				_last = _ptr;
			}
			else
			{
				_ptr = _alloc.allocate(1);
				_first = _ptr;
				_last = --_ptr;
			}
		}

		vector(const vector & x) :															// CONSTR #4
			_capacityFactor(2), _alloc(x.get_allocator())
		{
			iterator first = x.begin();
			iterator last = x.end();
			_n = x.size();
			_c = _n;
			if (_c > max_size())
			{
				capacity_error();
				return;
			}
			_ptr = x.get_allocator().allocate(_n + 1);
			_first = _ptr;
			while (first != last)
			{
				x.get_allocator().construct(_ptr, *first);
				++first;
				_ptr++;
			}
			_ptr--;
			_last = _ptr;
		}

		virtual ~vector() 																	// DESTR #1
		{
			if (_last >= _first)
			{
				_ptr = _first;
				while (_ptr != _last)
					_alloc.destroy(_ptr++);
			}
			_alloc.deallocate(_first, size()+1);
		}

	// ITERATORS
		iterator begin() { return iterator(_first); };
		iterator end() { return iterator(_last + 1); };
		const_iterator begin() const { return const_iterator(_first); }
		const_iterator end() const { return const_iterator(_last + 1); }
		const_iterator cbegin() const { return const_iterator(_first); }
		const_iterator cend() const { return const_iterator(_last + 1); }			
		reverse_iterator rbegin() { reverse_iterator from(_last + 1); return from; }
		const_reverse_iterator rbegin() const { const_reverse_iterator from(_last + 1); return from; }
		reverse_iterator rend() { reverse_iterator until(_first); return until; }
		const_reverse_iterator rend() const { const_reverse_iterator until(_first); return until; }
		const_reverse_iterator crbegin() const { const_reverse_iterator from(_last + 1); return from; }
		const_reverse_iterator crend() const { const_reverse_iterator until(_first); return until; }
	
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
		reference operator[](size_type index)				{ return _first[index]; }
		const_reference operator[](size_type index) const	{ return _first[index]; }
		reference front() 						{ return *_first; }
		const_reference front() const 			{ return *_first; }
		reference back() 						{ return *_last; }
		const_reference back() const 			{ return *_last; }
		value_type * data() 					{ return _first; }
		const value_type * data() const 		{ return _first; }
		reference at(size_type n)
		{
			if (n >= _n)
				range_error();
			return *(_first + n);
		}
		const_reference at(size_type n) const
		{
			if (n >= _n)
				range_error();
			return *(_first + n);
		}

	// CAPACITY
		size_type size() const 					{ return _n; }
		bool empty() const 						{ return bool(!_n); }
		size_type capacity() const				{ return _c; }
		size_type max_size() const				{ return _alloc.max_size(); }
		
		void shrink_to_fit()
		{
			size_type distance = _c - _n;
			if (distance > 0)
			{
				iterator old_first = begin();
				iterator old_last = end();
				_ptr = _alloc.allocate(_n + 1);
				pointer new_first = _ptr;
				while (old_first != old_last)
				{
					_alloc.construct(_ptr, *old_first);
					old_first++;
					_ptr++;
				}
				_alloc.deallocate(_first, _c + 1);
				_first = new_first;
				_last = --_ptr;
				_c = _n;
			}
		}

		void reserve(size_type n)
		{
			if (n > max_size())
				return capacity_error();
			if (n > _c)
			{
				iterator old_first = begin();
				iterator old_last = end();
				_ptr = _alloc.allocate(n + 1);
				pointer new_first = _ptr;
				while (old_first != old_last)
				{
					_alloc.construct(_ptr, *old_first);
					old_first++;
					_ptr++;
				}
				_alloc.deallocate(_first, _c + 1);
				_first = new_first;
				_last = --_ptr;
				_c = n;
			}
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < _n)
			{
				iterator first(_first + n);
				iterator last = end();
				erase(first, last);
			}
			else if (n > _n)
			{
				size_type diff = n - _n;
				for (size_type i = 0; i < diff; i++)
					push_back(val);
			}
		}

	// MODIFIERS
		void assign(size_type n, const value_type & val)
		{
			iterator old_first = begin();
			iterator old_last = end();
			_ptr = _alloc.allocate(n + 1);
			pointer new_first = _ptr;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr++, val);
			_alloc.deallocate(_first, _c + 1);
			_first = new_first;
			_last = --_ptr;
			_n = n;
			_c = _n;
		}
		
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, 
			typename InputIterator::SFINAE_condition = 0)
		{
			iterator old_first = begin();
			iterator old_last = end();
			size_type n = last - first;
			_ptr = _alloc.allocate(n + 1);
			pointer new_first = _ptr;
			while (first != last)
				_alloc.construct(_ptr++, *first++);
			_alloc.deallocate(_first, _c + 1);
			_first = new_first;
			_last = --_ptr;
			_n = n;
			_c = _n;
		}

		void push_back(const value_type & val)
		{
			if (_n + 1 <= _c)
				_alloc.construct(_last++ + 1, val);
			else
			{
				size_type new_capacity = _c * _capacityFactor;
				if (new_capacity > max_size())
					return capacity_error();
				iterator old_first = begin();
				iterator old_last = end();
				_ptr = _alloc.allocate(new_capacity + 1);
				pointer new_first = _ptr;
				while (old_first != old_last)
					_alloc.construct(_ptr++, *old_first++);
				_alloc.construct(_ptr, val);
				_alloc.deallocate(_first, _c + 1);
				_first = new_first;
				_last = _ptr;
				_c = new_capacity;
			}
			_n++;
		}

		void pop_back()
		{
			if (_n > 0)
			{
				_alloc.destroy(_last--);
				_n--;
			}
		}

		iterator insert(iterator position, const value_type & val)
		{
			iterator r_value;
			if (_n == _c)
			{
				iterator it = begin();
				_ptr = _alloc.allocate(_n + 2);
				pointer f = _ptr;
				while (it != position)
					_alloc.construct(_ptr++, *it++);
				r_value = _ptr;
				_alloc.construct(_ptr, val);
				_ptr++;
				while (it != _last + 1)
					_alloc.construct(_ptr++, *it++);
				_alloc.deallocate(_first, _c + 1);
				_c++;
				_last = _ptr - 1;
				_first = f;
			}
			else
			{
				r_value = position;
				value_type tmp = *position;
				value_type tmp2;
				_alloc.construct(position.getP(), val);
				while (position != _last + 1)
				{
					tmp2 = *(++position);
					_alloc.construct(position.getP(), tmp);
					tmp = tmp2;
				}
				_last++;
			}
			_n++;
			return r_value;
		}

		void insert(iterator position, size_type n, const value_type & val)
		{
			iterator it = begin();
			if (_n + n > _c)
			{
				_ptr = _alloc.allocate(_n + n + 1);
				pointer f = _ptr;
				while (it != position)
					_alloc.construct(_ptr++, *it++);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_ptr++, val);
				while (it != _last + 1)
					_alloc.construct(_ptr++, *it++);
				_alloc.deallocate(_first, _c + 1);
				_c += n;
				_last = _ptr - 1;
				_first = f;
			}
			else
			{
				vector<T> cpy(it, end());
				iterator it_cpy = cpy.begin();
				size_type index = get_index(position);
				size_type new_index;
				size_type dist = _last - position + 1;
				for (size_type i = 0; i < dist; i++)
				{
					new_index = index + n + i;
					_alloc.construct(_first + new_index, *(it_cpy + new_index - n));
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_first[get_index(position++)], val);
				_last = _first + new_index;
			}
			_n += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			size_type n = last - first;
			iterator it = begin();
			if (_n + n > _c)
			{
				_ptr = _alloc.allocate(_n + n + 1);
				pointer f = _ptr;
				while (it != position)
					_alloc.construct(_ptr++, *it++);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_ptr++, *first++);
				while (it != _last + 1)
					_alloc.construct(_ptr++, *it++);
				_alloc.deallocate(_first, _c + 1);
				_c += n;
				_last = _ptr - 1;
				_first = f;
			}
			else
			{
				vector<T> cpy(it, end());
				iterator it_cpy = cpy.begin();
				size_type index = get_index(position);
				size_type dist = _last - position + 1;
				size_type new_index;
				for (size_type i = 0; i < dist; i++)
				{
					new_index = index + n + i;
					_alloc.construct(_first + new_index, *(it_cpy + new_index - n));
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_first[get_index(position++)], *first++);
				_last = _first + new_index;
			}
			_n += n;
		}

		iterator erase(iterator position)
		{
			iterator r_value = position;
			size_type dist = _last - position + 1;
			while (--dist)
				_alloc.construct(&*position, *(position++ + 1));
			get_allocator().destroy(_last);
			_last--;
			_n--;
			return r_value;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator r_value = first;						
			size_type dist = _last - last + 2;
			while (--dist)
				_alloc.construct(&*first++, *last++);
			size_type erased = last - first;
			_last -= erased;
			_n -= erased;
			while (erased)
				get_allocator().destroy(_last - erased-- + 1);
			return r_value;
		}

		void swap(vector & x)
		{
			size_type n_this = _n;
			size_type c_this = _c;
			pointer f_this = _first;
			pointer l_this = _last;
			_n = x.size();
			_c = x.capacity();
			_first = x.data();
			_last = x.data() + x.size() - 1;
			x._n = n_this;
			x._c = c_this;
			x._first = f_this;
			x._last = l_this;
		}

		void clear()
		{
			for (size_type i = 0; i < _n; i++)
				_alloc.destroy(_first + i);
			_alloc.deallocate(_first, _c + 1);
			_ptr = _alloc.allocate(1);
			_first = _ptr;
			_last = --_ptr;
			_n = 0;
			_c = 0;
		}

	// ALLOCATOR
		allocator_type get_allocator() const 				{ return _alloc; }

		private :
		Alloc			_alloc;				// the default allocator
		size_type		_n;					// size: number of elements in container
		size_type		_c;					// capacity: storage space expressed in terms of elements
		size_type		_capacityFactor;	// incremental factor for capacity reallocation
		pointer			_first;				// first element
		pointer			_last;				// last element
		pointer			_ptr;			// random pointer for multi-usage

		size_type get_index(pointer p) const { return p - _first; }
		size_type get_index(iterator it) { return it - begin(); }
		
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
