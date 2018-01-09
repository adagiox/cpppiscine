/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:30:00 by erintala          #+#    #+#             */
/*   Updated: 2018/01/08 16:04:31 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int main()
{
	int max = 7;
	int size = 0;
	std::string command;
	Contact add[8];
	while (1)
	{
		if (size == 1)
			std::cout << "Phonebook contins " << size << " entry | ENTER COMMAND (ADD, SEARCH, EXIT):" << std::endl;
		else
			std::cout << "Phonebook contins " << size << " entries | ENTER COMMAND (ADD, SEARCH, EXIT):" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			if (size > max)
			{
				std::cout << "Phonebook is full." << std::endl;
				continue;
			}
			add[size].set_first();
			add[size].set_last();
			add[size].set_nick();
			add[size].set_login();
			add[size].set_address();
			add[size].set_email();
			add[size].set_phone();
			add[size].set_birthday();
			add[size].set_meal();
			add[size].set_color();
			add[size].set_secret();
			size++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			for (int i = 0; i < size; i++)
			{
				add[i].show_contact(i);
			}
			std::cout << "Select an index to view: ";
			std::string selection;
			std::getline(std::cin, selection);
			std::cout << std::endl;
			if (selection.compare("0") == 0 && size > 0)
				add[0].show_full_contact();
			else if (selection.compare("1") == 0 && size > 1)
				add[1].show_full_contact();
			else if (selection.compare("2") == 0 && size > 2)
				add[2].show_full_contact();
			else if (selection.compare("3") == 0 && size > 3)
				add[3].show_full_contact();
			else if (selection.compare("4") == 0 && size > 4)
				add[4].show_full_contact();
			else if (selection.compare("5") == 0 && size > 5)
				add[5].show_full_contact();
			else if (selection.compare("6") == 0 && size > 6)
				add[6].show_full_contact();
			else if (selection.compare("7") == 0 && size > 7)
				add[7].show_full_contact();
			else
				std::cout << "Invalid index, aborting....." << std::endl;
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Exiting..." << std::endl;	
			return 0;
		}
		else
			std::cout << "Try again." << std::endl;
	}
}
