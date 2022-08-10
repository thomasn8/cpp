#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iostream>
#include "random_access_iterator.hpp"

namespace ft
{

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

}

#endif

// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
// https://en.cppreference.com/w/cpp/iterator/iterator_traits
// https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait