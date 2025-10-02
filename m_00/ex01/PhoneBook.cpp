/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:38:01 by yaman-alrif       #+#    #+#             */
/*   Updated: 2025/10/01 11:16:20 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "Contact.hpp"
# include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    i = 0;
    total = 0;
}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cout << "Enter first name: ";
    while (std::getline(std::cin, firstName) && firstName.empty())
    {
        std::cout << "Enter first name: ";
    }
    if (firstName.empty())
        exit(1);
    std::cout << "Enter last name: ";
    while (std::getline(std::cin, lastName) && lastName.empty())
    {
        std::cout << "Enter last name: ";
    }
    if (lastName.empty())
        exit(1);
    std::cout << "Enter nickname: ";
    while (std::getline(std::cin, nickname) && nickname.empty())
    {
        std::cout << "Enter nickname: ";
    }
    if (nickname.empty())
        exit(1);
    std::cout << "Enter phone number: ";
    while (1)
    {
        if (std::getline(std::cin, phoneNumber) && phoneNumber.empty())
        {
            std::cout << "Enter phone number: ";
            continue;
        }
        if (phoneNumber.empty())
            exit(1);
        if (phoneNumber.size() != 10)
            std::cout << "Phone number must be 10 digits. Try again." << std::endl;
        else
        {
            bool valid = true;
            for (int i = 0; i < (int)phoneNumber.size(); i++)
            {
                if (!isdigit(phoneNumber[i]))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                break;
            else
            {
                std::cout << "Phone number must contain only digits. Try again." << std::endl;
                phoneNumber.clear();
            }
        }
    }
    std::cout << "Enter darkest secret: ";
    while (std::getline(std::cin, darkestSecret) && darkestSecret.empty())
    {
        std::cout << "Enter darkest secret: ";
    }
    if (darkestSecret.empty())
        exit(1);
    contacts[i] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    this->i++;
    if (this->i == 8)
        this->i = 0;
    total++;
}

void PhoneBook::searchContact()
{
    if (total == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int j = 0; j < total && j < 8; j++)
    {
        contacts[j].printContact(j);
    }
    
    std::string inde;
    std::cout << "Enter index of contact to view details: ";
    std::getline(std::cin, inde);
    
    if (inde.empty())
    {
        std::cout << "No index entered." << std::endl;
        return;
    }
    
    int index = std::atoi(inde.c_str());
    if (index < 0 || index >= total || index >= 8)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}