#include <iostream>

namespace ft
{
	template <typename T>
	class map
	{
		public :

			map()
			{
				std::cout << "(" << this << " - default) map created" << std::endl;
			}

			virtual ~map()
			{
				std::cout << "(" << this << " - default) map destroyed" << std::endl;
			}

		private :

	};
}