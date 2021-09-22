/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:58:11 by ztouzri           #+#    #+#             */
/*   Updated: 2021/08/16 19:01:32 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP
# include <string>
# include <iostream>

class Contact {

public:
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
	void	setFirstName(std::string firstname);
	void	setLastName(std::string lastname);
	void	setNickName(std::string nickname);
	void	setPhoneNumber(std::string phonenumber);
	void	setDarkestSecret(std::string darkestsecret);

private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darkestsecret;

};

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	int		contactnum;
	Contact	contacts[8];
	void	add(Contact);

};

#endif
