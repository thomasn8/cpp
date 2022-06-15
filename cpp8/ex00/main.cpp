#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void display(int i) 
{
	std::cout << " " << i;
}

int main()
{
	// VECTOR CONTAINER with MATCH
	int even[] = {2,4,6,8};
  	std::vector<int> myvector(even, even + sizeof(even)/sizeof(int));
	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), display);
	std::cout << std::endl;
	::easyfind< std::vector<int> >(myvector, 8);

	// LIST CONTAINER with MATCH
	int odd[] = {1,3,5,7};
  	std::list<int> mylist(odd, odd + sizeof(odd)/sizeof(int));
	std::cout << "mylist contains:";
	for_each(mylist.begin(), mylist.end(), display);
	std::cout << std::endl;
	::easyfind< std::list<int> >(mylist, 3);

	// DEQUE CONTAINER with NO MATCH
	int others[] = {11, 21, 31, 41, 51, 61};
  	std::deque<int> mydeque(others, others + sizeof(others)/sizeof(int));
	std::cout << "mydeque contains:";
	for_each(mydeque.begin(), mydeque.end(), display);
	std::cout << std::endl;
	::easyfind< std::deque<int> >(mydeque, 22);

	return 0;
}
