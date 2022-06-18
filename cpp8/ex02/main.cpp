#include "MutantStack.hpp"
#include <list>

void display(int i)
{
	std::cout << i << " ";
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(1);
	// std::cout << "SIZE = "<< mstack.size() << std::endl;
	// std::cout << "TOP = "<< mstack.top() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "*it = " << *it << std::endl;
	std::cout << "iter++" << std::endl;
	++it;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "iter--" << std::endl;
	--it;
	std::cout << "*it = " << *it << std::endl;
	std::cout << std::endl;

	it = mstack.begin();
	std::cout << "All the stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	mstack.pop();
	std::cout << "pop the stack" << std::endl;
	std::cout << std::endl;

	it = mstack.begin();
	ite = mstack.end();
	std::cout << "All the stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	
	std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(1);
// 	// std::cout << "SIZE = "<< mstack.size() << std::endl;
// 	// std::cout << "TOP = "<< mstack.top() << std::endl;
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
	
// 	std::cout << "*it = " << *it << std::endl;
// 	std::cout << "iter++" << std::endl;
// 	++it;
// 	std::cout << "*it = " << *it << std::endl;
// 	std::cout << "iter--" << std::endl;
// 	--it;
// 	std::cout << "*it = " << *it << std::endl;
// 	std::cout << std::endl;

// 	it = mstack.begin();
// 	std::cout << "All the stack: " << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::cout << std::endl;

// 	mstack.pop_back();
// 	std::cout << "pop the stack" << std::endl;
// 	std::cout << std::endl;

// 	it = mstack.begin();
// 	ite = mstack.end();
// 	std::cout << "All the stack: " << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::cout << std::endl;
	
// 	std::list<int> s(mstack);
// 	return 0;
// }