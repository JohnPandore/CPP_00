/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartostr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:58:17 by joncurci          #+#    #+#             */
/*   Updated: 2024/12/04 12:58:23 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

std::string	CharToString(int number)
{
	std::string	str;
	int	i;

	str[0] = number - 48;
	str[1] = '\0';
	return (str);
}

int	main(void)
{
	int	nbr = 4;
	std::string str = CharToString(nbr);

	std::cout << str << std::endl;
	return (0);
}