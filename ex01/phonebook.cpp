/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:35:55 by amousaid          #+#    #+#             */
/*   Updated: 2024/12/21 10:40:01 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void searchContact (Phonebook phonebook)
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
	std::cout << BLUE"Enter the index of the contact: "BLUE;
	std::cin >> index;
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
}

void getInfo(Phonebook *phonebook)
{
	std::cout << GREEN"Enter the first name: "RESET;
	std::cin >> phonebook->contacts[phonebook->contacts_count].first_name;
	std::cout << GREEN"Enter the last name: "RESET;
	std::cin >> phonebook->contacts[phonebook->contacts_count].last_name;
	std::cout << GREEN"Enter the nickname: "RESET;
	std::cin >> phonebook->contacts[phonebook->contacts_count].nickname;
	std::cout << GREEN"Enter the phone number: "RESET;;
	std::cin >> phonebook->contacts[phonebook->contacts_count].phone_number;
	std::cout << GREEN"Enter the darkest secret: "RESET;;
	std::cin >> phonebook->contacts[phonebook->contacts_count].darkest_secret;
	phonebook->contacts_count++;
}

void changeFirstContact(Phonebook *phonebook)
{
	int i = 0;
	while (i < 7)
	{
		phonebook->contacts[i] = phonebook->contacts[i + 1];
		i++;
	}
	phonebook->contacts_count--;
	getInfo(phonebook);
}

int main()
{
	Phonebook phonebook;
	std::string command;
	phonebook.contacts_count = 0;
	while (1)
	{
		std::cout << BLUE"Enter a command: "RESET;
		std::cin >> command;
		if (command == "ADD")
		{
			if (phonebook.contacts_count < 8)
				getInfo(&phonebook);
			else
				changeFirstContact(&phonebook);
		}
		else if (command == "EXIT")
		{
			std::cout << RED"Exiting..."RESET << std::endl;
			return (0);
		}
		else if (command == "SEARCH")
			searchContact(phonebook);
		else
			std::cout << RED"Invalid command"RESET << std::endl;
	}
}
