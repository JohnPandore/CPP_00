/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:48:53 by joncurci          #+#    #+#             */
/*   Updated: 2024/11/22 17:10:30 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
//#include <cctype>
//#include <cstdio>
#include <sstream>

class	PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	
	void	AddContact();
	void	SearchContact();

	int		nextindex;
	Contact	contacts[8];

private:
};