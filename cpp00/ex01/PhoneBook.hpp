/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:18:59 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/07/29 18:56:10 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int count;
    int index;

    std::string checkEmpty(const std::string &fieldName) const;
     std::string formatColumn(const std::string &str) const;

public:
    PhoneBook();
    void add(const Contact &c);
    void addContact();  
    void search();
};

#endif
