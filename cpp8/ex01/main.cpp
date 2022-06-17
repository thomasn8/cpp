#include "Span.hpp"
#include <time.h>

void display(int i) 
{
	std::cout << i << " ";
}

int main()
{
	std::cout << std::endl << "PART 1: SPAN OBJECT INSTANCIATIONS WITH NUMBERS INSIDE" << std::endl;
	Span sp = Span(6);
	sp.addNumber(4);
	sp.addNumber(1);
	std::cout << sp << std::endl;

	sp.addNumber(9);
	sp.addNumber(13);
	sp.addNumber(6);
	sp.addNumber(21);							// 6e nombre ajouté au container = limite
	std::cout << sp << " contains: ";
	for_each(sp.begin(), sp.end(), display);
	std::cout << std::endl;
	sp.addNumber(2);
	sp.addNumber(3);

	Span sp1 = Span(3);
	sp1.addNumber(100);
	std::cout << sp1 << " contains: ";
	for_each(sp1.begin(), sp1.end(), display);
	std::cout << std::endl;
	
	Span sp2(sp1);
	std::cout << sp2 << " contains: ";
	for_each(sp2.begin(), sp2.end(), display);
	std::cout << std::endl;

	sp1.addNumber(10);							// ajout d'un nombre dans sp1, sans impacter la copy sp2
	std::cout << sp1 << " contains: ";
	for_each(sp1.begin(), sp1.end(), display);
	std::cout << std::endl;
	std::cout << sp2 << " contains: ";
	for_each(sp2.begin(), sp2.end(), display);
	std::cout << std::endl;

	Span sp3 = Span(10);
	sp3.addNumber(1);
	sp3.addNumber(2);
	sp3.addNumber(3);
	std::cout << sp3 << " contains: ";
	for_each(sp3.begin(), sp3.end(), display);
	std::cout << std::endl;

	Span sp4 = sp3;
	std::cout << sp4 << " contains: ";
	for_each(sp4.begin(), sp4.end(), display);
	std::cout << std::endl;


	std::cout << std::endl << "PART 2: DISTANCES IN SPAN" << std::endl;
	std::cout << sp << " contains: ";
	for_each(sp.begin(), sp.end(), display);
	std::cout << std::endl;
	std::cout << "Longest distance = " << sp.longestSpan();
	std::cout << std::endl;
	
	Span sp5 = Span(10000);
	std::cout << sp5 << " contains: ";
	for_each(sp5.begin(), sp5.end(), display);
	std::cout << std::endl;
	std::cout << "Longest distance = " << sp5.longestSpan();
	std::cout << std::endl;

	std::cout << sp << " contains: ";
	for_each(sp.begin(), sp.end(), display);
	std::cout << std::endl;
	std::cout << "Shortest distance = " << sp.shortestSpan();
	std::cout << std::endl;

	std::cout << std::endl << "PART 3: TESTS WITH A 10'000 NUMBERS IN SPAN" << std::endl;
	int rand_num;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		rand_num = rand() % 1000000 + 1;
		sp5.addNumber(rand_num);
	}
	std::cout << sp5 << std::endl;
	std::cout << "Longest distance = " << sp5.longestSpan();
	std::cout << std::endl;
	std::cout << "Shortest distance = " << sp5.shortestSpan();
	std::cout << std::endl;

	std::cout << std::endl << "PART 4: ADDING A RANGE OF NUMBERS TO CONTAINER" << std::endl;
	Span sp6 = Span(100);
	sp6.addNumber(99);
	sp6.addNumber(98);
	std::cout << sp6 << " contains: ";
	for_each(sp6.begin(), sp6.end(), display);
	std::cout << std::endl;
	std::cout << sp << " contains: ";
	for_each(sp.begin(), sp.end(), display);
	std::cout << std::endl;
	sp6.addRange(sp.begin(), sp.end());				// from std::list with iterators
	std::cout << sp6 << " contains: ";
	for_each(sp6.begin(), sp6.end(), display);
	std::cout << std::endl;
	int myints[] = {16,2,77,29};
	sp6.addRange(myints, 4);						// from int *, with N
	for_each(sp6.begin(), sp6.end(), display);
	std::cout << std::endl;

	std::cout << std::endl << "PART 5: DESTRUCTOR CALLED ON OBJECTS INSTANCIATED" << std::endl;

	return 0;
}