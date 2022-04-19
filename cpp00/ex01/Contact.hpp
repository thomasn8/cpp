/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:46 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/19 13:09:00 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_hpp
# define Contact_hpp

#include <iostream>

class Contact
{
	public :
		Contact(void);
		~Contact(void);
		bool		isEmpty(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getNumber(void) const;
		std::string	getSecret(void) const;
		void		setEmpty(bool value);
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		void		setNickname(std::string str);
		void		setNumber(std::string str);
		void		setSecret(std::string str);

	private:
		static int	_nbIndex;
		bool		_empty;
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
};

#endif
