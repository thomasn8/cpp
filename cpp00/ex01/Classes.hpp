/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:46 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/17 13:40:02 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>
# define BLANK '_'

/* 
	Contact datas are called by the PhoneBook methods
	So they need to be scoped in public access 
	But only PhoneBook public methods allows modification in the tab of 8 contacts
*/

class Contact
{
	public :
	Contact(void);
	~Contact(void);
	int			empty;
	int			i;
	std::string	s_index;
	char		index[11];
	std::string	s_fname;
	char		fname[11];
	std::string	s_lname;
	char		lname[11];
	std::string	s_nname;
	char		nname[11];
	std::string	s_number;
	std::string	s_secret;
	void		init_placeholder(char *tab);
};

class PhoneBook
{
	public :
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search_contact(void);

	private :
	Contact	_tab[8];
	int		_get_first_empty(void);
	void	_shift_contacts(void);
	void	_copy_contact(Contact *src, Contact *dst);
	void	_save_data(std::string tmp,  std::string *s, const char *info, char *placeholder);
	void	_save_index(char *placeholder, int index);
	void	_print_contacts(int empty);
	int		_ask_index(int empty);
	void	_print_contact(int index);
};

#endif
