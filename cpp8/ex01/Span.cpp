#include "Span.hpp"

/* *****************
	...
***************** */

// 4	1	9	13	6	21
int Span::shortestSpan() const
{
	int shortest = -1;
	std::list<int>::const_iterator last = this->end();
	std::list<int>::const_iterator it = this->begin();
	std::list<int>::const_iterator it2 = it;

	try
	{
		if (this->size() <= 1)
			throw Span::SmallException();
	}
	catch (Span::SmallException & e)
	{
		std::cerr << RED;
		std::cerr << e.what();
		std::cerr << std::endl;
		std::cerr << WHI;
		return shortest;
	}
	it2++;
	int distance = abs(*it - *it2);
	shortest = distance;
	while (it != last)
	{
		while (it2 != last)
		{
			distance = abs(*it - *it2);
			if (distance < shortest)
				shortest = distance;
			it2++;
		}
		it2 = ++it;
		it2++;
	}
	return shortest;
}

int Span::longestSpan() const
{
	int distance = -1;

	try
	{
		if (this->size() <= 1)
			throw Span::SmallException();
	}
	catch (Span::SmallException & e)
	{
		std::cerr << RED;
		std::cerr << e.what();
		std::cerr << std::endl;
		std::cerr << WHI;
		return distance;
	}
	int min = *min_element(this->begin(), this->end());
	int max = *max_element(this->begin(), this->end());
	distance = max - min;
	return distance;
}

bool Span::addNumber(int number)
{
	try
	{
		if (this->size() >= this->getLimit())
			throw Span::FullException();
		// TESTER AUSSI LA LIMITE VS LE SYSTEM
	}
	catch (Span::FullException & e)
	{
		std::cerr << RED;
		std::cerr << e.what();
		std::cerr << this->_limit;
		std::cerr << std::endl;
		std::cerr << WHI;
		return false;
	}
	this->push_back(number);
	return true;
}

const char *Span::FullException::what() const throw()
{
	return ("Container is full: maximum numbers inside is ");
}

const char *Span::SmallException::what() const throw()
{
	return ("Impossible to calculate distance: less than 2 numbers inside container ");
}

/* *****************
	Getters/Setters
***************** */

unsigned int Span::getLimit() const
{
	return this->_limit;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Span const & instance)
{
	unsigned int s = instance.size();
	if (s > 1)
		o << "Span with " << s << "/" << instance.getLimit() << " numbers inside";
	else
		o << "Span with " << s << "/" << instance.getLimit() << " number inside";
	return o;
}

Span	& Span::operator=(Span const & src)
{
	this->resize(src.size());
	std::copy(src.begin(), src.end(), this->begin());
	this->_limit = src.getLimit();
	std::cout << "(" << this << " - assign.) Span (" << &src << ") copied" << std::endl;
	return *this;
}

Span::Span(Span const & src) :
std::list<int>(src),
_limit(src.getLimit())
{
	std::cout << "(" << this << " - copy) Span created" << std::endl;
}

Span::Span(unsigned int N) :
_limit(N)
{
	std::cout << "(" << this << " - u_int) Span created" << std::endl;
}

Span::Span()
{
	std::cout << "(" << this << " - default) Span created" << std::endl;
}

Span::~Span()
{
	std::cout << "(" << this << " - default) Span destroyed" << std::endl;
}
