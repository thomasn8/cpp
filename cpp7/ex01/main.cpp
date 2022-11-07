#include "iter.hpp"
#include "Num.hpp"

int main(void)
{
	char		tab1[] = "ABCD";
	int			tab2[6] = {1, 2, 3, 4, 5, 6};
	int			*tab3[6] = {&tab2[0], &tab2[1], &tab2[2], &tab2[3], &tab2[4], &tab2[5]};
	Num 		tab4[3];
	const int 	tab5[3] = {1, 2, 3};
	const Num 	tab6[3];

	std::cout << "BEFORE ITER:" << std::endl;
	for (int i = 0; tab1[i]; i++)
		std::cout << tab1[i] << " ";
	for (int i = 0; i < 6; i++)
		std::cout << tab2[i] << " ";
	for (int i = 0; i < 6; i++)
		std::cout << tab3[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl << "AFTER ITER:" << std::endl;
	iter<char *>(tab1, 4, add_one);
	iter<int *>(tab2, 6, add_one);
	iter<int **>(tab3, 6, add_one);
	std::cout << std::endl;

	std::cout << std::endl << "CLASS:" << std::endl;
	iter<Num *>(tab4, 3, add_one);
	std::cout << std::endl;

	std::cout << std::endl << "CONST TYPE:" << std::endl;
	// iter<const int *>(tab5, 6, add_one);			// impossible car const
	iter<const int *>(tab5, 3, display_value);
	std::cout << std::endl;
	// iter<const Num *>(tab6, 3, add_one);			// impossible car const
	iter<const Num *>(tab6, 3, display_value);
	std::cout << std::endl;

	return 0;
}
