/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  PhoneBook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/07/21 14:05:22 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>  


PhoneBook::PhoneBook()
{
    count = 0;
    index = 0;

};
std::string PhoneBook::checkEmpty(const std::string &fieldName) const {
    std::string input;
    do {
        std::cout << fieldName << ": ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "This field cannot be empty. Try again.\n";
    } while (input.empty());
    return input;
}

std::string PhoneBook::formatColumn(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}


void PhoneBook::addContact() {
    Contact newContact;
    newContact.setFirstName(checkEmpty("First name"));
    newContact.setLastName(checkEmpty("Last name"));
    newContact.setNickname(checkEmpty("Nickname"));
    newContact.setPhoneNumber(checkEmpty("Phone number"));
    newContact.setDarkestSecret(checkEmpty("Darkest secret"));

    add(newContact);
    std::cout << "Contact saved!" << std::endl;
}

void    PhoneBook::add(const Contact &c)
{
    contacts[index] = c;
    index = (index + 1) % 8;
    if(count < 8)
        count++;
}

void PhoneBook::search() {
    if (count == 0) {
        std::cout << "No contacts here.\n";
        return;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << formatColumn(contacts[i].getFirstName())
                  << "|" << formatColumn(contacts[i].getLastName())
                  << "|" << formatColumn(contacts[i].getNickname()) << "|\n";
    }
    std::cout << "---------------------------------------------\n";

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() == 1 && std::isdigit(input[0])) {
        int idx = input[0] - '0';
        if (idx >= 0 && idx < count) {
            const Contact &c = contacts[idx];
            std::cout << "First Name: " << c.getFirstName() << "\n";
            std::cout << "Last Name: " << c.getLastName() << "\n";
            std::cout << "Nickname: " << c.getNickname() << "\n";
            std::cout << "Phone Number: " << c.getPhoneNumber() << "\n";
            std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
            return;
        }
    }
    std::cout << "Invalid index.\n";
}

