#include "vector.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "class_test/Test.hpp"
#include <vector>
#include <map>

using namespace std;

int main()
{
	ft::map<char,int> ft1;
	
	std::map<char,int> std1;
	std1['a']=10;
	std1['b']=30;
	std1['c']=50;
	std1['d']=70;
	std::map<char,int>::iterator it = std1.begin();
	std::map<char,int>::iterator ite = std1.end();
	unsigned n = ite - it;
	// ft::map<char,int> ft2(it, ite);



	// std::vector<int> vec1(10, 3);
	// std::vector<int>::iterator it = vec1.begin();
	// std::vector<int>::iterator ite = vec1.end();
	// std::map<int, char> map2(it, ite);


	return 0;
}