#include <iostream>

std::string	string_to_upper(std::string s);

class Harl
{
	public:
		Harl(void);
		~Harl();
		void		complain(std::string level);

	private:
		void 		_debug(void) const;
		void 		_info(void) const;
		void 		_warning(void) const;
		void 		_error(void) const;
};

typedef	void (Harl::*f_ptr)(void) const;
