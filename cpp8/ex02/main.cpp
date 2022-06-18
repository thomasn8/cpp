#include "MutantStack.hpp"

/* 
	Si vous l’exécutez une première fois avec votre MutantStack, puis une seconde fois en
	remplaçant la MutantStack, par exemple par std::list, les deux résultats devront être
	identiques. Bien sûr, lorsque vous testez cet exemple avec un autre container, modifiez le
	code avec les fonctions membres correspondantes (push() peut devenir push_back()).
*/

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
	(void) it;
	(void) ite;
	std::cout << "At the begining of the stack: " << *it << std::endl;
	std::for_each(mstack.begin(), mstack.end(), display);
	std::cout << std::endl;

	++it;
	std::cout << "At the begining of the stack: " << *it << std::endl;

	// --it;

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }

	// std::stack<int> s(mstack);
	return 0;
}