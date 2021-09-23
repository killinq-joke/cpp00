/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:09:32 by ztouzri           #+#    #+#             */
/*   Updated: 2021/09/23 21:58:49by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

std::string	strformat(std::string str)
{
	std::string cpy;
	int	i;

	i = str.size();
	cpy = str.substr(0, 10);
	if (i > 10)
		cpy[9] = '.';
	// std::cout << cpy;
	return (cpy);
}

std::string	readString(std::istream& stream)
{
	std::string	str;

	std::getline(stream, str);
	return (str);
}

int		serviceADD(PhoneBook *phonebook)
{
	Contact		newcontact;

	std::cout << "Enter first name:" << std::endl;
	newcontact.setFirstName(readString(std::cin));
	if (std::cin.eof())
		return (0);
	std::cout << "Enter last name:" << std::endl;
	newcontact.setLastName(readString(std::cin));
	if (std::cin.eof())
		return (0);
	std::cout << "Enter nickname:" << std::endl;
	newcontact.setNickName(readString(std::cin));
	if (std::cin.eof())
		return (0);
	std::cout << "Enter phonenumber:" << std::endl;
	newcontact.setPhoneNumber(readString(std::cin));
	if (std::cin.eof())
		return (0);
	std::cout << "Enter darkest secret:" << std::endl;
	newcontact.setDarkestSecret(readString(std::cin));
	if (std::cin.eof())
		return (0);
	phonebook->add(newcontact);
	return (1);
}

int		serviceSEARCH(PhoneBook *phonebook)
{
	int			i;
	int			index;
	std::string	strindex;

	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "firstname" << "|" << std::setw(10) << "lastname" << "|" << std::setw(10) << "nickname" << std::endl;
	i = 0;
	while (i < phonebook->contactnum)
	{
		std::cout << std::setw(10) << strformat(std::to_string(i + 1));
		std::cout << "|" << std::setw(10) << strformat(phonebook->contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << strformat(phonebook->contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << strformat(phonebook->contacts[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "Which index do you want to search:" << std::endl;
	std::getline(std::cin, strindex);
	if (std::cin.eof())
		return (0);
	index = strindex[0] - '0';
	if (strindex.size() != 1 || !isdigit(strindex[0]) || index < 1 || index > phonebook->contactnum)
		std::cout << "NONE EXISTING INDEX" << std::endl;
	else
	{
		std::cout << "first name: " << phonebook->contacts[index - 1].getFirstName() << std::endl;
		std::cout << "last name: " << phonebook->contacts[index - 1].getLastName() << std::endl;
		std::cout << "nickname: " << phonebook->contacts[index - 1].getNickName() << std::endl;
		std::cout << "phone number: " << phonebook->contacts[index - 1].getPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << phonebook->contacts[index - 1].getDarkestSecret() << std::endl;
	}
	return (1);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (command != "EXIT")
	{
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (1);
		if (command == "ADD")
		{
			if (!serviceADD(&phonebook))
				return (1);
		}
		else if (command == "SEARCH")
			if (!serviceSEARCH(&phonebook))
				return (1);
	}
	return (0);
}
