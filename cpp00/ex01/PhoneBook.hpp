/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:46 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/19 14:06:11 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_hpp
# define PhoneBook_hpp

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void) const;

	private :
		// PhoneBook
		Contact	_tab[8];
		// Add
		int		_getFirstEmpty(void);
		void	_shiftContacts(void);
		void	_copyContact(Contact *src, Contact *dst);
		void	_askData(std::string *tmp, const char *info);
		// Search
		void	_printIndexes(int empty) const;
		void	_printIndex(std::string str) const;
		int		_askIndex(int empty) const;
		void	_printContact(int index) const;
};

#endif
