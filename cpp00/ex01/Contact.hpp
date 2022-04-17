/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:46 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/17 21:26:41 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_hpp
# define Contact_hpp

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

#endif
