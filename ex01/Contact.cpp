/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:48:41 by joncurci          #+#    #+#             */
/*   Updated: 2024/11/19 14:39:32 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
//#include "PhoneBook.hpp"
//#include "PhoneBook.cpp"

Contact::Contact()
{
	std::cout << "Contact Constructor has been called" << std::endl;
	this->ContactIndex = -1;
}

Contact::~Contact()
{
	std::cout << "Contact Destructor has been called" << std::endl;
}


		
void	Contact::SetFirstName(std::string input)
{
	_FirstName = input;
}



void	Contact::SetLastName(std::string input)
{
	_LastName = input;
}

void	Contact::SetNickName(std::string input)
{
	_NickName = input;
}

void	Contact::SetPhoneNumber(std::string input)
{
	_PhoneNumber = input;
}
void	Contact::SetDarkestSecret(std::string input)
{
	_DarkestSecret = input;
}



std::string		Contact::getFirstName() const
{
	return (_FirstName);
}

std::string		Contact::getlastName() const
{
	return (_LastName);
}

std::string		Contact::getNickName() const
{
	return (_NickName);
}

std::string		Contact::getPhoneNumber() const
{
	return (_PhoneNumber);
}

std::string		Contact::getDarkestSecret() const
{
	return (_DarkestSecret);
}