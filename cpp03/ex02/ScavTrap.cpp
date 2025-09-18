/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:09:24 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/09/18 15:47:07 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ScavTrap.hpp"
ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap") // call ClapTrap default/name ctor
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called for: " << name << std::endl;
}

// name ctor: call ClapTrap(name)
ScavTrap::ScavTrap(const std::string& nm)
    : ClapTrap(nm)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for: " << name << std::endl;
}

// copy ctor: call base copy ctor
ScavTrap::ScavTrap(const ScavTrap& copy)
    : ClapTrap(copy) // let ClapTrap copy its members
{
    std::cout << "ScavTrap copy constructor called for: " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
    if (this != &assign)
    {
        ClapTrap::operator=(assign); // reuse base assignment if available
    }
    std::cout << "ScavTrap assignment operator called for: " << name << std::endl;
    return *this;
}
// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for: " << name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

