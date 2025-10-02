/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:12:11 by yaman-alrif       #+#    #+#             */
/*   Updated: 2025/10/01 09:35:50 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
         std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    public:
        Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret);
        Contact();
        void printContact(int j);

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};