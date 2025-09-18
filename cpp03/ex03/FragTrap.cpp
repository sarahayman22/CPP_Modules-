/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:21 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 18:06:29 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("FragTrap")  
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called for: " << name << std::endl;
}

FragTrap::FragTrap(const std::string& nm)
    : ClapTrap(nm)           // call base ctor with name
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for: " << name << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& copy)
    : ClapTrap(copy)         // let ClapTrap copy its members
{
    std::cout << "FragTrap copy constructor called for: " << name << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& assign)
{
    if (this != &assign)
    {
        ClapTrap::operator=(assign); 
    }
    std::cout << "FragTrap assignation operator called for: " << name << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for: " << name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        --energyPoints;
        std::cout << "FragTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name << " is out of energy or hit points!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five! ✋😄" << std::endl;
}