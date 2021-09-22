/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:16:17 by ztouzri           #+#    #+#             */
/*   Updated: 2021/07/05 12:52:37 ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

PhoneBook::PhoneBook(void) : contactnum(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstname);
}

std::string	Contact::getLastName(void)
{
	return (this->_lastname);
}

std::string	Contact::getNickName(void)
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phonenumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestsecret);
}

void	Contact::setFirstName(std::string firstname)
{
	this->_firstname = firstname;
}

void	Contact::setLastName(std::string lastname)
{
	this->_lastname = lastname;
}

void	Contact::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phonenumber)
{
	this->_phonenumber = phonenumber;
}

void	Contact::setDarkestSecret(std::string darkestsecret)
{
	this->_darkestsecret = darkestsecret;
}

void	PhoneBook::add(Contact newcontact)
{
	int		i;
	Contact	tmp;

	if (this->contactnum < 8)
	{
		this->contacts[contactnum] = newcontact;
		this->contactnum++;
	}
	else
	{
		i = 0;
		while (i < 7)
		{
			this->contacts[i] = this->contacts[i + 1];
			i++;
		}
		this->contacts[7] = newcontact;
	}
}
