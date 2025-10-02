/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:38:01 by yaman-alrif       #+#    #+#             */
/*   Updated: 2025/10/01 10:25:44 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
#include <stdlib.h>

class PhoneBook
{
    private:
        Contact contacts[8];
        int i;
        int total;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};

