/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:46 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/17 21:29:31 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_hpp
# define PhoneBook_hpp

#include "Contact.hpp"

/* 
	Contact datas are called by the PhoneBook methods
	So they need to be scoped in public access 
	But only PhoneBook public methods allows modification in the tab of 8 contacts
*/

class PhoneBook
{
	public :
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search_contact(void) const;

	private :
	Contact	_tab[8];
	int		_get_first_empty(void);
	void	_shift_contacts(void);
	void	_copy_contact(Contact *src, Contact *dst);
	void	_save_data(std::string tmp,  std::string *s, const char *info, char *placeholder);
	void	_save_index(char *placeholder, int index);
	void	_print_contacts(int empty) const;
	int		_ask_index(int empty) const;
	void	_print_contact(int index) const;
};

#endif
