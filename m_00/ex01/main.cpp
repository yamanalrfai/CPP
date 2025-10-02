/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:17:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2025/10/01 10:46:30 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    while (std::getline(std::cin, command))
    {
        for (long unsigned int i = 0; i < command.size(); i++)
            command[i] = toupper(command[i]);
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else if (!command.empty())
        {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    }
    return 0;
}