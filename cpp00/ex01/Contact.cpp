/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:31:15 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/07/31 16:11:05 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string &fn) { 
    firstName = fn;
}
void Contact::setLastName(const std::string &ln) { 
    lastName = ln; 
}
void Contact::setNickname(const std::string &nn) { 
    nickname = nn; 
}
void Contact::setPhoneNumber(const std::string &pn) {
     phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string &ds) {
     darkestSecret = ds; 
}


std::string Contact::getFirstName() const { 
    return firstName; 
}
std::string Contact::getLastName() const {
     return lastName; 
}
std::string Contact::getNickname() const { 
    return nickname; 
}
std::string Contact::getPhoneNumber() const {
     return phoneNumber; 
}
std::string Contact::getDarkestSecret() const {
     return darkestSecret; 
}

bool Contact::isEmpty() const {
    return firstName.empty() || lastName.empty() || 
         nickname.empty()   || phoneNumber.empty() || 
         darkestSecret.empty();
}
