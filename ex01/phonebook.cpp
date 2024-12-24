/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:35:55 by amousaid          #+#    #+#             */
/*   Updated: 2024/12/24 13:36:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int searchContact (Phonebook phonebook)
{
	int i = 0;
	std::string index;
	std::cout << YELLOW"     index|     first name|     last name|     nickname|" RESET<< std::endl;
	while (i < phonebook.contacts_count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(15) << phonebook.contacts[i].first_name << "|";
		std::cout << std::setw(14) << phonebook.contacts[i].last_name << "|";
		std::cout << std::setw(13) << phonebook.contacts[i].nickname << "|";
		std::cout << std::endl;
		i++;
	}
	if (phonebook.contacts_count == 0)
		return (1);
	std::cout << BLUE "Enter the index of the contact: " RESET;
	std::getline(std::cin, index);
	if (std::cin.eof())
		return (0);
	std::stringstream ss(index);
	ss >> i;
	if (i >= 0 && i < phonebook.contacts_count)
	{
		std::cout << MAGENTA"First name: " RESET<< phonebook.contacts[i].first_name << std::endl;
		std::cout << MAGENTA"Last name: " RESET<< phonebook.contacts[i].last_name << std::endl;
		std::cout << MAGENTA"Nickname: " RESET<< phonebook.contacts[i].nickname << std::endl;
		std::cout << MAGENTA"Phone number: " RESET<< phonebook.contacts[i].phone_number << std::endl;
		std::cout << MAGENTA"Darkest secret: " RESET<< phonebook.contacts[i].darkest_secret << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
	std::cin.clear();
	return (1);
}

int checkInputPrintable(std::string input)
{
	int i = 0;
	while (input[i])
	{
		if (!isprint(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int getInfo(Phonebook *phonebook)
{
	std::string input;
	input = "";
	while (input == "" || !checkInputPrintable(input))
	{
		std::cout << BLUE "Enter the first name: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	phonebook->contacts[phonebook->contacts_count].first_name = input;
	input = "";
	while (input == "" || !checkInputPrintable(input))
	{
		std::cout << BLUE "Enter the last name: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	phonebook->contacts[phonebook->contacts_count].last_name = input;
	input = "";
	while (input == "" || !checkInputPrintable(input))
	{
		std::cout << BLUE "Enter the nickname: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	phonebook->contacts[phonebook->contacts_count].nickname = input;
	input = "";
	while (input == "" || !checkInputPrintable(input))
	{
		std::cout << BLUE "Enter the phone number: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	phonebook->contacts[phonebook->contacts_count].phone_number = input;
	input = "";
	while (input == "" || !checkInputPrintable(input))
	{
		std::cout << BLUE "Enter the darkest secret: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
	}
	phonebook->contacts[phonebook->contacts_count].darkest_secret = input;
	phonebook->contacts_count++;
	return (1);
}

int changeFirstContact(Phonebook *phonebook)
{
	int i = 0;
	while (i < 7)
	{
		phonebook->contacts[i] = phonebook->contacts[i + 1];
		i++;
	}
	phonebook->contacts_count--;
	return (getInfo(phonebook));
}

int main()
{
	Phonebook phonebook;
	std::string command;
	phonebook.contacts_count = 0;
	int exit = 1;
	while (1)
	{
		std::cin.clear();
		std::cout << BLUE "Enter a command: " RESET;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << RED "Exiting..." RESET << std::endl;
			return (0);
		}
		if (command == "ADD")
		{
			if (phonebook.contacts_count < 8)
				exit = getInfo(&phonebook);
			else
				exit = changeFirstContact(&phonebook);
		}
		else if (command == "EXIT")
		{
			std::cout << RED "Exiting..." RESET << std::endl;
			return (0);
		}
		else if (command == "SEARCH")
			exit = searchContact(phonebook);
		else
			std::cout << RED "Invalid command" RESET << std::endl;
		if (exit == 0)
		{
			std::cout << RED "Exiting..." RESET << std::endl;
			return (0);
		}
	}
}
