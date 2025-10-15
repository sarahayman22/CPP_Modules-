/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:35:32 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/11 17:34:21 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("default") {
    std::cout << "PresidentialPardonForm: default constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5),
    target(target) {
         std::cout << "PresidentialPardonForm: constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other),
    target(other.target) {
        std::cout << "PresidentialPardonForm: Copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "PresidentialPardonForm: Copy assignment operator called\n";
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm: destructor\n";
}

void PresidentialPardonForm::executeAction() const {
    std::cout << target << " PresidentialPardonForm: has been pardoned by Zaphod Beeblebrox.";
}