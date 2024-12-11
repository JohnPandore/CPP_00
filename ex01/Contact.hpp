/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:48:46 by joncurci          #+#    #+#             */
/*   Updated: 2024/11/19 16:08:34 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class	Contact
{
public:
	Contact();
	~Contact();

	int		ContactIndex;
	
	void	SetFirstName(std::string input);
	void	SetLastName(std::string input);
	void	SetNickName(std::string input);
	void	SetPhoneNumber(std::string input);
	void	SetDarkestSecret(std::string input);

	std::string		getFirstName() const;
	std::string		getlastName() const;
	std::string		getNickName() const;
	std::string		getPhoneNumber() const;
	std::string		getDarkestSecret() const;

private:
	std::string		_FirstName;
	std::string		_LastName;
	std::string		_NickName;
	std::string		_PhoneNumber;
	std::string		_DarkestSecret;
	
};