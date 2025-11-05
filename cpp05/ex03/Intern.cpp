/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:27:30 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/11/03 14:24:13 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &other){(void)other;}
Intern &Intern::operator=(const Intern &other){(void)other; return *this;}
Intern::~Intern(){}

static AForm* makeShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
static AForm* makeRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    struct Entry
    {
        const char* name;
        AForm* (*factory)(const std::string &);
    };
    static const Entry table[] ={
        { "shrubbery creation", makeShrubbery },
        { "robotomy request",   makeRobotomy },
        { "presidential pardon",makePresidential }
    };
    const size_t tableSize = sizeof(table) / sizeof(table[0]);
    for (size_t i = 0; i < tableSize; ++i)
    {
        if(formName == table[i].name)
        {
            AForm* form = table[i].factory(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }

    std::cerr << "Intern couldn't create form: unknown form name \"" << formName << "\"" << std::endl;
    return NULL;
}