#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <list>

# define RED "\033[0;31m"
# define WHI "\033[0m"

class Span : public std::list<int>
{
	public:
	
		Span & operator=(Span const & src);
		Span(Span const & src);
		Span(unsigned int N);
		~Span();

		unsigned int getLimit() const;
		bool addNumber(int number);
		bool addRange(std::list<int>::const_iterator first, std::list<int>::const_iterator last);
		int shortestSpan() const;
		int longestSpan() const;

		class FullException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class MaxSizeException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class SmallException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

	private:

		Span();
		unsigned int _limit;
};

std::ostream	& operator<<(std::ostream & o, Span const & inst);

#endif
