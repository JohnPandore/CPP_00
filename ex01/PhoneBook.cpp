/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:15:36 by joncurci          #+#    #+#             */
/*   Updated: 2024/11/22 20:01:02 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
//#include "Contact.hpp"
//#include "Contact.cpp"


PhoneBook::PhoneBook()
{
	this->nextindex = 0;
	std::cout << "PhoneBook Constructor has been Called !" << std::endl;
};

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destructor has been Called !" << std::endl;
};







int ft_atoi(const std::string& str)
{
	int	result = 0;
	int	sign = 1;
	std::string::size_type i = 0;

	while (i < str.size() && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)) 
	{
		i++;
	}
	if (i < str.size() && str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (i < str.size() && str[i] == '+')
	{
		i++;
	}
	while (i < str.size() && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

std::string	CharToString(int number)
{
	std::ostringstream	oss; // Création d'un flux de sortie
    
	oss << number;          // Ecriture de l'entier dans le flux
    return (oss.str());
}

std::string	PrintInfoToFormat(std::string	info)
{
	int	i = 0;
	int	blank = 0;
	int	size = info.size();
	std::string	Sub;
	
	if (size == 10)
		Sub.append(info);
	else if (info.size() < 10)
	{
		blank = 10 - size;
		while (i < blank)
		{
			Sub.append(" ");
			i++;
		}
		Sub.append(info);
	}
	else if (info.size() > 10)
	{
		Sub.append(info,0,9);
		Sub.append(".");
	}
	return (Sub);
}

void	PrintAllContacts(Contact* contacts)
{
	int	index = 0;
	
	system("clear");
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "||     Index| Firstname|  LastName|  NickName||" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "===============================================" << std::endl;

	while (contacts[index].ContactIndex != -1 && index < 8)
	{
		std::cout << "||" << PrintInfoToFormat(CharToString(contacts[index].ContactIndex)) << "|";
		std::cout << PrintInfoToFormat(contacts[index].getFirstName()) << "|";
		std::cout << PrintInfoToFormat(contacts[index].getlastName()) << "|";
		std::cout << PrintInfoToFormat(contacts[index].getNickName()) << "||\n";
	
		std::cout << "===============================================" << std::endl;
		
		index++;
	}
	std::cout << "===============================================" << std::endl;
}

void	PrintChosenContacts(Contact* contacts, int chosen)
{
	int	index;
	std::string	answer;

	while (1)
	{
		index = chosen - 1;
		if (chosen >= 1 && chosen <= 8)
		{
			if (contacts[chosen - 1].ContactIndex == -1)
			{
				std::cout << "This Contact doesn't exist, please enter a valid contact : ";
				std::cin >> answer;
				chosen = ft_atoi(answer);
			}
			else if (contacts[index].ContactIndex != -1 && contacts[index].ContactIndex == chosen)
			{
				system("clear");

				std::cout << "=====================================================================" << std::endl;
				std::cout << "=====================================================================" << std::endl;

				std::cout << "INDEX :  " << CharToString(contacts[index].ContactIndex) << std::endl;
				std::cout << "FirstName : " << contacts[index].getFirstName() << std::endl;
				std::cout << "LastName : " << contacts[index].getlastName() << std::endl;
				std::cout << "NickName : " << contacts[index].getNickName() << std::endl;
				std::cout << "PhoneNumber : " << contacts[index].getPhoneNumber() << std::endl;
				std::cout << "DarkestSecret : " << contacts[index].getDarkestSecret() << std::endl;
				
				std::cout << "=====================================================================" << std::endl;
				std::cout << "=====================================================================" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "This Contact doesn't exist, please enter a valid contact between 1 and 8 : ";
			std::cin >> answer;
			chosen = ft_atoi(answer);
		}
	}
}

/*void	PrintChosenContacts(Contact* contacts, int chosen)
{
	int	index;
	std::string	answer;
	
	//system("clear");
	//std::cout << std::endl;
	//std::cout << "|| Firstname|  LastName|  NickName|Phone Nmbr|	Secret||" << std::endl;

	while (1)
	{
		index = chosen - 1;
		if (chosen >= 1 && chosen <= 8)
		{
			if (contacts[chosen - 1].ContactIndex == -1)
			{
				std::cout << "This Contact doesn't exist, please enter a valid contact : ";
				std::cin >> answer;
				chosen = ft_atoi(answer);
			}
			else if (contacts[index].ContactIndex != -1 && contacts[index].ContactIndex == chosen)
			{
				system("clear");
				std::cout << "=====================================================================" << std::endl;
				std::cout << "||     Index| Firstname|  LastName|  NickName|Phone Nmbr|    Secret||" << std::endl;
				std::cout << "=====================================================================" << std::endl;
				std::cout << "=====================================================================" << std::endl;
		
				std::cout << "||" << PrintInfoToFormat(CharToString(contacts[index].ContactIndex)) << "|";
				std::cout << PrintInfoToFormat(contacts[index].getFirstName()) << "|";
				std::cout << PrintInfoToFormat(contacts[index].getlastName()) << "|";
				std::cout << PrintInfoToFormat(contacts[index].getNickName()) << "|";
				std::cout << PrintInfoToFormat(contacts[index].getPhoneNumber()) << "|";
				std::cout << PrintInfoToFormat(contacts[index].getDarkestSecret()) << "||\n";
				
				std::cout << "=====================================================================" << std::endl;
				std::cout << "=====================================================================" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "This Contact doesn't exist, please enter a valid contact between 1 and 8 : ";
			std::cin >> answer;
			chosen = ft_atoi(answer);
		}
	}
}*/

int	CheckPhoneNumber(std::string command)
{
	int	i = 0;

	while (command[i])
	{
		if (!isdigit(command[i]))
			return (0);
		i++;
	}
	if (command.size() != 10)
		return (0);
	return (1);
}

void	PhoneBook::AddContact()
{
	std::string	command;
	
	//std::cout << "Tu tentes de creer un contact mon reuf ??" << std::endl;
	
	
	this->contacts[nextindex].ContactIndex = nextindex + 1;
	
	std::cout << "Please enter the contact FirstName : ";
	//std::cin >> command;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::getline(std::cin, command);
	this->contacts[nextindex].SetFirstName(command);
	
	std::cout << "Please enter the contact LastName : ";
	//std::cin >> command;
	std::getline(std::cin, command);
	this->contacts[nextindex].SetLastName(command);
	
	std::cout << "Please enter the contact NickName : ";
	//std::cin >> command;
	std::getline(std::cin, command);
	this->contacts[nextindex].SetNickName(command);
	
	std::cout << "Please enter the contact Phone Number : ";
	//std::cin >> command;
	std::getline(std::cin, command);
	while (1)
	{
		if (CheckPhoneNumber(command))
		{
			this->contacts[nextindex].SetPhoneNumber(command);
			break;
		}
		else
		{
			std::cout << "Please enter a valid 10 digits Phone Number : ";
			//std::cin >> command;
			std::getline(std::cin, command);
		}
	}
	
	std::cout << "Please enter the contact Darkest Secret : ";
	//std::cin >> command;
	std::getline(std::cin, command);
	this->contacts[nextindex].SetDarkestSecret(command);
	
	if (this->nextindex < 7)
		this->nextindex++;
	else
		this->nextindex = 0;
	
}

void	PhoneBook::SearchContact()
{
	/*int	index = 0;
	
	//std::cout << "Tu veux quoi mon reuf ? J'ai tout c'qu'y faut Wolah !" << std::endl;
	//? ******** Afficher les contacts du PhoneBook *****
	std::cout << std::endl;
	std::cout << "|| Firstname|  LastName|  NickName|Phone Nmbr|	Secret||" << std::endl;

	while (contacts[index].ContactIndex != -1)
	{
		std::cout << "||  " << contacts[index].ContactIndex << "|";
		std::cout << "  " << contacts[index].getFirstName() << " |";
		std::cout << "  " << contacts[index].getlastName() << " |";
		std::cout << "  " << contacts[index].getNickName() << " ||\n";
		index++;
	}*/
	PrintAllContacts(contacts);
	
	//? ******** Afficher en Details le Contact Choisi *****
	
	std::string	command;
	int			chosen;
	
	std::cout << "Please enter your contact Index : ";
	std::cin >> command;
	chosen = ft_atoi(command);

	//std::cout << "CHOSEN = " << chosen << "COMAND = " << command << std::endl;
	
	while (1)
	{
		if (chosen >= 1 && chosen <= 8)
		{
			PrintChosenContacts(contacts, chosen);
			break;
		}
		else
		{
			std::cout << "Please enter a VALID contact Index : ";
			std::cin >> command;
			chosen = ft_atoi(command);
		}
	}
	
}