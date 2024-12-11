/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:32:47 by joncurci          #+#    #+#             */
/*   Updated: 2024/10/17 14:15:32 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*int	main(int argc, char **argv)
{
	std::string	string;
	
	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				string.append(1, toupper(argv[i][j]));
		}
		std::cout << "string = " << string << std::endl;
	}
	else if (argc == 1)
	{
		string = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << string << std::endl;
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	std::string	string;
	
	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				string += toupper(argv[i][j]);
		}
		std::cout << string << std::endl;
	}
	else if (argc == 1)
	{
		string = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << string << std::endl;
	}
	return (0);
}