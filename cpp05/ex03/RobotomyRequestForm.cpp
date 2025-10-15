/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:35:00 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/13 18:48:55 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default")
{
    std::cout<< "RobotomyRequestForm: default constructor called\n";       
}


RobotomyRequestForm::RobotomyRequestForm(const std::string& tgt)
    : AForm("RobotomyRequestForm", 72, 45), target(tgt)
{
    std::cout << "RobotomyRequestForm: constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm: copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "RobotomyRequestForm: copy assignment operator called\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: destructor called\n";
}

void RobotomyRequestForm::executeAction() const
{
    std::cout <<"* DRILLING NOISES * ZZZZZZZZZZZZZZZ...\n";
    
    std::srand(std::time(NULL));
    if(std::rand() % 2)
        std::cout << target << "Has been robotomized successfully!\n";
    else
        std::cout << "Robotomy faild on" << target << "...\n";
}
